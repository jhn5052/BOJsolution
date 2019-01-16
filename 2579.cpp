//dynamic programing -> 최댓값 찾기
//1.연속된 세 계단 올라가지 못함(시작점 계단에 포함 x, 마지막계단 꼭 밟아야함)
//2.부분문제의 합을 구해서 최댓값을 찾기
//3.부분문제의 최솟값부터 나아가기
//4.계단 한번에 한계단 또는 두계단 오를 수 있음

#include<iostream>
#include<algorithm>
using namespace std;

class Stair{
	int n; //계단의 개수
	int o_step, t_step;
	int grade[301];
	int sum[301] = { 0 }; //최적의 합찾기

public:
	void setGrade() {
		cin >> n;//계단의 개수
		for (int i = 1; i <= n; i++) {
			cin >> grade[i];
			if (grade[i] > 10000) { //조건 깨짐
				break; 
			}
		}
	}

	void maxGrade() {//한계단 오른거랑 두계단 오른거 비교
		sum[1] = grade[1];
		sum[2] = max(grade[1] + grade[2], grade[2]);
		for (int i = 3; i <= n; i++) {
			sum[i] = max(sum[i - 2] + grade[i], sum[i - 3] + grade[i - 1] + grade[i]);
			//한번에 두계단 오를 때, 한번에 세계단 오를때
		}
	}

	void outResult() {
		cout << sum[n];
	}
};

int main() {
	Stair s;
	s.setGrade();
	s.maxGrade();
	s.outResult();

	return 0;
}