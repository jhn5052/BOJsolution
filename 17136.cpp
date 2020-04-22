#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int map[10][10];
int paper[6] = { 0, 5, 5, 5, 5, 5 };
int cnt = 987654321;
int sum = 0;

bool is_possible(int y, int x, int n) {
   if ((y + n - 1 >= 10) || (x + n - 1 >= 10)) {
      return false;
   }
   if (paper[n] > 0) {
      for (int i = y; i < y + n; i++) {
         for (int j = x; j < x + n; j++) {
            if (map[i][j] == 0) {
               return false;
            }
         }
      }
      return true;
   }
   return false;
}

void Search(int y, int x) {
   if (x >= 10) { 
      Search(y + 1, 0);
      return;
   }
   if (y >= 10) {
      cnt = min(sum, cnt);
      return;
   }

   if (map[y][x] == 1) {
      for (int n = 5; n > 0; n--) {
         if (is_possible(y, x, n) == true) {
            paper[n] -= 1;
            for (int i = y; i < y + n; i++) {
               for (int j = x; j < x + n; j++) {
                  map[i][j] = 0;
               }
            }
            
            sum += 1;
            Search(y, x + n);
            paper[n] += 1;
            sum -= 1;

            for (int i = y; i < y + n; i++) {
               for (int j = x; j < x + n; j++) {
                  map[i][j] = 1;
               }
            }
         }
      }
   }
   else if (map[y][x] == 0) {
      Search(y, x + 1);
   }
   
}

int main() {
   for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
         cin >> map[i][j];
      }
   }

   Search(0, 0);
   
   if (cnt == 987654321) {
      cout << -1 << '\n';
   }
   else {
      cout << cnt << '\n';
   }
   return 0;
}
