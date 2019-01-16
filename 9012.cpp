#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int cnt;
	int T; //테스트 케이스
	char arr[51];
	int *ans;
	int j;
	cin >> T;
	ans = new int[T];

	//)))))(((((이런거 생각 못함
	for (int i = 0; i < T; i++) {
		cnt = 0;
		cin >> arr;
		j = 0;
		while (arr[j] != NULL) {
			if (cnt < 0 ) {
				break;
			}
			if (arr[j] == '(') {
				cnt++;
			}
			else if (arr[j] == ')') {
				cnt--;
			}
			j++;
		}
		if (cnt == 0) {
			ans[i] = 1;
		}
		else {
			ans[i] = 0;
		}
	}

	for (int i = 0; i < T; i++) {
		if (ans[i] == 1) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}