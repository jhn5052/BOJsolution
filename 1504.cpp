#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int N, E;
int a, b, c;
int v1, v2;
typedef pair<long long, int> PP;
vector<PP> v[200001];

vector<int> dijkstra(int start){
    priority_queue<PP> pq; //first : weight, second : node;
    vector<int> dist(N+1, INT_MAX);
    dist[start] = 0;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            long long next_dist = cost + v[cur][i].second;
            if(dist[next] > next_dist){
                dist[next] = next_dist;
                pq.push(make_pair(-next_dist, next));
            }
        }
    }
    return dist;
}

int main(){
    cin >> N >> E;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;
    vector<int> result;
    long long t1 = 0, t2 = 0;
    result = dijkstra(1);
    t1 += result[v1];
    t2 += result[v2];
    result = dijkstra(v1);
    t1 += result[v2];
    t2 += result[N];
    result = dijkstra(v2);
    t1 += result[N];
    t2 += result[v1];
    long long ans = min(t1, t2);
    if(ans >= INT_MAX){
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}
