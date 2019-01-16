#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int u = 1, d = 1;
	int i = 1;
	while (1) {
		if (N == i) {
			cout << u << '/' << d;
			return 0;
		}
		if (u == 1 && d == 1) {
			d++;
			i++;
			if (N == i) {
				cout << u << '/' << d;
				return 0;
			}
		}
		if (u == 1) {
			while (d + 1 > 0) {
				u++;
				d--;
				i++;
				if (N == i) {
					cout << u << '/' << d;
					return 0;
				}
				if (d == 1) {
					u++;
					i++;
					break;
				}
			}
		}
		else if (d == 1) {
			while (u + 1 > 0) {
				d++;
				u--;
				i++;
				if (N == i) {
					cout << u << '/' << d;
					return 0;
				}
				if (u == 1) {
					d++;
					i++;
					break;
				}
			}
		}
	}
	cout << u << '/' << d;
	return 0;
}