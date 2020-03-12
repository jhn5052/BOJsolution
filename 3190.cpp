#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, K, turn_times;
queue<pair<int, char> > q; // turn point
vector<pair<int, int> > s; //snake point
int map[101][101] =  { 0 }; //1 : apple, 2 = snake
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //N, S, E, W
int sec = 0; //L's time

bool isRange(int y, int x){
    if(y > N || y <= 0 || x > N || x <= 0){
        return false;
    }
    return true;
}

int main(){
    cin >> N >> K;
    int y, x;
    for(int i = 0; i < K; i++){
        cin >> y >> x;
        map[y][x] = 1;
    }

    cin >> turn_times;
    int cnt;
    char c;
    for(int i = 0; i < turn_times; i++){
        cin >> cnt >> c;
        q.push(make_pair(cnt, c));
    }
    
    //init
    map[1][1] = 2;
    int d = 1; // North : 0/ East : 1 / South : 2/ West : 3 
    s.push_back(make_pair(1, 1));
    
    while(1){
        int t, tmp_d;
        if(!q.empty()){
           int t = q.front().first;
           char tmp_d = q.front().second;
           //head point turn
           if(t == sec){
               q.pop();
               if(tmp_d == 'L'){
                   if((d-1) >= 0){
                       d -= 1; //East(1) -> North/ South(2) -> East(1)
                   }
                   else{
                       d = 3; //North(0) -> West(3);
                   }
               }
               if(tmp_d == 'D'){
                   if((d+1) < 4){
                       d += 1;
                   }
                   else{
                       d = 0;
                   }
               }
           }
        }
        sec += 1;
        int ny = s[s.size()-1].first + dir[d][0];
        int nx = s[s.size()-1].second + dir[d][1];

        if(!isRange(ny, nx) || map[ny][nx] == 2){
            break;
        }

        if(map[ny][nx] == 0){
            map[s[0].first][s[0].second] = 0;
            s.erase(s.begin());
        }
        map[ny][nx] = 2;
        s.push_back(make_pair(ny, nx));
    }
    cout << sec << '\n';
    return 0;
}
