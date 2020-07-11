//2610
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;
#define MAX 200

int N, M, K = 0;
int Team[102] = { 0 };
bool graph[102][102];
int dist[101][101];
vector<int> answer;

int FloydWarshall(int teamNum, int start)
{
 
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (dist[j][k] > dist[j][i] + dist[i][k])
                {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
    int idx = start;
    int ans = MAX;
    for(int i = 1; i <= N; i++){
        if(Team[i] != teamNum)  continue;
        int tmp = 0;
        for(int j = 1; j <= N; j++){
            if(Team[j] != teamNum)  continue;
            if (dist[i][j] != MAX)
            {
                tmp = max(tmp, dist[i][j]);
            }
        }
        if (ans > tmp)
        {
            ans = tmp;
            idx = i;
        }
    }
    return idx;
}

//팀개수
int BFS(int start, int teamNum){
    queue<int> q;
    Team[start] = teamNum;
    q.push(start);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 1; i <= N; i++){
            //그래프에 연결되어있으면서, 팀으로 아직 등록되지 않은 경우
            if(graph[cur][i] && Team[i] == 0){
                Team[i] = teamNum;
                q.push(i);
            }
        }
    }
    int ans = FloydWarshall(teamNum, start);
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //input
    cin >> N >> M;
    int a, b;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j){
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = MAX;
            }
        }
    }

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    //팀짜기 - BFS
    for(int i = 1; i <= N; i++){
        if(Team[i] == 0){
            K++;
            int result = BFS(i, K);
            answer.push_back(result);
        }       
    }

    //output
    cout << K << '\n';
    sort(answer.begin(), answer.end());
    for(auto x : answer){
        cout << x << '\n';
    }
    return 0;
}

