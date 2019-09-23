//4153 직각삼각형
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c;
    while(true){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0){
            break;
        }
        int total = a+b+c;
        int one = max(a,max(b,c));
        int two = min(a,max(b,c));
        int thr = total - one - two;
        if((one*one) == (two*two) + (thr*thr)){
            cout << "right" << '\n';
        }
        else{
            cout << "wrong" << '\n';
        }
    }
    return 0;
}