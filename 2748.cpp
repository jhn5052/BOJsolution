#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	long long *ans;
	ans = new long long[n+1];
	ans[0] = 0;
	ans[1] = 1;
	if(n < 2){
		cout << ans[n];
	}
	else{
		for(int i = 2; i <= n; i++){
			ans[i] = ans[i-1] + ans[i-2];
		}
		cout << ans[n];
	}	
	return 0;
}
