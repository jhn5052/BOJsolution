#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int N;
long long ans = -1e9;
vector<int> num;
vector<char> op;
bool visit[30] = { false };

//계산하는 함수
int Calc(int a, int b, char c){
    if(c == '+') return a+b;
    else if(c == '-') return a-b;
    else  return a*b;
}

int Final_calc(){
    vector<int> num_tmp;
    vector<char> op_tmp;
    //괄호 먼저 계산 끝
    for(int i = 0; i < num.size(); i++){
        if(visit[i] == true){
            int result = Calc(num[i], num[i+1], op[i]);
            num_tmp.push_back(result);
            i += 1;
        }
        else{
            num_tmp.push_back(num[i]);
        }

        if(i < op.size()){
            op_tmp.push_back(op[i]);
        }
    }
    /*
    cout << "new op_size : " << op_tmp.size() << '\n';
    cout << "new num_size: " << num_tmp.size() << '\n';

    for(int i = 0; i < num_tmp.size(); i++){
        cout << num_tmp[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < op_tmp.size(); i++){
        cout << op_tmp[i] << ' ';
    }
    cout << '\n';
    */
    long long result = num_tmp[0];
    for(int i = 1; i < num_tmp.size(); i++){
        result = Calc(result, num_tmp[i], op_tmp[i-1]);
    }
    return result;
}

void DFS(int cur, int end){
    if(cur >= end){
        int result = Final_calc();
        if(ans < result){
            ans = result;
        }
        return;
    }

    visit[cur] = true;
    DFS(cur+2, end);
    visit[cur] = false;
    DFS(cur+1, end);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string s;
    cin >> s;
    
    //num, op 나눠서 벡터 저장
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
            op.push_back(s[i]);
        }
        else{
            num.push_back(s[i]-'0');
        }
    }
    DFS(0, op.size());
    cout << ans << '\n';
    return 0;
}

