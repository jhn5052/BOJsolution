#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int N;
int arr[1001];
map<string, int> in;

int Solve(){
    int cnt = 0;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(arr[i] > arr[j]){
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        string car_name;
        cin >> car_name;
        in[car_name] = i;
    }
    for(int i = 0; i < N; i++){
        string car_name;
        cin >> car_name;
        arr[i] = in[car_name];
    }
    int ans = Solve();
    cout << ans << '\n';
    return 0;
}