#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct info{
    int row;
    int col;
    int size;
}info;
int T, N;
int map[101][101];
bool visited[101][101];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int sy, sx;

bool cmp(info a, info b){
    if(a.size < b.size) return true;
    else if(a.size == b.size){
        if(a.row < b.row) return true;
    }
    return false;
}

void BFS(int y, int x){
    queue<pair<int, int> > q;
    visited[y][x] = true;
    q.push(make_pair(y,x));
    int cur_y, cur_x;
    sy = 0;
    sx = 0;
    while(!q.empty()){
        cur_y = q.front().first;
        cur_x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = cur_y + dir[i][0];
            int nx = cur_x + dir[i][1];
            if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if(visited[ny][nx] || map[ny][nx] == 0) continue;
            visited[ny][nx] = true;
            q.push(make_pair(ny, nx));
        }
    }
    sy = cur_y - y + 1;
    sx = cur_x - x + 1;
}

int main(){
    cin >> T;
    //freopen("input.txt", "r", stdin);
    for(int tc = 1; tc <= T; tc++){
        cin >> N;
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        vector<info> v;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> map[i][j];
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && map[i][j] > 0){
                    BFS(i, j);
                    v.push_back(info{sy, sx, sy*sx});
                }
            }
        }

        sort(v.begin(), v.end(), cmp);
        cout << "#" << tc << ' ' << v.size() << ' ';
        for(int i = 0; i < v.size(); i++){
            cout << v[i].row << ' ' << v[i].col << ' ';
        }
        cout << '\n';
    }
    return 0;
}