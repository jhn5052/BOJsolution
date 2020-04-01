#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
int A, B;
bool visit[10001] = { false };

int main(){
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> A >> B;
        
        memset(visit, false, sizeof(visit));
        queue<pair<int, string> > q;

        //BFS
        q.push(make_pair(A, ""));
        while(!q.empty()){
            int cur = q.front().first;
            string step = q.front().second;
            q.pop();

            //A -> B로 변환 완료
            if(cur == B){
                cout << step << '\n';
                break;
            }
            
            //D
            int result = (cur * 2) % 10000;
            if(visit[result] == false){
                q.push(make_pair(result, step + 'D'));
                visit[result] = true;
            }
            //S
            if(cur == 0){
                result = 9999;
            }
            else{
              result = cur - 1;
            }
            if(visit[result] == false){
                q.push(make_pair(result, step + 'S'));
                visit[result] = true;
            }
            //L
            result = (cur % 1000) * 10 + (cur / 1000);
            if(visit[result] == false){
                q.push(make_pair(result, step + 'L'));
                visit[result] = true;
            }
            //R
            result = (cur / 10) + ((cur % 10) * 1000);
            if(visit[result] == false){
                q.push(make_pair(result, step + 'R'));
                visit[result] = true;
            }   
        }
    }
    return 0;
}

