#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int N, M;

int main(){
    cin >> N >> M;
    vector<long long int> v;
    long long int L = 0;
    long long int R = 0;
    long long int tmp;
    long long int ans = 0;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    R = v[N-1];

    while(L <= R){
        long long mid = (L + R) / 2;
        long long sum = 0;
        for(int i = 0; i < N; i++){
            if(v[i] > mid){
                sum += (v[i] - mid);
            }
        }

        if(sum >= M){
            L = mid + 1;
            if(ans < mid){
                ans = mid;
            }
        }
        else{
            R = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
