#include<iostream>
#include<string.h>
using namespace std;
int alph[26] = { 0 };

int main(){
	string S;
	cin >> S;
	for(int i = 0; i < S.length(); i++){
		alph[S[i] - 'a']++;
	}

	for(int i = 0; i < 26; i++){
		cout << alph[i] << ' ';
	}
	return 0;
}
	

