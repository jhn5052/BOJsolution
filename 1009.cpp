#include<iostream>
#include<math.h>
using namespace std;
//�����÷ο� ����, 

int main() {
	int a, b;
	unsigned int c;//a�� b���� ����
	int n;
	int *result;
	cin >> n;
	result = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		c = a;
		for (int j = 0; j < b-1; j++) {
			c *= a;
			c = c % 10;
		}
		result[i] = c;
	}

	
	for (int i = 0; i < n; i++) {
		if (result[i] == 0) {
			cout << 10 << endl;
		}
		else {
			cout << result[i]<<endl;
		}
	}
	while (1);
	return 0;
}