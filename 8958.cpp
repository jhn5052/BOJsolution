//OX퀴즈
//문제의 점수는 그 문제까지 연속된 O의 개수가 된다.
#include<iostream>
using namespace std;

int main() {
	int T,L;//테스트 케이스
	int cnt; //연속해서 맞은 개수 세기
	int result;
	char a[81];//주어진 문자열
	int *grade;
	int i, j = 0;
	cin >> T; //테스트 케이스 입력
	grade = new int[T]; //점수 저장
	L = T; 

	while (T > 0) {
		cin >> a;
		i = 0;
		result = 0;
		cnt = 0;
		while (a[i] != NULL) {
			if (a[i] == 'O') {
				cnt++;
			}
			else if (a[i] == 'X') {
				cnt = 0;
			}
			result += cnt;
			i++;
		}
		grade[j++] = result;
		T--;
	}

	for (int k = 0; k < L; k++) {
		cout << grade[k] << '\n';
	}

	return 0;
}