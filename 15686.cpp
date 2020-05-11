#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int N, M;
int ans = 987654321;
int map[51][51];
bool visit[101] = { false };
vector<pair<int, int> > v;
vector<pair<int, int> > h;

void DFS(int start, int end, int cnt){
    if(cnt == M){
        int result = 0;
        //집 크기
        for(int i = 0; i < h.size(); i++){
            int tmp = 987654321;
            int ry = h[i].first;
            int rx = h[i].second;
            for(int j = 0; j < v.size(); j++){
              if(visit[j] == true){
                int cy = v[j].first;
                int cx = v[j].second;
                tmp = min(tmp, abs(ry-cy)+abs(rx-cx));
              }
            }
            result += tmp;
        }
        ans = min(result, ans);
        return;
    }

    for (int i = start+1 ; i < end; i++)
    {
      if(!visit[i]){
        visit[i] = true;
        DFS(i, end, cnt+1);
        visit[i] = false;
      }
    }
}


int main(){
    cin >> N >> M;
    int a;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> a;
            if (a == 2){
                //치킨집 뽑기
                v.push_back({i, j});
            }
            else if (a == 1){
              h.push_back({i, j});
            }
        }
    }
    //조합으로 뽑아서 map에 표시하기
    for(int i = 0; i < v.size(); i++){
        visit[i] = true;
        DFS(i, v.size(), 1);
        visit[i] = false;
    }
    cout << ans << '\n';
    return 0;
}
