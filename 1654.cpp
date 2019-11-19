#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int K, N;
int main(){
    cin >> K >> N;
    long long sum = 0;
    long long L = 0;
    long long R = (long long)pow(2, 31) - 1;
    long long M = 0;
    vector<int> v;
    int tmp;
    for(int i = 0; i < K; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
   
    long long ans = 0;
    while(R >= L){
        M = (R + L) / 2;
        sum = 0;
        
        for(int i = 0; i < K; i++){
            sum += v[i] / M;
        }
        
        if(sum >= N){ //N개 넘거나 같을 때 최댓값
            L = M + 1;
            ans = ans < M ? M : ans;
        }
        else{
            R = M - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
