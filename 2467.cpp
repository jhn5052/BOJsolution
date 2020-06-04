//2467 용액
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int N;
int L, R;
int arr[100001];
int ans = INT_MAX;
vector<int> v(2);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    L = 0;
    R = N-1;
    while(L < R){
        int x = arr[L];
        int y = arr[R];
        if(ans > abs(x + y)){
            ans = abs(x + y);
            v[0] = arr[L];
            v[1] = arr[R];
        }
        if(x+y < 0) L++;
        else    R--;
    }
    sort(v.begin(), v.end());
    cout << v[0] << ' ' << v[1]<< '\n';
    return 0;
}
