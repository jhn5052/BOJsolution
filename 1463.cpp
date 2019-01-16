#include<iostream>
#define MAX 1000001 
using namespace std;
int D[MAX];

//using dynamic algorithm to solve
class Calculate {
	int num;
public : 
	void setNum() {
		cin >> num;
		for (int i = 1; i <= num; i++) {
			D[i] = 99999; //initiate all array
		}
	}

	void Cal() {
		D[1] = 0;//minimum subset problem 
		for (int i = 2; i <= num; i++) {
			D[i] = D[i - 1] + 1; //method 3
			if (i % 3 == 0) { //method 1
				int result = D[i/3] + 1;
				if (result <= D[i]) {
					D[i] = result;
				}
			}
			else if (i % 2 == 0) { //method 2
				int result = D[i / 2] + 1;
				if (result <= D[i]) {
					D[i] = result;
				}
			}
		}
	}

	void printResult() {
		cout << D[num]; //print result
	}
};

int main() {
	Calculate One;
	One.setNum();
	One.Cal();
	One.printResult();
	return 0;
}