#include<iostream>
#include<algorithm>
using namespace std;

int N;
int map[21][21] = { 0 };
bool visit[21] = { false };
int result = 987654321;
int score[2] = { 0 }; //0 : start, 1 : link

int Find(int Depth, int idx){
    if(idx == N){
        return 0;
    }
    if(Depth == N/2){
        score[0] = 0;
        score[1] = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(visit[i] == true && visit[j] == true){
                    score[0] += map[i][j];
                }
                else if(visit[i] == false && visit[j] == false){
                    score[1] += map[i][j];
                }
            }
        }
        int a = max(score[0], score[1]);
        int b = min(score[0], score[1]);
        result = min(result, a - b);
        return 0;
    }
    visit[idx] = true;
    Find(Depth + 1, idx + 1);
    visit[idx] = false;
    Find(Depth, idx + 1);
    return 0;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    Find(0, 0); //depth, id
    cout << result << '\n';
    return 0;
}

