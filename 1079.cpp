#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct info {
   int num;
   bool dead;
};
int N;
vector<info> p;
int R[20][20];
int mafia_idx;
int ans = 0;

void Kill_Citizen(int num, int day) {
   if (p[mafia_idx].dead == true || num == 1) {
      ans = max(ans, day);
      return;
   }

   //밤 -> 마피아가 사람 고름(유죄지수 바뀜, day증가)
   if (num % 2 == 0) {
      //죽지 않은 사람 중 한명씩 골라보고 -> return되기 전까지 타고 들어가기 -> 다시 복구
      for (int i = 0; i < N; i++) {
         if (!p[i].dead && i != mafia_idx) {
            
            p[i].dead = true;
            //살아있는 사람들 유죄지수 변경
            for (int j = 0; j < N; j++) {
               if (!p[j].dead) {
                  p[j].num += R[i][j];
               }
            }

            //변경된걸로 DFS
            Kill_Citizen(num - 1, day + 1);

            //다시 복구
            for (int j = 0; j < N; j++) {
               if (!p[j].dead) {
                  p[j].num -= R[i][j];
               }
            }
            p[i].dead = false;
         }
      }
   }

   //낮 -> 시민이 유죄지수 제일 높은사람 선택(유죄지수 안바뀜, day증가x)
   else{
      //살아있는 사람 중, 유죄지수 높은 사람 인덱스, 유죄지수 찾기
      int idx = 0;
      int Max = 0;
      for(int i = 0; i < N; i++){
         if (!p[i].dead && Max < p[i].num) {
            idx = i;
            Max = p[i].num;
         }
      }
      if (idx == mafia_idx) {
         ans = max(ans, day);
         return;
      }

      p[idx].dead = true;
      Kill_Citizen(num - 1, day);
      p[idx].dead = false;
   }
}


int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> N;
   p = vector<info>(N);
   for (int i = 0; i < N; i++) {
      cin >> p[i].num;
      p[i].dead = false;
   }

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cin >> R[i][j];
      }
   }
   cin >> mafia_idx;
   Kill_Citizen(N, 0);
   cout << ans << '\n';
   return 0;
}
