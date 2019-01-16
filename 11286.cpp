#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
//절댓값을 출력하는게 아니라서 우선순위큐 두개만듦
//절댓값으로 그냥 비교 -> 출력은 원래 값
priority_queue<int> p_pq;//양수
priority_queue<int> m_pq;//음수
int heap[100000] = { 0 };//값 저장할 배열
int N;

int abs(int t) {
	if (t < 0) {
		return -t;
	}
	return t;
}

int main() {
	int x = 0;
	cin >> N;
	//양수 : 절댓값 제일큰수 맨 위에 있음->제일 아래로 가게 바꾸기
	//음수 : 절댓값 제일 작은수 맨위 -> 바꿀필요 없음
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp > 0) {//양수나 음수면 push
			p_pq.push(-1 * tmp);
		}
		else if (tmp < 0) {
			m_pq.push(tmp);
		}
		else if (tmp == 0) {//0이면 1.top, 2.pop
			if (p_pq.size() > 0 && m_pq.size() > 0) {//둘다 값이 있을 때
				if (p_pq.top() > m_pq.top()) {
					heap[x++] = abs(p_pq.top());
					p_pq.pop();
				}
				else if (p_pq.top() <= m_pq.top()) {
					heap[x++] = m_pq.top();
					m_pq.pop();
				}
			}
			else if (p_pq.empty() && m_pq.empty()) {
				heap[x++] = 0;
			}
			else if (p_pq.size() == 0 && m_pq.size() != 0) {
				heap[x++] = m_pq.top();
				m_pq.pop();
			}
			else if (p_pq.size() != 0 && m_pq.size() == 0) {
				heap[x++] = abs(p_pq.top());
				p_pq.pop();
			}
		}
	}

	for (int i = 0; i < x; i++) {
		printf("%d\n", heap[i]);
	}
	return 0;
}
