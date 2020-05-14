#include <iostream>
#include <algorithm>
using namespace std;

int N, S;
int ans = 987654321;
int L = 0, R = 0;
int map[100001];

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    int result = map[L];
    while (L < N) {
        if (R == N - 1 && result < S) {
            break;
        }
        if (L == R) {
            if (result >= S) {
                ans = 1;
                break;
            }
            else {
                R++;
                result += map[R];
            }
        }
        else {
            if (result < S) {
                R++;
                result += map[R];
            }
            else if (result >= S) {
                ans = min(ans, R - L + 1);
                result -= map[L];
                L++;
            }
        }
    }

    if (ans == 987654321) {
        cout << 0 << '\n';
    }
    else {
        cout << ans << '\n';
    }
    return 0;
}
