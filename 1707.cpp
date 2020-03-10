#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int K, V, E;
int visit[20001] = { 0 };
vector<vector<int> > G;

int BFS(){
    queue<int> q;
    for(int i = 1; i <= V; i++){
        if(visit[i] != 0){
            continue;
        }
        q.push(i);
        visit[i] = 1;
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            for(int j = 0; j < G[tmp].size(); j++){
                if(visit[G[tmp][j]] == 0){
                    q.push(G[tmp][j]);
                    if(visit[tmp] == 1){
                        visit[G[tmp][j]] = -1;
                    }
                    else{
                        visit[G[tmp][j]] = 1;
                    }
                }else if(visit[G[tmp][j]] + visit[tmp] != 0){
                    return -1;
                }
            }
        }
    }
    return 0;
}

int main(){
    cin >> K;
    while (K--){
        cin >> V >> E;
        int a, b;
        G = vector<vector<int> > (V+1);
        memset(visit, 0, sizeof(visit));
        for(int i = 0; i < E; i++){
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int ans = BFS();
        if(ans == -1){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
        }
    }
    return 0;
}
