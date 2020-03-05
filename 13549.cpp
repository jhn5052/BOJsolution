//13549 숨바꼭질3
#include<iostream>
#include<queue>
using namespace std;

int N, K;
int visit[100001] = { false };
queue<pair<int, int> > q;

int BFS(int cur, int cnt){
    q.push(make_pair(cur, cnt));
    visit[cur] = true;

    while(!q.empty()){
        int x = q.front().first;
        int t_cnt = q.front().second;
        q.pop();
        if(x == K){
            cout << t_cnt << '\n';
            return 0;
        }

        int dir[3] = {x*2, x-1, x+1};
        for(int i = 0; i < 3; i++){
            if(dir[i] >= 0 && dir[i] <= 100000){
                if(!visit[dir[i]]){
                    if(i == 0){
                        visit[dir[i]] = true;
                        q.push(make_pair(dir[i], t_cnt));
                    }
                    else{
                        visit[dir[i]] = true;
                        q.push(make_pair(dir[i], t_cnt + 1));
                    }
                }
            }
        }
    }
    return 0;
}

int main(){
    cin >> N >> K;
    BFS(N, 0);
    return 0;
}
