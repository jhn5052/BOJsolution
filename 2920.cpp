#include<iostream>
using namespace std;

int main() {
	int a[9];
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}
	
	if (a[0] == 8) {
		for (int i = 1; i < 8; i++) {
			if (a[i] != 8 - i) {
				cout << "mixed";
				return 0;
			}
		}
		cout << "descending";
	}
	
	else if (a[0] = 1) {
		for (int i = 1; i < 8; i++) {
			if (a[i] != i+1) {
				cout << "mixed";
				return 0;
			}
		}
		cout << "ascending";
	}

	else if(a[0] != 8 && a[0] != 1){
		cout << "mixed";
		return 0;
	}
	return 0;
}