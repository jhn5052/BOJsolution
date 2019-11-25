#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

char map[12][6];
int cnt = 0;
int dir[4][2] = {{-1, 0}, {1, 0}, {0 ,-1}, {0, 1}};
bool visit[12][6];


int isRange(int y, int x){
    if(y < 0 || y > 11 || x < 0 || x > 5){
        return false;
    }
    else{
        return true;
    }
}

int Puyo(int y, int x){
    int ans = 1;
    visit[y][x] = true;
    for(int i = 0; i < 4; i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];
        if(isRange(ny, nx) && !visit[ny][nx] && map[y][x] == map[ny][nx]){
            ans += Puyo(ny, nx);
        }
    }
    return ans;
}
            



int main(){
     for(int i = 0; i < 12; i++){
         for(int j = 0; j < 6; j++){
             scanf(" %c", &map[i][j]);
         }
     }
    while(1){
       queue<pair<int, int> > q;
        for(int i = 0; i < 12; i++){ 
            for(int j = 0; j < 6; j++){
                memset(visit, false, sizeof(visit));
                if(map[i][j] != '.'){
                    int ans = Puyo(i,j);
                    if(ans >= 4){
                        q.push(make_pair(i,j));
                    }
                }
            }
        }
        if(q.empty() == true){
            break;
        }
        else{
            while(!q.empty()){
                int c = q.front().first;
                int r = q.front().second;
                map[c][r] = '.';
                q.pop();
            }
            cnt += 1;

            // after remove, down puyo
            for(int i = 0; i < 6; i++){
                vector<char> tmp_v;
                for(int j = 11; j >= 0; j--){
                    if(map[j][i] != '.'){
                        tmp_v.push_back(map[j][i]);
                    }
                }
                for(int j = tmp_v.size(); j < 12; j++){
                    tmp_v.push_back('.');
                }
                for(int j = 11; j >= 0; j--){
                    map[j][i] = tmp_v[11-j];
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
