#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int H, W;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int map[250][250];
bool visit[250][250];
char arr[250][250];
int cnt = 0;
char word[] = {'W', 'A', 'K', 'J', 'S', 'D'};

bool isRange(int x, int y){
    if(x >= 0 && y >= 0 && x <= H+1 && y <= W*4+1){
        return true;
    }
    return false;
}


void Background_fill(int x, int y){
    visit[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(isRange(nx, ny) && map[nx][ny] == 0 && !visit[nx][ny]){
            Background_fill(nx, ny);
        }
    }
}

void DFS(int x, int y, int check){
    visit[x][y] = true;
    if(check == 1){
        //inner fill
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(isRange(nx, ny) && !visit[nx][ny] && map[nx][ny] == 0 ){
                DFS(nx, ny, check);
            }
        }
    }
    else{
        //line fill
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(isRange(nx, ny) && !visit[nx][ny]){
                if(map[nx][ny] == 0){
                    cnt++;
                    DFS(nx, ny, 1);
                }
                else{
                    DFS(nx, ny, check);
                }
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc = 0;
    while(1){
        tc += 1;
        string ans = "";
        cin >> H >> W;
        if(H == 0 && W == 0){
            break;
        }
        memset(visit, false, sizeof(visit));
        for(int i = 0; i <= H+1; i++){
            for(int j = 0; j <= W+1; j++){
                char hex;
                int num;
                if(i == 0 || i == H+1 || j == 0 || j == W+1){
                    hex = '0';
                }
                else{
                    cin >> hex;
                }

                if(hex >= 'a' && hex <= 'f'){
                    num = hex - 'a' + 10;
                }
                else{
                    num = hex - '0';
                }
                for(int k = 3; k >= 0; k--){
                    map[i][4*j+k] = num % 2;
                    num /= 2;
                }
            }
        }

        //background fill
        Background_fill(0, 0);

        //detection
        for(int i = 0; i <= H+1; i++){
            for(int j = 0; j <= 4*W+1; j++){
                if(!visit[i][j] && map[i][j] != 0){
                    cnt = 0;
                    DFS(i, j, 0);
                    ans += word[cnt];
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Case " << tc << ": " << ans << '\n';
    }
    return 0;
}

