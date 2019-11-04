#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;
vector<int> v1,v2;


void recur(int num){
    if(num == M){
        for(int i = 0; i < M; i++){
            cout << v2[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < v1.size(); i++){
        if(v2[num-1] <= v1[i]){
            v2.push_back(v1[i]);
            recur(num+1);
            v2.pop_back();
        }
    }

}

int main(){
    cin >> N >> M;
    int tmp;
    bool check = false;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        for(int j = 0; j < i; j++){
            if(v1[j] == tmp){
                check = true;
            }
        }
        if(check == false){
            v1.push_back(tmp);
        }
        else{
            check = false;
        }
    }
    sort(v1.begin(), v1.end());
    for(int i = 0; i < v1.size(); i++){
        v2.push_back(v1[i]);
        recur(1);
        v2.pop_back();
    }
    return 0;
}
