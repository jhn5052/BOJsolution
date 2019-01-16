#include<iostream>
using namespace std;

int main(){
	int n, k = 1, t;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			cout << " ";
		}
		t = 2*n-k;
		while(t > 0){
			cout << "*";
			t--;

		}
		k += 2;
		cout << '\n';
	}
	return 0;
}
