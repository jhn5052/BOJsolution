#include <iostream>
using namespace std;

int N;
long long num;
long long ans = 0;
int main(){
    cin >> N >> num;
    if(N == 1){
        ans = num * 8;
    }
    else if(N == 2){
        ans = 1 + (num/2)*8 + (num%2)*6;
    }
    else if(N == 3){
        ans = 2 + (num/2)*8 + (num%2)*4;
    }
    else if(N == 4){
        ans = 3 + (num/2)*8 + (num%2)*2;
    }
    else{
        ans = 4 + (num*8);
    }
    cout << ans << '\n';
    return 0;
}
