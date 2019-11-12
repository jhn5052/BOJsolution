#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int N;

int main(){
    cin >> N;
    int tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    
    int ans = v[0];
    for(int i = 1; i < N; i++){
        tmp = 0;
        for(int j = 0; j <= i; j++){
            tmp += v[j];
        }
        ans += tmp;
    }
    cout << ans;
    return 0;
}
