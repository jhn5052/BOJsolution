#include<iostream>
#include<vector>
using namespace std;

int N,M;
vector<int> v;
bool flag[9];

void recur(int num){
    if(num == M){
        for(int i = 0; i < M; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        if(flag[i] == false) {
            flag[i] = true;
            v.push_back(i+1); //because start with 0
            recur(num+1);
            v.pop_back();
            flag[i] = false;//back tracking
        }
    }
}


int main(){
    cin >> N >> M;
    recur(0);
    return 0;
}
