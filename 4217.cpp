#include<iostream>
#include<cstring>
using namespace std;

int H, W;
int Tohex[16][4] = { 0 };
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
char map[201][201]
bool visit[201][201]
char ans[] = {'A', 'J', 'D', 'S', 'W', 'K'};
int main(){
    cin >> H >> W;
    //0 ~ F까지 이진수 저장
    int num, r;
    for(int i = 0; i < 16; i++){
        num = i;
        r = 3;
        while(num != 0){
            int tmp = num % 2;
            Tohexa[i][r] = tmp;
            r--;
            num = num / 2;
        }
    }



