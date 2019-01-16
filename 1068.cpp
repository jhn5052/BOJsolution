//백준에서 복사하기
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int tree[55];
vector <int> v[55];
queue<int> q;

int main() {
	int N;//개수
	int root;//루트노드
	int del;//지우려는 노드;
	int cnt = 0;//리프노드 개수
	int leaf;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[i]);//i번째 노드가 어디에 들어있는지
		if (tree[i] == -1) {//만약 루트노드면
			root = i;//루트 노드를 i로 바꿔주기
		}
		else {
			v[tree[i]].push_back(i);//i의 루트노드에 i를 추가
		}
	}
	scanf("%d", &del); //지우려는 노드
	if (tree[del] == -1) {//만약 루트 노드면
		printf("0");
		return 0;
	}
	for (int i = 0; i < v[tree[del]].size(); i++) {//지우려는 노드가 들어있는 트리의 사이즈만큼
		if (v[tree[del]][i] == del) {
			v[tree[del]][i] = v[tree[del]].back();//루트노드로 반환
			v[tree[del]].pop_back();
			break;
		}
	}
	q.push(root);//루트노드 넣기,리프노드 탐색
	while (!q.empty()) {
		leaf = q.front();
		q.pop();
		for (int i = 0; i < v[leaf].size(); i++) {
			if (v[v[leaf][i]].size() != 0) {//벡터 트리의 i번째 노드가 크기가 0이 아니면 리프노드가 아님
				q.push(v[leaf][i]);
			}
			else {
				cnt++;//리프노드 증가
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
