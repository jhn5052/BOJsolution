
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int R, C;
char map[51][51];
int dist[51][51];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<pair<int, int> > q;
queue<pair<int, int> > m;
int a, b, c, d;
bool flag = false;

bool isRange(int x, int y){
    if(x < 0 || x >= R || y < 0 || y >= C){
        return false;
    }
    return true;
}

int Find(){
    while(!m.empty()){
        //1. 물 번지는 곳부터 먼저 표시
        int tmp_size = q.size();
        for(int k = 0; k < tmp_size; k++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
 
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(isRange(nx, ny)){
                    if(map[nx][ny] == '.'){
                        map[nx][ny] = '*';
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }

        //2. 고슴도치가 물 번질 곳 제외하고 갈 수 있는 곳 움직이기
        tmp_size = m.size();
        for(int k = 0; k < tmp_size; k++){
            int x = m.front().first;
            int y = m.front().second;
            m.pop();
            if(x == c && y == d){
                flag = true;
                return 0;
            }

            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(isRange(nx, ny)){
                    if(map[nx][ny] == '*' || map[nx][ny] == 'X'){
                        continue;
                    }
                    if(dist[nx][ny] == -1){
                        dist[nx][ny] = dist[x][y] + 1;
                        m.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    return 0;
}




int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(map[i][j] == 'S'){
                a = i;
                b = j;
            }
            if(map[i][j] == 'D'){
                c = i;
                d = j;
            }
            if(map[i][j] == '*'){
                q.push(make_pair(i, j));
            }
            dist[i][j] = -1;
        }
    }
    m.push(make_pair(a, b));
    dist[a][b] = 0;
    Find();

    if(flag == false){
        cout << "KAKTUS" << '\n';
    }
    else{
        cout << dist[c][d] << '\n';
    }
    return 0;
}
