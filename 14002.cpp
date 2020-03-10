#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int A[1001] = { 0 };
int ans[1001] = { 0 };
int D[1001] = { 0 };
vector<int> v;


void find(int ans_idx){
    if(ans_idx == -1){
        return;
    }
    v.push_back(A[ans_idx]);
    find(ans[ans_idx]);
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    for(int i = 0; i < N; i++){
        ans[i] = -1;
        D[i] = 1;
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]){
                if(D[i] < D[j] + 1){
                    D[i] = D[j] + 1;
                    ans[i] = j;
                }
            }
        }
    }
    int MAX = 0;
    for(int i = 0; i < N; i++){
        MAX = max(MAX, D[i]);
    }

    cout << MAX << '\n';

    for(int i = 0; i < N; i++){
        if(MAX == D[i]){
            v.push_back(A[i]);
            find(ans[i]);
            break;
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    return 0;
}
