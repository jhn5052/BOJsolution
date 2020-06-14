#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string str;
vector<string> v;

bool compare(string a, string b){
    if(a == b) return true;
    string t1 = a + b;
    string t2 = b + a;
    return t1 < t2;
}

int main(){
    cin >> N;
    bool flag = false;
    for(int i = 0; i < N; i++){
        cin >> str;
        if(str != "0") flag = true;
        v.push_back(str);
    }
    if(flag == false){
        cout << '0' << '\n';
        return 0;
    }
    sort(v.begin(), v.end(), compare);
    for(int i = N-1; i >= 0; i--){
        cout << v[i];
    }
    return 0;
}
