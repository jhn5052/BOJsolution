#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int visit[10002] = { 0 }; 
vector<pair<int,int> > v[10002];
int n;
int ans = 0;//지름 길이
int end_p = 0;//끝점

void dfs(int p, int l){
	if(visit[p]){
		return;//이미 들렸으면 나가기
	}
	visit[p] = 1;
	if(ans < l){
		ans = l;
		end_p = p;
	}
	for(int i = 0; i < v[p].size(); i++){//트리 근접정점 탐색
		dfs(v[p][i].first,l+v[p][i].second);
	}
}


int main(){
	int n;//간선의 수
	int p,c,w;
	cin >> n;
	for(int i = 0; i < n-1; i++){
		cin >> p >> c >> w;
		v[p].push_back(make_pair(c,w)); //부모와 연결된 자식노드
		v[c].push_back(make_pair(p,w));//양방향으로 이동가능해서
	}
	dfs(1,0);//첫번째 노드에서, 가중치 0일때부터 시작
	
	ans = 0;
	for(int i = 0; i <= n; i++){//visit배열 메모리 초기화
		visit[i] = 0;
	}	
	dfs(end_p, 0);//끝점과 가장 멀리있는 정점과의 거리 구하기
	cout << ans;
	return 0;
}
