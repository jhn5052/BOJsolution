#include<iostream>
using namespace std;
int T;

class Stat {
	int HP;
	int MP;
	int Power;//공격력
	int Armor;//방어력
	int vHP;//변화되는 능력치
	int vMP;
	int vPower;
	int vArmor;
	int attackPower[1000]; //전투력

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
			HP = 1;//1보다 작은경우 1로 간주
		}

		MP = MP + vMP;
		if (MP < 1) {
			MP = 1;//1보다 작은경우 1로 간주
		}

		Power = Power + vPower;
		if (Power < 0) {
			Power = 0;//0보다 작은경우 0로 간주
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
	cin >> T; //테스트 케이스의 수
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