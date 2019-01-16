#include<string>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int alph[26] = { 0 };
string str;

int main() {
	int M = 0;
	while(cin >> str) {
		for(int i = 0; i < str.length(); i++){
            if(str[i] >= 'a' && str[i] <= 'z')
			    alph[str[i] - 'a']++;
		}
		str = "";
	}

	M = alph[0];
	for (int i = 1; i < 26; i++) {
		if (alph[i] > M) {
			M = alph[i];
		}
	}

	for (int i = 0; i < 26; i++) {
		if (M == alph[i]) {
			cout << (char)('a' + i);
		}
	}
	return 0;
}
