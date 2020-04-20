#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int map[51][9];
int cnt = 0;
bool cur[3] = { false, };
vector<int> player_num;

//n번 이닝째, 현재 선수가 누구인지, out개수, 총 합 
void Baseball(int n, int idx, int out, int sum) {
    if (n == N) {
        //마지막 이닝이 끝나면 최댓값 갱신 후 종료
        cnt = max(cnt, sum);
        return;
    }

    //다음 타자
    int next = (idx == 8) ? 0 : idx + 1;
    if (out == 3) {
        memset(cur, false, sizeof(cur)); //이닝이 시작할때 주자는 없음
        Baseball(n + 1, idx, 0, sum);
    }

    else {
        int total = 0;
        //n번째 이닝의 타자가 아웃을 쳤을 때
        if (map[n][player_num[idx]] == 0) {
            Baseball(n, next, out + 1, sum);
        }

        //n번째 이닝의 타자가 안타를 쳤을 때
        else if (map[n][player_num[idx]] == 1) {
            total = 0;
            if (cur[2] == true) {
                total += 1;
            }
            cur[2] = cur[1];
            cur[1] = cur[0];
            cur[0] = true;
            Baseball(n, next, out, sum + total);
        }

        //n번째 이닝의 타자가 2루타 쳤을때
        else if (map[n][player_num[idx]] == 2) {
            total = 0;
            if (cur[2] == true) {
                total += 1;
            }
            if (cur[1] == true) {
                total += 1;
            }

            cur[2] = cur[0];
            cur[1] = true;
            cur[0] = false;
            Baseball(n, next, out, sum + total);
        }

        //n번째 이닝의 타자가 3루타 쳤을 때
        else if (map[n][player_num[idx]] == 3) {
            total = 0;
            if (cur[2] == true) {
                total += 1;
            }
            if (cur[1] == true) {
                total += 1;
            }
            if (cur[0] == true) {
                total += 1;
            }
            memset(cur, false, sizeof(cur));
            cur[2] = true;
            Baseball(n, next, out, sum + total);
        }

        //홈런
        else if (map[n][player_num[idx]] == 4) {
            total = 1;
            if (cur[2] == true) {
                total += 1;
            }
            if (cur[1] == true) {
                total += 1;
            }
            if (cur[0] == true) {
                total += 1;
            }
            memset(cur, false, sizeof(cur));
            Baseball(n, next, out, sum + total);
        }
    }
    return;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i < 9; i++) {
        player_num.push_back(i);
    }

    do {
        memset(cur, false, sizeof(cur));
        player_num.insert(player_num.begin() + 3, 0);
        Baseball(0, 0, 0, 0);
        player_num.erase(player_num.begin() + 3);
    } while (next_permutation(player_num.begin(), player_num.end()));

    cout << cnt << '\n';
    return 0;
}
