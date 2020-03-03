//연산자 끼워놓기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> op(4,0);
vector<int> A(101, 0);
long long MAX = -987654321;
long long MIN = 987654321;

int DFS(int cnt, long long tmp){
    if(cnt == N){
        MAX = max(tmp, MAX);
        MIN = min(tmp, MIN);
        return 0;
    }
    if(op[0] > 0){
        op[0]--;
        DFS(cnt + 1, tmp + A[cnt]);
        op[0]++;
    }
    if(op[1] > 0){
        op[1]--;
        DFS(cnt + 1, tmp - A[cnt]);
        op[1]++;
    }
    if(op[2] > 0){
        op[2]--;
        DFS(cnt + 1, tmp * A[cnt]);
        op[2]++;
    }
    if(op[3] > 0){
        op[3]--;
        DFS(cnt + 1, tmp / A[cnt]);
        op[3]++;
    }
    return 0;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }
    DFS(1, A[0]);
    cout << MAX << '\n' << MIN;
    return 0;
}
