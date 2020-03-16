#include<iostream>
using namespace std;

int map[10][10] = { 0 };
bool r[10][10] = { false };
bool c[10][10] = { false };
bool v[10][10] = { false };

int Sudoku(int depth){
    int t_x = depth / 9;
    int t_y = depth % 9;

    if(depth == 81) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
        return 0;
    }
    if(map[t_x][t_y] == 0){
        for(int i = 1; i <= 9; i++){
            if(r[t_x][i] == false && c[t_y][i] == false && v[(t_x/3)*3 + (t_y/3)][i] == false){ 
                //가로, 세로, 3*3 에 없는 숫자
                r[t_x][i] = true;
                c[t_y][i] = true;
                v[(t_x/3)*3 + (t_y/3)][i] = true;
                map[t_x][t_y] = i;
                Sudoku(depth+1);
                r[t_x][i] = false;
                c[t_y][i] = false;
                map[t_x][t_y] = 0; //backtracking
                v[(t_x/3)*3 + (t_y/3)][i] = false;
            }
        }
    }
    else{
        Sudoku(depth+1);
    }
    return 0;
} 

int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> map[i][j];
            if(map[i][j] > 0){
                r[i][map[i][j]] = true;
                c[j][map[i][j]] = true;
                v[(i/3)*3 + (j/3)][map[i][j]] = true;
            }
        }
    }
    Sudoku(0);
    return 0;
}
                
