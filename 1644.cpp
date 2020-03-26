#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define MAX 4000001

int N;
int cnt = 0;
int idx = 0;
bool prime[MAX] = { false };
int v[MAX];

void Prime(){
    for(int i = 2; i <= sqrt(N); i++){
        if(!prime[i]){
            for(int j = i+i; j <= N; j += i){
                prime[j] = true;
            }
        }
    }
    for(int i = 2; i <= N; i++){
        if(prime[i] == false){
            v[idx++] = i;
        }
    }
}

int Find(){
    int L = 0, R = 0;
    int sum = 0;
 
    while(R <= idx){
        if(sum < N){
            sum += v[R];
            R++;
            continue;
        }

        else if(sum == N){
            cnt++;
        }
        sum -= v[L];
        L++;
    }
    return cnt;
}



int main(){
    cin >> N;
    Prime();
    int ans = Find();
    cout << ans << '\n';
    return 0;
}
