#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int cnt = 0;
int visit[101][101];
int map[101][101];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isRange(int y, int x){
    if(y >= 0 && x >= 0 && y < N && x < M){
        return true;
    }
    return false;
}

void BFS(){
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(isRange(ny, nx)){
                //치즈가 있으면 방문 횟수 증가
                if(map[ny][nx] == 1){
                    visit[ny][nx] += 1;
                }
                //치즈가 없는 곳이면 큐에 담아서 다시 탐색
                else if(map[ny][nx] == 0 && visit[ny][nx] == 0){
                    visit[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}


int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    
    while(1){
        bool flag = false;

        //map에 남아있는 치즈가 있는지 확인
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(visit[i][j] >= 2 && map[i][j] == 1){
                    //2번이상 방문하고, 치즈가 있는 곳일 때
                    map[i][j] = 0;
                }
                if(map[i][j] == 1){
                    flag = true;
                }
            }
        }

        //남아있는 치즈가 있을때 돌기 -> 시간 1 증가
        if(flag == true){
            memset(visit, 0, sizeof(visit));
            BFS();
            cnt += 1;
        }
        
        //남아있는 치즈가 없을때 출력하고 종료
        else{
            cout << cnt << '\n';
            break;
        }

    }
    return 0;
}
