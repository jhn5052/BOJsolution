#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,M;
bool flag[9];
vector<int> v1;
vector<int> v2;

void recur(int num){
    if(num == M){
        for(int i = 0; i < M; i++){
            cout << v2[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        if(flag[i] == false){
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
    int tmp_num;
    for(int i = 0; i < N; i++){
        cin >> tmp_num;
        v1.push_back(tmp_num);
    }
    sort(v1.begin(), v1.end());
    for(int i = 0; i < N; i++){
        flag[i] = true;
        v2.push_back(v1[i]);
        recur(1);
        v2.pop_back();
        flag[i] = false;
    }
    return 0;
}
