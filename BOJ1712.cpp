//1712 손익분기점
#include<iostream>
using namespace std;

long long A,B,C;
int com = 0;
int main(){
    cin >> A >> B >> C; //고정, 가변, 가격
    if(B >= C){//손익분기점이 존재하지 않으면 -1
        cout << -1 << '\n';
    }
    else{
        com = A/(C-B);
        cout << com+1 << '\n';
    }

    return 0;
}