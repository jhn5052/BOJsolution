#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int R,C,N;
char map[101][101];
bool visit[101][101];
int num[101];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void LeftToRight(int n){
    int x = 1;
    while(map[R-n+1][x] != 'x' && x <= C){
        x++;
    }
    if(map[R-n+1][x] == 'x'){
        map[R-n+1][x] = '.';
    }
    return;
}

void RightToLeft(int n){
    int x = C;
    while(map[R-n+1][x] != 'x' && x >= 1){
        x--;
    }
    if(map[R-n+1][x] == 'x'){
        map[R-n+1][x] = '.';
    }
    return;
}

void Drop(){
    int d = R;
    for(int j = 1; j <= C; j++){
        for(int i = R; i >= 1; i--){
            if(map[i][j] == 'x' && visit[i][j] == false){
                int col = R - i;
                for(int k = i + 1; k <= R; k++){
                    if(visit[k][j] == true){
                        col = k - i - 1;
                        break;
                    }
                }
                if(d > col){
                    d = col;
                }
            }
        }
    }
    for(int j = 1; j <= C; j++){
        for(int i = R; i >= 1; i--){
            if(i + d <=  R && d != 0){
                if(visit[i][j] == false && map[i][j] == 'x'){
                    map[i+d][j] = map[i][j];
                    map[i][j] = '.';
                }
            }
        }
    }

}
void move(){
    for(int i = 1; i <= C; i++){
        if(map[R][i] == 'x'){
            queue<pair<int, int> > cluster;
            cluster.push(make_pair(R, i));
            visit[R][i] = true;
            while(!cluster.empty()){
                int x = cluster.front().first;
                int y = cluster.front().second;
                cluster.pop();
                for(int t = 0; t < 4; t++){
                    int nx = x + dir[t][0];
                    int ny = y + dir[t][1];
                    if(nx >= 1 && ny >= 1 && nx <= R && nx <= C){
                        if(visit[nx][ny] == false && map[nx][ny] == 'x'){
                            visit[nx][ny] = true;
                            cluster.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }
    Drop();
}

int main(){
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> map[i][j];
        }
    }
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> num[i];
    }
    int t = 1;
    while(t <= N){
        if(t % 2 == 1){
            //홀수 left -> right
            LeftToRight(num[t]);
        }
        else{
            RightToLeft(num[t]);
        }
        
        memset(visit, false, sizeof(visit));
        move();
        t++;
    }
    
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}
