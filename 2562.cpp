#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[10];
    int MAX = 0, MIN = 100;
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
        MAX = max(MAX, arr[i]);
    }
    cout << MAX << '\n';
    for(int i = 0; i < 9; i++){
        if(arr[i] == MAX){
            cout << i+1 << '\n';
        }
    }
    return 0;
}
