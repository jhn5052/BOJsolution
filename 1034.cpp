#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M, K;
string arr[51];
int maxValue = 0;
int zeroCnt = 0;
int cnt = 0;

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> K;

    for(int i = 0; i < N; i++){
        zeroCnt = 0;
        for(int j = 0; j < M; j++){
            if (arr[i][j] == '0')
            {
                zeroCnt++;
            }
        }
        int cnt = 0;
        if(zeroCnt <= K && (zeroCnt % 2 == K % 2)){
            for (int curRow = 0; curRow < N; curRow++)
            {
                if (arr[i] == arr[curRow]){
                    cnt++;
                }
            }
        }
        maxValue = max(maxValue, cnt);
    }
    cout << maxValue;
    return 0;
}