#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N, M, K;
int a, b, c;
typedef pair<int, int> PP;
vector<PP> v[301];
int DP[301][301] = { 0 };

int Solve(int cur, int cnt) {
    //도착지 = 마지막 도시
    if (cnt == M) {
        if (cur < N) {
            return -1;
        }
        else {
            return 0;
        }
    }

    if (cur == N) {
        return 0;
    }

    int& ans = DP[cur][cnt]; //이 위치의 주소 체크
    if (ans != -1) return ans;

    for (int i = 0; i < v[cur].size(); i++) {
        int next = v[cur][i].first;
        int value = v[cur][i].second;
        if (next < cur)    continue;
        ans = max(ans, Solve(next, cnt + 1) + value); //주소가 가리키는 곳에 값을 넣음
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    memset(DP, -1, sizeof(DP));
    cout << Solve(1,1) << '\n';
    return 0;

}
