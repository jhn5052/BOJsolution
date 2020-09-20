#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

string gear[5];
int ans = 0;
int K;

void turnGear(int gearNum, int dir){
    if(dir == 1){//시계방향
        int tmp = gear[gearNum][7];
        for(int i = 6; i >= 0; i--){
            gear[gearNum][i+1] = gear[gearNum][i];
        }
        gear[gearNum][0] = tmp;
    }
    else{//반시계방향
        int tmp = gear[gearNum][0];
        for (int i = 1; i <= 7; i++)
        {
            gear[gearNum][i-1] = gear[gearNum][i];
        }
        gear[gearNum][7] = tmp;
    }
    return;
}

void Solve(int gear_num, int turn_dir, int dir){
    if(gear_num > 4 || gear_num < 1){
        return;
    }
    //현재 톱니바퀴의 2번과 오른쪽 톱니바퀴의 6번 보기
    if (gear_num < 4 && gear_num >= 1 && (dir == 1 || dir == 0))
    {
        //극이 다를 경우
        if(gear[gear_num][2] != gear[gear_num+1][6]){
            Solve(gear_num+1, turn_dir * -1, 1);
        }

    }

    //현재톱니바퀴의 6번과 왼쪽 톱니바퀴의 2번 보기
    if (gear_num <= 4 && gear_num > 1 && (dir == 2 || dir == 0)) 
    {
        //극이 다를 경우
        if (gear[gear_num][6] != gear[gear_num-1][2])
        {
            Solve(gear_num - 1, turn_dir * -1, 2);
        }
    }
    turnGear(gear_num, turn_dir);
    return;
}

int main(){
    //input
    for(int i = 1; i <= 4; i++){
        cin >> gear[i];
    }
    cin >> K;
    for(int i = 0; i < K; i++){
        int gear_num;
        int turn_dir;
        cin >> gear_num >> turn_dir;
        Solve(gear_num, turn_dir, 0);
    }

    for(int i = 0; i < 4; i++){
        if(gear[i+1][0] == '1'){
            ans += pow(2, i);
        }
    }
    cout << ans << '\n';
    return 0;
}