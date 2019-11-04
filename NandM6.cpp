#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;
vector<int> v1;
vector<int> v2;
bool flag[9];

void recur(int num){
    if(num == M){
        for(int i = 0; i < M; i++){
            cout << v2[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        if(!flag[i]){
            if(v2[num-1] >= v1[i]){
                continue;
            }
            flag[i] = true;
            v2.push_back(v1[i]);
            recur(num+1);
            v2.pop_back();
            flag[i] = false;
        }
    }
}


int main(){
    cin >> N >> M;
    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        v1.push_back(tmp);
    }
    sort(v1.begin(), v1.end());
    for(int i = 0; i < N; i++){
        flag[i] = true;
        v2.push_back(v1[i]);
        recur(1);
        v2.pop_back();
        flag[i] = false;
    }
}
