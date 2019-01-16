#include<iostream>
#include<string>
using namespace std;

int Alph(string c){
	int alph[26] = {0};
	int j = 0;
	for(int j = 0; j < c.length(); j++){
		if(alph[c[j] - 97] == 1){
			return 0;
		}
		else{
			char s = c[j];
			alph[c[j] - 97] = 1;
			while(1){
				if(s != c[++j]){
					j--;
					break;
				}
			}
		}
	}
	return 1;
}




int main(){
	int T;
	int cnt = 0;
	string c;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> c;
		if(Alph(c) == 1){
			cnt++;
		}
	}
	cout << cnt;
	return 0;

}
		
