#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector <int> g;
vector <int> e;
int ans = 0;

int main(){
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        g.push_back(x);
        e.push_back(y);
    }
    sort(g.begin(), g.end());
    sort(e.begin(), e.end());

    while(N > 0){
        if(N >= 6){
            if(g[0] < e[0] * 6){
                ans += g[0];
                N -= 6;
            }
            else{
                ans += e[0] * N;
                N -= N;
            }
        }
        else{
            if(g[0] > e[0]*N){
                ans += e[0] * N;
                N -= N;
            }else{
                ans += g[0];
                N -= 6;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
