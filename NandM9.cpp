#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> v1, v2;
bool flag[10001];
int arr[10001] = { 0 };

void recur(int num){
    if(num == M){
        for(int i = 0; i < M; i++){
            cout << v2[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < 10001; i++){
        if(!flag[i] && arr[i] > 0){
            flag[i] = true;
            v2.push_back(i);
            recur(num+1);
            v2.pop_back();
            flag[i] = false;
        }

    }
}
            


int main(){
    cin >> N >> M;
    int tmp;
    
    for(int i = 0; i < N; i++){
        cin >> tmp;
        arr[tmp] += 1;
    }
    tmp = 0;
    for(int i = 0; i < 10001; i++){
        if(arr[i] > 0){   
            flag[i] = true;
            v2.push_back(i);
            recur(1);
            v2.pop_back();
            flag[i] = false;
        }
    }
    return 0;

}
