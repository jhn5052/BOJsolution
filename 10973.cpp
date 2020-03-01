//10973이전순열
#include<iostream>
#include<algorithm>
using namespace std;
int arr[10001] = { 0 };

int main(){
    int N;
    int p1 = N-1, p2 = N-1;
    bool flag = false;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    for(int i = N-1; i > 0; i--){
        if(arr[i] < arr[i-1]){
            p1 = i;
            flag = true;
            break;
        }
    }
    if(flag == false){
        cout << -1;
        return 0;
    }
    
    for(int i = N-1; i >= p1; i--){
        if(arr[p1-1] > arr[i]){
            p2 = i;
            break;
        }
    }
    swap(arr[p1-1], arr[p2]);
    p2 = N-1;
    while(p1 < p2){
        swap(arr[p1], arr[p2]);
        p1++;
        p2--;
    }
    for(int i = 0; i < N; i++){
        cout << arr[i] << ' ';
    }
    return 0;
}
