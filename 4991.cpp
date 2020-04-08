#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int w, h;
int s, e;
int cnt = 0;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char map[21][21];
int surplus = 0;

bool isRange(int y, int x){
    if(y >= 0 && x >= 0 && y < w && x < h){
        return true;
    }
    return false;
}


int main(){
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }
        cnt = 0;
        surplus = 0;
        for(int i = 0; i < w; i++){
            for(int j = 0; j < h; j++){
                cin >> map[i][j];
                if(map[i][j] == 'o'){
                    s = i;
                    e = j;
                }
                else if(map[i][j] = '*'){
                    surplus++;
                }
            }
        }
        BFS();

        if(surplus > 0){
            cout << -1 << '\n';
        }
        else{
            cout << cnt << '\n';
        }
    }
    return 0;
}

