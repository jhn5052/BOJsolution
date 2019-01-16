#include<iostream>
using namespace std;

int main() {
	int n,k,j;
	int cnt = 0; // 한수 개수
	int su[3]; //1000보다 작은 경우
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i < 100) { //한~두자리 모두 한수
			cnt = i;
		}
		else if (i == 1000) { //1000->한수 포함 안됨 break
			break;
		}
		else {
			k = i;
			j = 0;
			while (k > 0) {
				//1. 100보다 큰 경우 각각의 자리를 떼어내서 확인
				su[j] = k % 10; //역순으로 저장
				k = k / 10;
				j++;
			}
			if (su[1] - su[2] == su[0] - su[1]) {//2. 100보다 큰 경우 각각 자리수를 확인해서 등차수열이면 한수 하나 추가
				cnt++;
			}
		}
	}
	cout << cnt; //한수 출력
	return 0;
}