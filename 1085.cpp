#include<iostream>
using namespace std;

int main() {
	int x, y, w, h;
	int min_x, min_y;
	int min;
	cin >> x >> y; //1 <= x <= w-1, 1<=y<=h-1 
	cin >> w >> h;//w,h <= 1000
	min_x = x < w - x ? x : w - x;
	min_y = y < h - y ? y : h - y;
	min = min_x < min_y ? min_x : min_y;
	cout << min;
	return 0;
}