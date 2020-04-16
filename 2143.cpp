#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long T, n, m;
long long cnt = 0;
long long ans = 0;
vector<long long> A;
vector<long long> B;
map<long long, long long> part_sum;

int main(){
    cin >> T;
    cin >> n;
    int tmp;
    for(long long i = 0; i < n; i++){
        cin >> tmp;
        A.push_back(tmp);
    }
    cin >> m;
    for(long long i = 0; i < m; i++){
        cin >> tmp;
        B.push_back(tmp);
    }
    
    for(long long i = 0; i < n; i++){
        ans = 0;
        for(long long j = i; j < n; j++){
            ans += A[j];
            if(abs(ans) <= 1000000000){
                part_sum[ans] += 1;
            }
        }   
    }

    for(long long i = 0; i < m; i++){
        ans = T;
        for(long long j = i; j < m; j++){
            ans -= B[j];
            if(abs(ans) <= 1000000000){
                cnt += part_sum[ans];
            }
            else{
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
