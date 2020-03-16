#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool visit[10] = { false };
char A[10];
int K;
vector<int> num;
vector<string> ans;

int Find(int cnt){
    if(cnt == K+1){
        string tmp = "";
        for(int i = 0; i < num.size(); i++){
            tmp += to_string(num[i]);
        }
        ans.push_back(tmp);
        return 0;
    }
    for(int i = 0; i < 10; i++){
        if(visit[i] == false){
            if(cnt == 0){
                visit[i] = true;
                num.push_back(i);
                Find(cnt+1);
                visit[i] = false;
                num.pop_back();
            }
            else{
                if(A[cnt-1] == '>'){
                    if(num[cnt-1] > i){
                        visit[i] = true;
                        num.push_back(i);
                        Find(cnt+1);
                        visit[i] = false;
                        num.pop_back();
                    }
                }
                else if(A[cnt-1] == '<'){
                    if(num[cnt-1] < i){
                        visit[i] = true;
                        num.push_back(i);
                        Find(cnt+1);
                        visit[i] = false;
                        num.pop_back();
                    }
                }   
            }
        }
    }
    return 0;
}

int main(){
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> A[i];
    }
    
    Find(0);
    cout << ans[ans.size()-1] << '\n' << ans[0] << '\n';
    return 0;
}
