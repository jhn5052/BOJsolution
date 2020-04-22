#include <iostream>
#include <vector>
using namespace std;

int map[9][9];
vector<pair<int, int> > v;

bool isPossible(int y, int x, int num) {
   /*가로 체크*/
   for (int i = 0; i < 9; i++) {
      //이미 번호가 존재하면
      if (map[y][i] == num) {
         return false;
      }
   }

   /*세로 체크*/
   for (int i = 0; i < 9; i++) {
      if (map[i][x] == num) {
         return false;
      }
   }

   /*정사각형 구역 체크*/
   for (int r = (y / 3)*3; r < (y / 3 + 1) * 3; r++) {
      for (int c = (x / 3)*3; c < (x / 3 + 1) * 3; c++) {
         if (map[r][c] == num) {
            return false;
         }
      }
   }

   return true;
}


void Sudoku(int idx) {
   if (idx == v.size()) {
      //스도쿠 완성
      for (int i = 0; i < 9; i++) {
         for (int j = 0; j < 9; j++) {
            cout << map[i][j];
         }
         cout << '\n';
      }
      //재귀라 return하면 잘 안끝날수도
      exit(0);
   }

   for (int i = 1; i <= 9; i++) {
      int y = v[idx].first;
      int x = v[idx].second;
      if (isPossible(y, x, i)) {
         map[y][x] = i;
         Sudoku(idx + 1);
         map[y][x] = 0;
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   string s;
   for (int i = 0; i < 9; i++) {
      cin >> s;
      for (int j = 0; j < 9; j++) {
         map[i][j] = (int)(s[j] - '0');
         if (map[i][j] == 0) {
            v.push_back(make_pair(i, j));
         }
      }
   }
   Sudoku(0);
   return 0;
}
