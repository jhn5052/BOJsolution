#include <iostream>
#include <limits.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int N;
ll result = LONG_MAX;
vector<ll> v;
vector<ll> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            //구해야하는 값
            int find = -(v[i] + v[j]);
            int idx = lower_bound(v.begin()+j+1, v.end(), find) - v.begin();
            for(int k = idx-2; k <= idx+2; k++){
                if(k > j && k < N){
                    ll tmp = v[i] + v[j] + v[k];
                    if(abs(tmp) < result){
                        result = abs(tmp);
                        while(!ans.empty()){
                            ans.pop_back();
                        }
                        ans.push_back(v[i]);
                        ans.push_back(v[j]);
                        ans.push_back(v[k]);
                    }
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(auto x : ans){
        cout << x << ' ';
    }
    return 0;
}
