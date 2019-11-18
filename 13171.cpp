#include <iostream>
#include <bitset>
using namespace std;
#define MOD 1000000007
long long int A;
long long int X;

int main(){
    cin >> A;
    cin >> X;
    long long int ans = 1;
    A = A % MOD;
    bitset<64> b(1);
    bitset<64> xt(X);
    for(int i = 0; i < 64; i++){
        if((xt & b) == b){
            ans *= A % MOD;
            ans %= MOD;
        }
        A = (A * A) % MOD;
        b = b << 1;
    }
    ans %= MOD;
    cout << ans << '\n';
    return 0;
}

