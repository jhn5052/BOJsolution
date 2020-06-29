#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct info{
    int s;
    int e;
    long long w;
}info;

int V, E;
int parent[10002];
vector<info> Edge;
long long sum = 0;

bool Compare(info a, info b){
    return a.w < b. w;
}

//union-find
int Find(int v){
    if(parent[v] == v)  return v;
    else    return Find(parent[v]);
}

void Union(int v, int u, long long w){
    int x = Find(v);
    int y = Find(u);
    if(x != y){
        sum += w;
        parent[x] = y;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //input  
    int a, b;
    long long c;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        Edge.push_back(info{a, b, c});
    }
    //for MST -> Sorting
    sort(Edge.begin(), Edge.end(), Compare);

    //union-find parent init
    for(int i = 1; i <= V; i++){
        parent[i] = i;
    }

    for(int i = 0; i < E; i++){
        int v1 = Edge[i].s;
        int v2 = Edge[i].e;
        long long weight = Edge[i].w;
        Union(v1, v2, weight);
    }
    cout << sum << '\n';
    return 0;
}



