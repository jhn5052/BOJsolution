#include<iostream>
#include<vector>
using namespace std;

int N;
long long K;
vector<int> v1;

int main(){
    cin >> N >> K;
    int tmp;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        v1.push_back(tmp);
    }
    while(true){
        for(int i = N-1; i >= 0; i--){
            if(K >= v1[i]){
                K -= v1[i];
                cnt += 1;
                break;
            }
        }
        if(K == 0){
            break;
        }
    }
    cout << cnt;
    return 0;
}
