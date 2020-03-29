#include<iostream>
#include<queue>
using namespace std;

int N, K;
queue<pair<int, int> > q;
bool visit[100001] = { false };
int cnt = 0;
int times = 987654321;

bool isRange(int a){
    if(a >= 0 && a <= 100000){
        return true;
    }
    return false;
}

void BFS(){
    q.push(make_pair(N, 0));
    visit[N] = true;
    while(!q.empty()){
        int x = q.front().first;
        int t = q.front().second;
        q.pop();
        visit[x] = true;
        //if x == K
        if(x == K){ 
            if(times > t){
                cnt = 1;
                times = t;
            }
            else if(times == t){
                cnt += 1;
            }
        }

        //*2
        if(isRange(x*2) && !visit[x*2]){
            q.push(make_pair(x*2, t+1));
        }
        if(isRange(x+1) && !visit[x+1]){
            q.push(make_pair(x+1, t+1));
        }
        if(isRange(x-1) && !visit[x-1]){
            q.push(make_pair(x-1, t+1));
        }
    }
    return;
}

int main(){
    cin >> N >> K;
    BFS();
    cout << times << '\n' << cnt << '\n';
    return 0;
}
           
