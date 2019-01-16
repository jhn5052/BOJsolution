#include<iostream>
#include<queue>
using namespace std;
#define MAX 100001
int cnt = 0;
int N, K;//수빈이, 동생
bool visit[MAX] = { false };
bool arr[MAX] = { false };
int np;

int BFS(int n, int k){
	queue<int> q;
	q.push(n);
	while(1){
		int s = q.size();
		for(int i = 0; i < s; i++){
			n = q.front();
			q.pop();
			if(n == k){
				return cnt;
			}
			if(n > 0 && visit[n-1] == false){
				visit[n-1] = true;
				q.push(n-1);
			}
			if(n < MAX-1 && visit[n+1] == false){
				visit[n+1] = true;
				q.push(n+1);
			}
			if(n*2 <= MAX-1 && visit[n*2] == false){
				visit[n*2] = true;
				q.push(n*2);
			}
		}
		cnt++;
	}
}


int main(){
	cin >> N >> K;
	BFS(N, K);
	cout << cnt;
	return 0;
}


