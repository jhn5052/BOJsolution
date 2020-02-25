#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main(){
    int N;
    vector<int> B(50, 0);
    pair<int, int> P[50];
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> P[i].first;
        P[i].second = i;
    }

    sort(P, P + N);
    for(int i = 0; i < N; i++){
        B[P[i].second] = i;
    }
    for(int i = 0; i < N; i++){
        cout << B[i] << " ";
    }
    return 0;
}



