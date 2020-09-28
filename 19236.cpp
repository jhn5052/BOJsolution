#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct info{
    int y, x, d;
    bool isLive;
}Info;
int dir[9][2] = {{0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
int ans = 0;
int shark_dir;
Info Fish[17];
int map[5][5];

void Solve(int s_y, int s_x, int shark_d, int cnt){
    ans = max(ans, cnt);
    //백트레킹을 위한 임시변수
    int tmp[5][5];
    Info tmp_fish[17];

    //map과 물고기 상태 저장
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            tmp[i][j] = map[i][j];
        }
    }
    for(int i = 1; i <= 16; i++){
        tmp_fish[i] = Fish[i];
    }

    //1.물고기 움직이기
    for(int i = 1; i <= 16; i++){
        if(Fish[i].isLive == false){
            continue;
        }
        int cur_y = Fish[i].y;
        int cur_x = Fish[i].x;
        int nd = Fish[i].d;

        //8방향 탐색
        int t = 8;
        while(t > 0){
            t--;
            int ny = cur_y + dir[nd][0];
            int nx = cur_x + dir[nd][1];
            if(ny >= 0 && nx >= 0 && ny < 4 && nx < 4){
                //빈칸일 때 이동할 수 있음
                if(map[ny][nx] == 0){
                    Fish[i].y = ny;
                    Fish[i].x = nx;
                    Fish[i].d = nd;
                    map[cur_y][cur_x] = 0;
                    map[ny][nx] = i;
                    break;
                }
                //상어가 아닐때 -> 바꾸기
                else if(map[ny][nx] != -1){
                    Info t_fish = Fish[i];

                    //물고기 사이즈 바꾸기
                    int tmp_idx = map[ny][nx];
                    map[cur_y][cur_x] = tmp_idx;
                    map[ny][nx] = i;

                    //현재의 물고기 정보를 다른 물고기와 바꾸기
                    t_fish = Fish[i];
                    Fish[i].y = Fish[tmp_idx].y;
                    Fish[i].x = Fish[tmp_idx].x;
                    Fish[i].d = nd;
                    Fish[i].isLive = Fish[tmp_idx].isLive;

                    Fish[tmp_idx].y = t_fish.y;
                    Fish[tmp_idx].x = t_fish.x;
                    //Fish[tmp_idx].d = nd;
                    Fish[tmp_idx].isLive = t_fish.isLive;
                    break;
                }
            }
            nd = nd+1 > 8 ? 1 : nd+1;
        }
    }

    //상어 움직이기
    int sharkY = s_y;
    int sharkX = s_x;
    for(int i = 1; i < 4; i++){
        sharkY += dir[shark_d][0];
        sharkX += dir[shark_d][1];
        if(sharkY >= 0 && sharkX >= 0 && sharkY < 4 && sharkX < 4){
            //빈칸일때 건너뛰기
            if (map[sharkY][sharkX] == 0)
            {
                continue;
            }
            //먹은 고기 죽은 상태로 만들기
            int eatSize = map[sharkY][sharkX];
            int eatDir = Fish[eatSize].d;
            map[s_y][s_x] = 0;
            map[sharkY][sharkX] = -1;
            Fish[eatSize].isLive = false;
            Solve(sharkY, sharkX, eatDir, cnt + eatSize);

            //원상태 복귀
            map[s_y][s_x] = -1;
            map[sharkY][sharkX] = eatSize;
            Fish[eatSize].isLive = true;
        }
        else{//범위를 벗어난 경우
            break;
        }
    }

    //map과 물고기 상태 원상복귀
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            map[i][j] = tmp[i][j];
        }
    }
    for (int i = 1; i <= 16; i++)
    {
        Fish[i] = tmp_fish[i];
    }
}

int main(){
    int s, d;
    //input
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> s >> d;
            map[i][j] = s;
            Fish[s] = {i, j, d, true};
        }
    }
    
    //물고기 -> 상어 -> 물고기 -> 상어...
    ans = map[0][0];
    shark_dir = Fish[ans].d;
    Fish[ans].isLive = false;
    map[0][0] = -1;
    Solve(0, 0, shark_dir, ans);
    cout << ans << '\n';
    return 0;
}