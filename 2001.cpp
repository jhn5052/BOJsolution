#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<pair<int, int> > map[101]; //다리 연결
vector<int> jewel; //보석 유무
bool visited[101][32768] = { false };
int ans = 0, jewel_cnt = 1;

void Solve(int island, int cnt, int bit) {
    if (island == 1) {
        ans = max(ans, cnt);
    }
    //섬에 bit에 표시된 보석만큼 들고 들어왔다
    visited[island][bit] = true;

    for (int i = 0; i < map[island].size(); i++) {
        int next = map[island][i].first;
        int weight = map[island][i].second;
        if (weight < cnt)   continue;

        //줍지 않는 경우 -> 같은 보석을 들고 방문한 적이 없을 때
        if (!visited[next][bit]) {
            Solve(next, cnt, bit);
        }
        //보석이 있을 때
        if (jewel[island] > 0) {
            if (weight < cnt + 1)   continue;
            if (!visited[next][bit | (1 << jewel[island])]) {
                Solve(next, cnt + 1, bit | (1 << jewel[island]));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;

    jewel = vector<int>(N + 1, false);
    int a, b, c;
    for (int i = 0; i < K; i++) {
        cin >> a;
        jewel[a] = jewel_cnt++;

    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        //양방향 간선
        map[a].push_back({ b, c });
        map[b].push_back({ a, c });
    }
    map[1].push_back({ 1,14 });//1-1연결
    Solve(1, 0, 0);
    cout << ans << '\n';
    return 0;
}
