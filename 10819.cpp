//10819 차이를 최대로
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> v(9, 0);
vector<bool> visit(9, false);
vector<int> num;
int ans = 0;

int DFS(){
    if(num.size() == N){
        int tmp = 0;
        for(int i = 0; i < N-1; i++){
            if(num[i] > num[i-1]){
                tmp += num[i] - num[i+1];
            }
            else{
                tmp += num[i+1] - num[i];
            }
        }
        ans = max(tmp, ans);
        return 0;
    }
    for(int i = 0; i < N; i++){
        if(visit[i] == false){
            visit[i] = true;
            num.push_back(v[i]);
            DFS();
            visit[i] = false;
            num.pop_back();
        }
    }
    return 0;
}


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    DFS();
    cout << ans;
    return 0;
}
