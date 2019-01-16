#include<iostream>
using namespace std;

int GCD(int a, int b){
	if(a%b == 0){
		return b;
	}
	else{
		return GCD(b,a%b);
	}
}

int LCM(int G, int a, int b){
	return (a*b)/G;
}
int main() {
	int a, b;
	int G;
	cin >> a >> b;
	G = GCD(a,b);
	cout << G << endl;
	cout << LCD(G,a,b);
	return 0;
}
