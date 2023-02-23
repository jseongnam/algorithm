#include <iostream>
using namespace std;
int N;
int M;
int MAP[50][50];
struct Node{
    int y;
    int x;
};
Node start_1, end_1;
int visit_cost[50][50];
void dfs(int y, int x){
    
}
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0; j<M;j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 2)
            {
                start_1.y = i;
                start_1.x = j;
            }
            else if(MAP[i][j] == 3){
                end_1.y = i;
                end_1.x = j;
            }
        }
    }
    dfs(i,j);
}