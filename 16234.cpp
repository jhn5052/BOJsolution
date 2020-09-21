#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 102

int N, L, R;
int arr[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //인접한 곳 이동
vector<pair<int, int>> connCountry[51*51];                  //연결된 국가
int cnt = 0;

void BFS(int r, int c, int num){
    queue<pair<int, int> > q;
    connCountry[num].push_back({r, c});
    q.push({r, c});
    visited[r][c] = true;

    //현재 점에서 인접한 곳 찾기
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int next_y = y + dir[i][0];
            int next_x = x + dir[i][1];

            //범위를 벗어나지 않으면서
            if(next_y >= 0 && next_x >= 0 && next_y < N && next_x < N){

                //방문하지 않은 곳 중에
                if(!visited[next_y][next_x]){
                    int diff = abs(arr[y][x] - arr[next_y][next_x]);
                    //차이가 존재하는 곳
                    if(diff >= L && diff <= R){
                        visited[next_y][next_x] = true;
                        q.push({next_y, next_x});
                        connCountry[num].push_back({next_y, next_x});
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    while(true){
        int a = 0;

        //전체 방문 후 연합 국가 찾기
        for (int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j]){
                    //방문하지 않았던 곳에서 인접한 국가 찾기
                    BFS(i, j, a);
                    a++;
                }
            }
        }
        
        //연합 국가 인구 이동
        bool flag = false;
        for(int i = 0; i <= a; i++){
            //인접한 국가 크기가 1인 경우는 자기자신밖에 없음
            if(connCountry[i].size() > 1){
                flag = true;

                //연합을 이루고 있는 칸의 개수
                int num = connCountry[i].size();
                
                //연합의 인구수
                int total = 0;
                for(int j = 0; j < connCountry[i].size(); j++){
                    int r = connCountry[i][j].first;
                    int c = connCountry[i][j].second;
                    total += arr[r][c];
                }

                int final_num = total/num;
                for(int j = 0; j < connCountry[i].size(); j++){
                    int r = connCountry[i][j].first;
                    int c = connCountry[i][j].second;
                    arr[r][c] = final_num;
                }
            }
        }
        
        //사이즈가 1인 경우만 있는 경우는 인접한국가가 모두 없다는 것
        if(!flag){
            break;
        }

        //초기화
        for(int i = 0; i <= 51*51; i++){
            connCountry[i].clear();
        }
        memset(visited, false, sizeof(visited));
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}