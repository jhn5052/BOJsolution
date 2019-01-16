
#include<iostream>
using namespace std;
int sum = 0;
int i = 0;
char al[101];
void find() {
	if (al[i] == 'c') {
		if (al[i + 1] == '=') {
			sum += 1;
			i++;
			return;
		}
		else if (al[i + 1] == '-') {
			sum += 1;
			i++;
			return;
		}
		else {
			sum++;
			return;
		}
	}
	if (al[i] == 'd') {
		if (al[i + 1] == 'z') {
			if (al[i + 2] == '=') {
				i += 2;
				sum += 1;
				return;
			}
		}
		else if (al[i + 1] == '-') {
			sum += 1;
			i++;
			return;
		}
		else {
			sum += 1;
			return;
		}
	}
	if (al[i] == 'l') {
		if (al[i + 1] == 'j') {
			sum += 1;
			i++;
			return;
		}
		else {
			sum++;
			return;
		}
	}
	if (al[i] == 'n') {
		if (al[i + 1] == 'j') {
			sum += 1;
			i++;
			return;
		}
		else {
			sum++;
			return;
		}
	}
	if (al[i] == 's') {
		if (al[i + 1] == '=') {
			sum += 1;
			i++;
			return;
		}
		else {
			sum++;
			return;
		}
	}
	if (al[i] == 'z') {
		if (al[i + 1] == '=') {
			sum += 1;
			i++;
			return;
		}
		else {
			sum++;
			return;
		}
	}
	else {
		sum++;
		return;
	}
}

int main() {
	cin >> al;
	while (al[i] != '\0') {
		find();
		i++;
	}
	cout << sum;
	return 0;
}
