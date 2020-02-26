#include <iostream>
#include <vector>
using namespace std;

int main(){
    int E = 1, S = 1, M = 1;
    int ans = 1;
    vector<int> y(3);
    for(int i = 0; i < 3; i++){
        cin >> y[i];
    }
    while(!((y[0] == E) && (y[1] == S) && (y[2] == M))){
        E++;
        S++;
        M++;
        if(E == 16){
            E = 1;
        }
        if(S == 29){
            S = 1;
        }
        if(M == 20){
            M = 1;
        }
        ans += 1;
    }
    cout << ans;
    return 0;
}
