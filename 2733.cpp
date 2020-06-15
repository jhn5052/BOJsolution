//2733 Brainf*ck
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int T, p = 0;
int Byte[32768] = { 0 };
string op = "";
string ans = "";
map<int, int> m;

int Solve(int idx){
    if(op[idx] == '>'){
        if(p == 32767)  p = 0;
        else    p++;
    }
    else if(op[idx] == '<'){
        if(p == 0)  p = 32767;
        else    p--;
    }
    else if(op[idx] == '+'){
        if(Byte[p] == 255)  Byte[p] = 0;
        else    Byte[p]++;
    }
    else if (op[idx] == '-')
    {
        if (Byte[p] == 0) Byte[p] = 255;
        else    Byte[p]--;
    }
    else if(op[idx] == '.'){
        ans += Byte[p];
    }
    else if(op[idx] == '['){
        if(Byte[p] == 0)    return m[idx] + 1;
        else    return idx + 1;
        
    }
    else if(op[idx] == ']'){
        if(Byte[p] != 0)    return m[idx];
        else    return idx+1;
    }
    return idx + 1;
}

int main(){
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        memset(Byte, 0, sizeof(Byte));
        m.clear();
        p = 0;
        int idx = 0;
        string str;
        op = "";
        ans = "";
        stack<int> st;
        cout << "PROGRAM #" << tc << ":\n";
        while(1){
            getline(cin, str);
            if(str == "end"){
                break;
            }
            for(int i = 0; i < str.size(); i++){
                if(str[i] == '%')   break;
                else{
                    op += str[i];
                }
            }
        }
        for(int i = 0; i < op.size(); i++){
            if(op[i] == '['){
                st.push(i);
            }
            else if(op[i] == ']'){
                if(!st.empty()){
                    int t = st.top();
                    m.insert(make_pair(t, i));
                    m.insert(make_pair(i, t));
                    st.pop();
                }
            }
        }
        if(st.empty()){
            for(int i = 0; i < op.size(); i = Solve(i));
        }  
        else{
            ans += "COMPILE ERROR";
        }
        cout << ans << '\n';
    }
    return 0;
}
