#include <iostream>
#include <cstring>
using namespace std;

int N;
int map[65][65];

void tree(int y, int x, int size){
    if(size == 1){
        cout << map[y][x];
        return;
    }
    int flag = map[y][x];
    bool check = false;
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(flag != map[i][j]){
                check = true;
                break;
            }
        }
        if(check == true){
            break;
        }
    }
    if(check == false){
        cout << flag;
    }
    else{
        cout << '(';
        tree(y, x, size/2); //2
        tree(y, x + size/2);// 1
        tree(y + size/2, x, size/2);//3
        tree(y + size/2, x + size/2, size/2);
        cout << ')';
    }
    return;
}


int main(){
    cin >> N;
    memset(map, 0, sizeof(map));
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < N; j++){
            map[i][j] = tmp[j] - 48;
        }
    }

    tree(0, 0, N);
    return 0;
}


