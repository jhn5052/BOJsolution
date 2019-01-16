//dynamic programing -> �ִ� ã��
//1.���ӵ� �� ��� �ö��� ����(������ ��ܿ� ���� x, ��������� �� ��ƾ���)
//2.�κй����� ���� ���ؼ� �ִ��� ã��
//3.�κй����� �ּڰ����� ���ư���
//4.��� �ѹ��� �Ѱ�� �Ǵ� �ΰ�� ���� �� ����

#include<iostream>
#include<algorithm>
using namespace std;

class Stair{
	int n; //����� ����
	int o_step, t_step;
	int grade[301];
	int sum[301] = { 0 }; //������ ��ã��

public:
	void setGrade() {
		cin >> n;//����� ����
		for (int i = 1; i <= n; i++) {
			cin >> grade[i];
			if (grade[i] > 10000) { //���� ����
				break; 
			}
		}
	}

	void maxGrade() {//�Ѱ�� �����Ŷ� �ΰ�� ������ ��
		sum[1] = grade[1];
		sum[2] = max(grade[1] + grade[2], grade[2]);
		for (int i = 3; i <= n; i++) {
			sum[i] = max(sum[i - 2] + grade[i], sum[i - 3] + grade[i - 1] + grade[i]);
			//�ѹ��� �ΰ�� ���� ��, �ѹ��� ����� ������
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