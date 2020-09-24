#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 300002
//맨위의 피자가 얼마나 깊이 들어가 있는지
int D, N;
int oven[MAX] = { 0 };
int radius[MAX] = { 0 };
int main(){
    //input
    cin >> D >> N;
    for(int i = 0; i < D; i++){
        cin >> oven[i];
        if(i > 0){
            oven[i] = min(oven[i], oven[i-1]);
        }
    }
    for(int i = 0; i < N; i++){
        cin >> radius[i];
    }

    int idx = 0;
    for(int i = D-1; i >= 0; i--){
        //오븐이 반죽보다 더 작을때 넘김
        if(oven[i] < radius[idx])   continue;
        else{
            //도우 인덱스가 갯수를 넘어가면 다 넣은거라 return
            idx++;
            if(idx >= N){
                cout << i+1 << '\n';
                return 0;
            }
        }

    }

    cout << 0 << '\n';
    return 0;
}