#include<iostream>
using namespace std;

int find(int a, int b){
	if(a % b == 0){
		return b;
	}
	else{
		return find(b,a%b);
	}
}

int LCM(int a, int b){
	int G = find(a,b);
	return (a*b)/G;
}


int main(){
	int T;
	int a,b;
	cin >> T;
	for(int i=0;i<T;i++){
		cin >> a >> b;
		cout << LCM(a,b) << endl;
	}
	return 0;
}
