#include<iostream>
using namespace std;
int main(){
	int T;
	char c;
	int arr[2];
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> arr[0] >> c >> arr[1];
		cout << arr[0]+arr[1] << '\n';
	}
	return 0;
}
