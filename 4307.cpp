#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T;
int L, N;
vector<int> v;
int main(){
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        cin >> L >> N; //막대 길이, 개미 수 
        int tmp;
        for(int i = 0; i < N; i++){
             cin >> tmp;
             v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        int a = 0, b = 0;
        int Min = 0, Max = 0; 
        for(int i = 0; i < N; i++){
            a = min(v[i], L-v[i]);
            b = max(v[i], L-v[i]);
            Min = max(Min, a);
            Max = max(Max,b);
        }
        cout << Min << ' ' << Max << '\n';
        while (v.size() > 0){
            v.pop_back();
        }
    }

    return 0;
}
