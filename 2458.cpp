#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
bool visit[501];
int up[501];//현재보다 큰거
int down[501];//현재보다 작은거

int main(){
	int N, M;
	int a, b;
	int from, to;
	int tmp, cnt = 0;
	cin >> N >> M;
	vector <int> v[501];
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		v[b].push_back(a);
	}
	for(int i = 1; i <= N; i++){
		memset(visit,false,sizeof(visit));
		queue <int> st;
		from = i;
		st.push(i);
		while(!st.empty()){
			to = st.front();
			st.pop();
			for(int j = 0; j < v[to].size(); j++){
				tmp = v[to][j];//주변 탐색
				if(visit[tmp] == false){
					visit[tmp] = true;
					st.push(tmp);
					up[tmp] += 1;//자신이 tmp보다 크고
					down[from] += 1;//tmp는 자신보다 작다
				}
			}
		}
	}
	for(int i = 1; i <= N; i++){
		int result = up[i] + down[i] + 1;
		if(result == N){
			cnt += 1;
		}
	}
	cout << cnt;
	return 0;
}



