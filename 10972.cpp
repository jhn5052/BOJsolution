#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    int num = N - 1;
    while(num > 0 && (v[num-1] >= v[num])){
        num--;
    }
    if(num == 0){
        cout << "-1";
        return 0;
    }

    int num2 = N-1;
    while(v[num-1] >= v[num2]){
        num2--;
    }

    swap(v[num-1], v[num2]);
    num2 = N-1;
    while(num < num2){
        swap(v[num++], v[num2--]);
    }

    for(int i = 0; i < N; i++){
        cout << v[i] << " ";
    }
    return 0;
}
