#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int N;
int L, R, M;
long long arr[5001];
int result[3];
long long ans = INT_MAX;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //input
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    
    for(auto x : arr){
        cout << x << '\n';
    }
    //init
    L = 0;
    R = N-1;
    M = 1;
    while(L < R){
        long long tmp = arr[L] + arr[R] + arr[M];
        if(tmp == 0){
            break;
        }
        else if(tmp < 0){
            if(ans > tmp){
                result[0] = arr[L];
                result[1] = arr[M];
                result[2] = arr[R];
            }

            M++;
        }
        else if(tmp > 0){
            if(ans > tmp){
                result[0] = arr[L];
                result[1] = arr[M];
                result[2] = arr[R];
            }
            M--;
        } 

        if(M == L){
            R--;
        }
        else if(M == R){
            L++;
        }
    }

    cout << result[0] << ' ' << result[1] << ' ' << result[2] << '\n';
    return 0;
}

