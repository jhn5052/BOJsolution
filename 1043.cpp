#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 51

int N, M, K;
bool trueMan[MAX] = { false };
bool visited[MAX] = { false };
vector<int> arr[MAX];
int answer = 0;

void Solve(int partyNum){
    visited[partyNum] = true;
    for(int i = 0; i < arr[partyNum].size(); i++){
        trueMan[arr[partyNum][i]] = true;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            //파티 방문을 하지 않았는데, 진실을 아는 사람이 있을 때
            if (!visited[i] && trueMan[arr[i][j]])
            {
                Solve(i);
            }
        }
    }
}


int main(){
    //input
    cin >> N >> M;

    int tmp;
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> tmp;
        trueMan[tmp] = true;       
    }

    for(int i = 0; i < M; i++){
        cin >> tmp;
        int participate;
        for(int j = 0; j < tmp; j++){
            cin >> participate;
            arr[i].push_back(participate);
        }
    }

    //true일때만 들어가기
    for(int i = 0; i < M; i++){
        for(int j = 0; j < arr[i].size(); j++){
            //파티 방문을 하지 않았는데, 진실을 아는 사람이 있을 때
            if(!visited[i] && trueMan[arr[i][j]]){
                Solve(i);
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        if(visited[i] == false){
            answer++;
        }
    }
    cout << answer << '\n';
    return 0;
}