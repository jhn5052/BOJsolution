#include<iostream>
#include<math.h>
#include<cstdio>
#include<algorithm>
using namespace std;
double absolute(double s) {
	if (s >= 0) {
		return s;
	}
	else {
		return -1*s;
	}
}
int main() {
	double ax, bx, cx;
	double ay, by, cy;
	double A, B, C;
	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> cx >> cy;
	if (absolute((by - ay) / (bx - ax)) == absolute((cy - ay) / (cx - ax))) {
		cout << -1;
		return 0;
	}
	
	A = sqrt(((ax - bx)*(ax - bx)) + (ay - by)*(ay - by)) * 2 + sqrt(((ax - cx)*(ax - cx)) + ((ay - cy)*(ay - cy))) * 2;
	B = sqrt(((ax - bx)*(ax - bx)) + ((ay - by)*(ay - by))) * 2 + sqrt(((bx - cx)*(bx - cx)) + ((by - cy)*(by - cy))) * 2;
	C = sqrt(((bx - cx)*(bx - cx)) + ((by - cy)*(by - cy))) * 2 + sqrt(((ax - cx)*(ax - cx)) + ((ay - cy)*(ay - cy))) * 2;
    printf("%.15lf", max(A, max(B, C)) - min(A, min(B, C)));
	return 0;
}
