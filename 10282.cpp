#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
#define MAX INT_MAX

int T;
int n, d, c;
int a, b, s;
int num;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        //dijkstra
        num = 1;
        //input
        cin >> n >> d >> c;
        
        //dijkstra
        vector<pair<int, int>> arr[n + 1];
        priority_queue<pair<int, int>> pq; //max_heap
        vector<int> dist(n + 1);
        for(int i = 0; i < n+1; i++){
            dist[i] = MAX;
        }

        for (int i = 0; i < d; i++)
        {
            cin >> a >> b >> s;
            arr[b].push_back({a, s}); // b감염 -> s초 후  a감염
        }

        dist[c] = 0;     //출발
        pq.push({0, c}); //cost, start
        while (!pq.empty())
        {
            int cost = -pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            for (int i = 0; i < arr[cur].size(); i++)
            {
                int next = arr[cur][i].first;
                int weight = arr[cur][i].second;
                if (dist[next] > dist[cur] + weight)
                {
                    if (dist[next] == MAX)
                    {
                        num++;
                    }
                    dist[next] = dist[cur] + weight;
                    pq.push({-dist[next], next});
                }
            }
        }

        int ans = -1;
        for(int i = 1; i <= n; i++){
            if(dist[i] != MAX){
                ans = max(ans, dist[i]);
            }
        }
        cout << num << ' ' << ans << '\n';
    }
    return 0;
}
