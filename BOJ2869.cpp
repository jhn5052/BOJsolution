//2869달팽이
#include <iostream>
using namespace std;

long long A, B, V;
int day = 0;
int main(){
    cin >> A >> B >> V;
    day = ((V-B)/(A-B));
    if((double)(V-B)/(A-B)>(int)(V-B)/(A-B)){
        day += 1;
    }
    cout << day;
    return 0;
}