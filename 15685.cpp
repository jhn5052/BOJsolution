#include <iostream>
#include <cmath>
using namespace std;

int N;
int map[11][1025];
bool visited[101][101] = { false };
int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int c_dir[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
int ans = 0;

int main(){
    cin >> N;
    int x, y, d, g;
    //초기값
    map[0][0] = 0;
    for(int i = 1; i <= 10; i++){
        int m = pow(2, i);
        int k = 1;
        for(int j = 0; j < m/2; j++){
            map[i][j] = map[i-1][j];
        }
        for(int j = m/2; j < m; j++){
            map[i][j] = map[i-1][m/2-k]+1; 
            k++;
        }
    }

    //드래곤 커브 개수
    for(int i = 0; i < N; i++){
        cin >> x >> y >> d >> g;
        visited[y][x] = true;
        int m = pow(2, g);
        for(int j = 0; j < m; j++){
            int tmp = (map[g][j] + d) % 4;
            y = y + dir[tmp][0];
            x = x + dir[tmp][1];
            visited[y][x] = true;
        }
    }

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(visited[i][j] && visited[i+1][j+1] && visited[i+1][j] && visited[i][j+1]) ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}

