#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct info{
    int num, cnt;
} Info;

int N;
int recNum;
vector<Info> v;
int minValue = 1001;

bool cmp(Info a, Info b){
    return a.num < b.num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> recNum;
    int x;
    for(int i = 0; i < recNum; i++){
        cin >> x;
        //num이 있는지 확인, 있으면 cnt 값 증가
        bool flag = false;
        for(int j = 0; j < v.size(); j++){
            if (v[j].num == x)
            {
                flag = true;
                v[j].cnt++;
                break;
            }
        }

        //없으면 vector size > N인지 확인
        if(!flag){
            //N을 넘지 않으면 -> push_back
            if(v.size() < N){
                v.push_back({x, 1});
            }

            //N을 넘으면 가장 횟수가 적은 값 찾기
            else{
                minValue = v[0].cnt;
                for(int j = 1; j < v.size(); j++){
                    minValue = min(minValue, v[j].cnt);
                }

                for(int j = 0; j < v.size(); j++){
                    if(v[j].cnt == minValue){
                        v.erase(v.begin()+j);
                        v.push_back({x, 1});
                        break;
                    }
                }
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < N; i++){
        cout << v[i].num << ' ';
    }
    return 0;
}