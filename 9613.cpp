//GCD합
#include<iostream>
#include<cstdio>
using namespace std;
int v[101];

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}


int main(){
    int t, n;
    long long ans = 0;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        cin >> n;
        ans = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                ans += gcd(v[i], v[j]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
