#include<iostream>
#include<algorithm>
using namespace std;

char word[1000001];
int alph[26] = { 0 };
int cnt = 0;

void Max_alpha() { //inlineÇÔ¼ö ½èÀ»¶§ 8ms ´õ ´Ã¾î³²
	int i = 0;
	while (word[i] != NULL) {
		if (word[i] >= 'A' && word[i] <= 'Z') {
			alph[word[i] - 'A'] += 1;
		}
		else if (word[i] >= 'a' && word[i] <= 'z') {
			alph[word[i] - 'a'] += 1;
		}
		i++;
	}
}

void Check() {
	cnt = alph[0];
	for (int i = 1; i < 26; i++) {
		cnt = max(cnt, alph[i]);
	}
}

char isOne() {
	int a = 0;
	int j = 0;
	char result;
	for (int i = 0; i < 26; i++) {
		if (cnt == alph[i]) {
			a++;
			j = i;
		}
	}
	if (a > 1) {
		return '?';
	}
	else if (a == 1) {
		result = (char)j + 65;
		return result;
	}
}

int main() {
	char a;
	cin >> word;
	Max_alpha();
	Check();
	a = isOne();
	cout << a << "\n";
	return 0;
}