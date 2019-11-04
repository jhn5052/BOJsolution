#include<iostream>
#include<vector>
using namespace std;

int N,M;
vector<int> v;

void recur(int num){
    if(num == M){
        for(int i = 0; i < M; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        v.push_back(i+1);
        recur(num+1);
        v.pop_back();
    }
}


int main(){
    cin >> N >> M;
    recur(0);
    return 0;
}
