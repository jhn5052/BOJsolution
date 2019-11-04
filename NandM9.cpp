#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;
vector<int> v1, v2;
int visit[10001] { 0 };

void recur(int num){
    if(num == M){
        for(int i = 0; i < M; i++){
            cout << v2[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < v1.size(); i++){
        if(visit[v1[i]] > 0){
            v2.push_back(v1[i]);
            visit[v1[i]] -= 1;
            recur(num+1);
            visit[v1[i]] += 1;
            v2.pop_back();
        }
    }
}

int main(){
    cin >> N >> M;
    int tmp;
    bool check = false;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        for(int j = 0; j < i; j++){
            if(v1[j] == tmp){
                check = true;
            }
        }
        if(check == false){
            v1.push_back(tmp);
            visit[tmp]++;
        }
        else{
            check = false;
            visit[tmp]++;
        }
    }
    sort(v1.begin(), v1.end());
    for(int i = 0; i < v1.size(); i++){
        v2.push_back(v1[i]);
        visit[v1[i]] -= 1;
        recur(1);
        v2.pop_back();
        visit[v1[i]] += 1;
    }
    return 0;
}
