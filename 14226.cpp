#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int S;
int map[2001][2001] = { 0 };

int find(){
    queue<pair<int, int> > q;
    q.push(make_pair(1,0));
    while(!q.empty()){
        int x = q.front().first;//display
        int y = q.front().second; //clipboard
        q.pop();
        if(x == S){
            cout << map[x][y] << '\n';
            return 0;
        }
        int dir[3][2] = {{x, x}, {x+y, y}, {x-1, y}};
        for(int i = 0; i < 3; i++){
            if(dir[i][0] < 0 || dir[i][0] > (2*S)){
                continue;
            }
            if(map[dir[i][0]][dir[i][1]] > 0){
                continue;
            }
            q.push(make_pair(dir[i][0], dir[i][1]));
            map[dir[i][0]][dir[i][1]] = map[x][y] + 1;
        }
    }   
    return 0;
}

int main(){
    cin >> S;
    find();
    return 0;
}
    
