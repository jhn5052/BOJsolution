#include<iostream>
using namespace std;
int T;

class Stat {
	int HP;
	int MP;
	int Power;//���ݷ�
	int Armor;//����
	int vHP;//��ȭ�Ǵ� �ɷ�ġ
	int vMP;
	int vPower;
	int vArmor;
	int attackPower[1000]; //������

public:
	void setStat() {
		cin >> HP;
		cin >> MP;
		cin >> Power;
		cin >> Armor;
		cin >> vHP;
		cin >> vMP;
		cin >> vPower;
		cin >> vArmor;

		HP = HP + vHP;
		if (HP < 1) {
			HP = 1;//1���� ������� 1�� ����
		}

		MP = MP + vMP;
		if (MP < 1) {
			MP = 1;//1���� ������� 1�� ����
		}

		Power = Power + vPower;
		if (Power < 0) {
			Power = 0;//0���� ������� 0�� ����
		}
		Armor = Armor + vArmor;
	}

	void attack(int i) {
		attackPower[i] = 1 * (HP)+5 * (MP)+2 * (Power)+2 * (Armor);
	}

	void printStat(int i) {
		cout << attackPower[i] << endl;;
	}
};

int main() {
	cin >> T; //�׽�Ʈ ���̽��� ��
	Stat stat;
	for (int i = 0; i < T; i++) {
		stat.setStat();
		stat.attack(i);
	}

	for (int i = 0; i < T; i++) {
		stat.printStat(i);
	}
	return 0;
}