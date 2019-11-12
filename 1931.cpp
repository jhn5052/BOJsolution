#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<pair <int, int> > v;
int cnt = 0;

bool Comparison(const pair<int,int> &x, const pair<int,int> &y){
    if(x.second == y.second){
        return x.first < y.first;
    }
    else{
        return x.second < y.second;
    }
}


int main(){
    cin >> N; 
    int s, e;
    for(int i = 0; i < N; i++){
        cin >> s >> e;
        v.push_back(make_pair(s,e));
    }
    sort(v.begin(), v.end(), Comparison);
    int end = 0;//끝나는 시간 저장
    for(int i = 0; i < N; i++){ //처음부터 시간 비교
        if(end <= v[i].first){
            cnt += 1;
            end = v[i].second;
        }
    }
    cout << cnt;
    return 0;
}
