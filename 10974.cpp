#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> arr;
vector<bool> visit(9, false); 

int DFS(){
    if(arr.size() == N){
        for(int i = 0; i < N; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    for(int i = 1; i <= N; i++){
        if(visit[i] == false){
            visit[i] = true;
            arr.push_back(i);
            DFS();
            arr.pop_back();
            visit[i] = false;
        }
    }
    return 0;
}


int main(){
    cin >> N;
    DFS();
    return 0;
}   
