#include<iostream>
#include<vector>
using namespace std;

int N;
char S[11][11];
vector<int> v;

bool chk(int idx){
    int sum = 0;
    for(int i = idx; i >= 0; i--){
        sum += v[i];
        if(S[i][idx] == '+' && sum <= 0) {
            return false;
        }
        if(S[i][idx] == '-' && sum >= 0){
            return false;
        }
        if(S[i][idx] == '0' && sum != 0){
            return false;
        }
    }
    return true;
}


int Find(int cnt){
    if(cnt == N){
        for(int i = 0; i < N; i++){
            cout << v[i] << ' ';
        }
        exit(0);
    }
    
    int sum = 0;
    for(int j = -10; j < 11; j++){
        v.push_back(j);
        if(chk(cnt)){
            Find(cnt + 1);
        }
        v.pop_back();
    }
    return 0;
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            cin >> S[i][j];
        }
    }
    Find(0);

    return 0;
}
