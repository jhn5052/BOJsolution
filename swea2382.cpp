#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//미생물 위치, 수, 이동방향(상 : 1, 하 : 2, 좌 : 3, 우 : 4)
typedef struct info{
    int y, x;
    int num;
    int dir;
}Info;

int T, N, M, K; //testcase, map size, microbe, time
vector<Info> microbe;
int map[101][101] = { 0 };
int Dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //상하좌우

//미생물 움직이기
void Move(){
    for(int i = 0; i < microbe.size(); i++){
        //미생물 합쳐진 애들은 제외
        if(microbe[i].y == -1 && microbe[i].x == -1){
            continue;
        }
        int ny = microbe[i].y + Dir[microbe[i].dir][0];
        int nx = microbe[i].x + Dir[microbe[i].dir][1];
        map[ny][nx]++;

        //가장자리인 경우
        if(ny == 0 || ny == N-1 || nx == 0 || nx == N-1){
            //1. 미생물 수 반 감소(1인 경우 0으로 되어서 군집 사라지게)
            if(microbe[i].num == 1){
                microbe[i].y = -1;
                microbe[i].x = -1;
                microbe[i].num = 0;
                continue;
            }

            microbe[i].num /= 2;
            //2. 진행 방향 반대로 바꾸기
            if (microbe[i].dir == 2 || microbe[i].dir == 4){
                microbe[i].dir -= 1;
            }
            else{
                microbe[i].dir += 1;
            }
        }
        microbe[i].y = ny;
        microbe[i].x = nx;
    }
}

void Plus(int r, int c){
    vector<int> v;
    for(int i = 0; i < microbe.size(); i++){
        if(microbe[i].y == r && microbe[i].x == c){
            v.push_back(i); //같은 인덱스 저장
        }
    }

    //최대 찾기
    int Max = 0;
    int idx = 0;
    for(int i = 0; i < v.size(); i++){
        if(microbe[v[i]].num > Max){
            Max = microbe[v[i]].num;
            idx = v[i];
        }
    }

    //idx가 아닌경우 인덱스에 합치고 y, x -1로 변경
    for (int i = 0; i < microbe.size(); i++)
    {
        if (microbe[i].y == r && microbe[i].x == c)
        {
            if(i != idx){
                microbe[idx].num += microbe[i].num;
                microbe[i].y = -1;
                microbe[i].x = -1;
                microbe[i].num = 0;
            }
        }
    }
}

int main(){
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> N >> M >> K;
        
        int r, c, n, d;
        for(int i = 0; i < K; i++){
            cin >> r >> c >> n >> d;
            microbe.push_back({r, c, n, d});
        }

        //움직이는 시간
        for(int i = 0; i < M; i++){
            Move();
            
            //합칠 미생물들 확인
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    if(map[j][k] > 1){
                        Plus(j, k);
                    }
                }
            }
            memset(map, 0, sizeof(map));
        }

        //시간 끝나고 미생물 인덱스의 num을 다 합침
        int ans = 0;
        for(int i = 0; i < microbe.size(); i++){
            ans += microbe[i].num;
        }
        cout << '#' << tc << ' ' << ans << '\n';
        
        //init
        memset(map, 0, sizeof(map));
        microbe.clear();
    }
    return 0;
}