#include<iostream>
#include<algorithm>
using namespace std;

class Big{
	private:
		int n;
		int *arr;
		int a, b;
		int *ans;
	public:
		void setNum(){
			cin >> n;
			arr = new int[n];
			ans = new int[n];
			for(int i = 0; i < n; i++){
				cin >> arr[i];
			}
		}

		void Find(){
			a = 0;
			ans[0] = arr[0];
			for(int i = 1; i < n; i++){
				if(ans[i-1] + arr[i] > arr[i]){
					ans[i] = ans[i-1] + arr[i];
				}
				else{
					ans[i] = arr[i];
				}
			}
			int result = ans[0];
			for(int i = 0; i < n; i++){
				if(result < ans[i]){
					result = ans[i];
				}
			}
			cout << result;
		}		
};

int main(){
	Big B;
	B.setNum();
	B.Find();
	return 0;
}




