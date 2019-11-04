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
        if(flag[i] == false){
            if(num >= 1 && v[num-1] > i+1){
                continue;
            }
            flag[i] = true;
            v.push_back(i+1);
            recur(num+1);
            v.pop_back();
            flag[i] = false;
        }
    }
}


int main(){
    cin >> N >> M;
    recur(0);
    return 0;
}
