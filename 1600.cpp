#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

typedef struct info{
    int horse;
    int y, x;
    int cnt;
}Info;

int K, W, H;
int map[201][201];
bool visited[201][201][32];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int horseDir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool isRange(int r, int c){
    if(r >= 0 && c >= 0 && r < H && c < W){
        return true;
    }
    return false;
}


int BFS(){
    queue<Info> q;
    visited[0][0][0] = true;
    q.push({0, 0, 0, 0}); //말처럼움직일수있는 경우, (y,x), cnt
    
    while(!q.empty()){
        int horseMv = q.front().horse;
        int curY = q.front().y;
        int curX = q.front().x;
        int move = q.front().cnt;
        q.pop();

        if(curY == H-1 && curX == W-1){
            return move;
        }

        //말처럼 움직이는 경우
        if (horseMv < K)
        {
            for (int i = 0; i < 8; i++)
            {
                int nextY = curY + horseDir[i][0];
                int nextX = curX + horseDir[i][1];
                if (!visited[nextY][nextX][horseMv+1] && isRange(nextY, nextX) && map[nextY][nextX] == 0){
                    visited[nextY][nextX][horseMv + 1] = true;
                    q.push({horseMv + 1, nextY, nextX, move + 1});
                }
            }
        }

        //일반적으로 움직이는 경우
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];
            if (!visited[nextY][nextX][horseMv] && isRange(nextY, nextX) && map[nextY][nextX] == 0)
            {
                visited[nextY][nextX][horseMv] = true;
                q.push({horseMv, nextY, nextX, move + 1});
            }
        }
    }
    return -1;
}

int main(){
    //input
    cin >> K >> W >> H;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> map[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    cout << BFS() << '\n';
    return 0;
}