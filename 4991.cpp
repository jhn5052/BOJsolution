#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e5
int w, h;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char map[21][21];
int dist[21][21][21];
bool visit[21][21][21];
int s, e;
vector<pair<pair<int, int>, int> > v;

bool isRange(int y, int x){
    if(y >= 0 && x >= 0 && y < h && x < w){
        return true;
    }
    return false;
}

void BFS(int y, int x, int idx){
    queue<pair<int, int> > q;
    visit[y][x][idx] = true;
    dist[y][x][idx] = 0;
    q.push(make_pair(y, x));

    while(!q.empty()){
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = cur_y + dir[i][0];
            int nx = cur_x + dir[i][1];
            if(isRange(ny, nx) && map[ny][nx] != 'x' && !visit[ny][nx][idx]){
                visit[ny][nx][idx] = true;
                q.push(make_pair(ny, nx));
                dist[ny][nx][idx] = dist[cur_y][cur_x][idx] + 1;
            }
        }
    }
}

int main(){
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }

        memset(map, 0, sizeof(map));
        memset(visit, false, sizeof(visit));
        memset(dist, INF, sizeof(dist));
        v.clear();
        int cnt = 1;
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> map[i][j];
                if(map[i][j] == 'o'){
                    s = i;
                    e = j;
                }
                else if(map[i][j] == '*'){
                    v.push_back(make_pair(make_pair(i, j), cnt));
                    cnt++;
                }
            }
        }

        if(v.size() == 0){
            cout << 0 << '\n';
            continue;
        }
        BFS(s, e, 0);
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            int y = v[i].first.first;
            int x = v[i].first.second;
            int idx = v[i].second;
            BFS(y, x, idx);
        }
        
        int result = INF;
        do{
            int tmp = dist[v[0].first.first][v[0].first.second][0]; //청소기 시작점
            for(int i = 0; i < v.size()-1; i++){
                tmp += dist[v[i+1].first.first][v[i+1].first.second][v[i].second];
            }
            result = min(tmp, result);
        }while(next_permutation(v.begin(), v.end()));

        if(result >= 1000 || result < 0){
            cout << -1 << '\n';
        }
        else{
            cout << result << '\n';
        }

    }
    return 0;
}
