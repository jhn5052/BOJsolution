#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int map[21][21];

struct info{
    int y;
    int x;
    int d;
};

vector<info> v;
int sr, sc;
int s_size = 2; //아기상어 크기
int ans = 0; //리턴값
int cnt=0;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool compare(info a, info b){
    if(a.d == b.d){
        if(a.y == b.y) return a.x > b.x;
        else return a.y > b.y;
    }
    else return a.d > b.d;
}

void BFS(int r, int c){
    queue<info> q;
    bool visit[21][21] = { false, };
    visit[r][c] = true;
    q.push({r, c, 0});
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        int cur_d = q.front().d;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];
            if(ny < 0 || nx < 0 || ny >= N || nx >= N){
                continue;
            }
            if(!visit[ny][nx] && map[ny][nx] <= s_size){
                if(map[ny][nx] > 0 && map[ny][nx] < s_size){
                    v.push_back({ny, nx, cur_d+1});
                }
                visit[ny][nx] = true;
                q.push({ny, nx, cur_d+1});
            }
        }
    }
}

void Solve(int r, int c){
    BFS(r, c);
    if(v.size() == 0){
        return;
    }
    sort(v.begin(), v.end(), compare);
    int y, x, d;
    
    y = v[v.size()-1].y;
    x = v[v.size()-1].x;
    d = v[v.size()-1].d;
    cnt++;
    if(s_size==cnt){
      cnt=0;
      s_size++;
    }
    map[y][x] = 0;
    ans += d;
    v.clear();
    Solve(y, x);
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                sr = i;
                sc = j;
                map[i][j] = 0;
            }
        }
    }
    Solve(sr, sc);
    cout << ans << '\n';
    return 0;
}
