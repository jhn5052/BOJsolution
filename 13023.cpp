#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
vector<int> graph[2001];// a - b friend
bool check[2001] = { false };
bool flag = false;

int Find(int a, int cnt){
    check[a] = true;
    if(cnt == 5){
        flag = true;
        return 0;
    }

    for(int i = 0; i < graph[a].size(); i++){
        if(check[graph[a][i]] == false){
            Find(graph[a][i], cnt+1);
            if(flag == true){
                return 0;
            }
        }
    }
    check[a] = false;
    return 0;
}


int main(){
    cin >> N >> M;
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 0; i < N; i++){
        memset(check, false, sizeof(check));
        Find(i, 1);
        if(flag == true){
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}

