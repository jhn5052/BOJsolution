#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 102

int r, c, k;
int A[MAX][MAX] = { 0 }; // 최대 100
vector<pair<int, int> > v;
int cnt = 0;

void RowCol(int row, int col){
    //행연산
    if(row >= col){
        for(int i = 1; i <= row; i++){
            v.clear();
            for(int j = 1; j <= col; j++){
                bool flag = false;
                //해당 숫자가 몇번 나왔는지 체크
                for(int t = 0; t < v.size(); t++){
                    if(v[t].second == A[i][j]){
                        v[t].first += 1;
                        flag = true;
                        break;
                    }
                }
                if (!flag && A[i][j] != 0)
                {
                    v.push_back({1, A[i][j]});
                }
                A[i][j] = 0;
            }
            sort(v.begin(), v.end());

            //배열에 정렬된 값 넣기 : 수 -> 갯수
            int x = 1;
            int size = v.size();
            if(size >= 50){
                size = 49;
            }
            for (int j = 0; j < size; j++)
            {
                A[i][x++] = v[j].second;
                A[i][x++] = v[j].first;
            }
        }
    }
    //열연산
    else{
        for (int i = 1; i <= col; i++)
        {
            v.clear();
            for (int j = 1; j <= row; j++)
            {
                bool flag = false;
                //해당 숫자가 몇번 나왔는지 체크
                for (int t = 0; t < v.size(); t++)
                {
                    if (v[t].second == A[j][i])
                    {
                        v[t].first += 1;
                        flag = true;
                        break;
                    }
                }
                if (!flag && A[j][i] != 0)
                {
                    v.push_back({1, A[j][i]});
                }
                A[j][i] = 0;
            }

            sort(v.begin(), v.end());

            int x = 1;
            int size = v.size();
            if (size >= 50)
            {
                size = 49;
            }

            for (int j = 0; j < size; j++)
            {
                A[x++][i] = v[j].second;
                A[x++][i] = v[j].first;
            }
        }
    }
    return;
}


int main(){
    cin >> r >> c >> k;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> A[i][j];
        }
    }

    int row = 3;
    int col = 3;
    while(true){
        //값이 100을 넘어가는 경우 -1
        if(cnt > 100){
            cnt = -1;
            break;
        }

        //값이 k일때
        if(A[r][c] == k){
            break;
        }

        //행연산과 열연산 중에 고르기
        RowCol(row, col);

        //연산 끝낸 후에 최대 r, 최대 c 찾기
        for(int i = 1; i < MAX; i++){
            for(int j = 1; j < MAX; j++){
                if(A[i][j] > 0){
                    col = max(col, j);
                }
                if(A[j][i] > 0){
                    row = max(row , j);
                }
            }
        }
        //연산의 최소 시간
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}