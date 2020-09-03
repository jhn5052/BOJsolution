#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

string S;
stack<char> str;
int interval[51];

int Solve(int start, int end){
    int str_size = 0;
    for(int i = start; i < end; i++){
        if(S[i] == '('){
            //반복 횟수
            int repeat = S[i-1] - '0';

            //반복 후 총 문자열
            str_size += repeat * Solve(i + 1, interval[i]) - 1;
            //괄호 쌍의 위치
            i = interval[i];
        }else{
            str_size++;
        }
    }
    return str_size;
}

int main()
{
    cin >> S;

    for (int i = 0; i < S.size(); i++)
    {
        if(S[i] == '('){
            str.push(i);
        }
        else if(S[i] == ')'){
            interval[str.top()] = i;
            str.pop();
        }
    }
    int answer = Solve(0, S.size());
    cout << answer << '\n';
    return 0;
}