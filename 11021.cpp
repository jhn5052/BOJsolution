#include<iostream>
using namespace std;

int main(){
	int num;
	int A, B;
	cin >> num;
	for(int i = 1; i <= num; i++){
		cin >> A >> B;
		cout << "Case #" << i << ": " << A+B << "\n";
	}
	return 0;
}

