#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;//가로,세로 길이
int M;//터널의 개수
struct Node {
	vector<int>y;
	vector<int>x;
	vector<int>cost;
};
struct Node2 {
	int y;
	int x;
};
int ydir[] = { 1,-1,0,0 };
int xdir[] = { 0,0,1,-1 };
int map[30][30];//원래 맵
void bfs(int tc) {
	Node telepote[30][30];//터널

	for (int i = 0; i < M; i++) {
		int Ay, Ax, By, Bx, cost;
		cin >> Ay >> Ax >> By >> Bx >> cost;
		telepote[Ay-1][Ax-1].y.push_back(By-1);
        telepote[Ay-1][Ax-1].x.push_back(Bx-1);
		telepote[Ay-1][Ax-1].cost.push_back(cost);
        telepote[By-1][Bx-1].y.push_back(Ay-1);
        telepote[By-1][Bx-1].x.push_back(Ax-1);
		telepote[By-1][Bx-1].cost.push_back(cost);
	}
	int total_cost[30][30];//이 맵을 가는데 드는 비용
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			total_cost[i][j] = -1;
		}
	}
	queue<Node2>q;
	q.push({ 0,0 });
	total_cost[0][0] = 0;
	while (!q.empty())
	{
		int length = q.size();
		for (int i = 0; i < length; i++) {
			Node2 now = q.front();
			q.pop();
			for (int t = 0; t < 4; t++) {
				int ny = now.y + ydir[t];
				int nx = now.x + xdir[t];
				int cost_;
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
				if (map[now.y][now.x] > map[ny][nx])
					cost_ = 0;
				else if (map[now.y][now.x] < map[ny][nx])
					cost_ = (map[ny][nx] - map[now.y][now.x]) * 2;
				else
					cost_ = 1;
				if (total_cost[ny][nx] == -1) {
					total_cost[ny][nx] = total_cost[now.y][now.x] + cost_;
					q.push({ ny,nx });
				}
				else if (total_cost[now.y][now.x] + cost_ < total_cost[ny][nx]) {//새로운 값이 기존값보다 작을 때
					total_cost[ny][nx] = total_cost[now.y][now.x] + cost_;
					q.push({ ny,nx });
				}
			}
            for(int t =0; t<telepote[now.y][now.x].y.size();t++){
                int ny = telepote[now.y][now.x].y[t];
                int nx = telepote[now.y][now.x].x[t];
                int cost_ = telepote[now.y][now.x].cost[t];
               if (total_cost[ny][nx] == -1) {
					total_cost[ny][nx] = total_cost[now.y][now.x] + cost_;
					q.push({ ny,nx });
				}
				else if (total_cost[now.y][now.x] + cost_ < total_cost[ny][nx]) {//새로운 값이 기존값보다 작을 때
					total_cost[ny][nx] = total_cost[now.y][now.x] + cost_;
					q.push({ ny,nx });
				}
            }
		}
	}
	cout << '#' << tc << ' ' << total_cost[N - 1][N - 1] << endl;

}
int main() {
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		bfs(tc);
	}
}