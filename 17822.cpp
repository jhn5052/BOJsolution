#include <iostream>
#include <cstring>
using namespace std;

int N, M ,T;
int map[51][51];
int x, d, k;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, 1}};
bool visited[51][51] = { false };
int ans;
/*
void Print(){
    cout << '\n';
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}
*/
void Check(){
    bool flag = false;
    memset(visited, false, sizeof(visited));
    int n = 0, sum = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(map[i][j] != -1){
                for(int h = 0; h < 4; h++){
                    int y = i + dir[h][0];
                    int x = j + dir[h][1];
                    if(y > N || y < 1)  continue;
                    if(x == M+1)  x = 1;
                    if(x == 0)  x = M;
                    if(map[i][j] == map[y][x]){
                        visited[y][x] = true;
                        visited[i][j] = true;
                        flag = true;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(visited[i][j]){
                map[i][j] = -1;
            }
            else if(!visited[i][j] && map[i][j] != -1){
                sum += map[i][j];
                n++;
            }
        }
    }
    if(flag == false){
        double avg = (double)sum/(double)n;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(map[i][j] != -1){
                    if(double(map[i][j]) > avg){
                        map[i][j] -= 1;
                        sum -=1;
                    }
                    else if(double(map[i][j]) < avg){
                        map[i][j] += 1;
                        sum += 1;
                    }
                }
            }
        }
    }
    ans = sum;
}


void Solve(int num, int direction, int cnt){
    //회전 함수
    if(direction == 0){//시계방향
        while(cnt > 0){
            cnt--;
            int mem = map[num][M];//맨 끝 인덱스
            for(int i = M; i > 1; i--){
                map[num][i] = map[num][i-1];
            }
            map[num][1] = mem;
        }
    }
    else if(direction == 1){//반시계방향
        while(cnt > 0){
            cnt--;
            int mem = map[num][1];
            for(int i = 1; i < M; i++){
                map[num][i] = map[num][i+1];
            }
            map[num][M] = mem;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> map[i][j];
        }
    }
    for(int i = 1; i <= T; i++){
        cin >> x >> d >> k;
        for(int j = x; j <= N; j += x){
            //x의 배수만큼
            Solve(j, d, k);
        }
        //T만큼 회전 끝난 후 -> 지울것 체크 || 큰수 작은수 변경
        Check();
        //Print();
    }
    cout << ans << '\n';
    return 0;
}
