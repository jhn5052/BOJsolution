#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef struct Wait
{
    int num, time;
}Wait;

int T;
int N, M; //접수창구개수, 정비창구개수
int K, A, B; //차량 정비소를 방문한 고객수, 고객이 이용한 (접수창구, 정비창구)
int a[12], b[12];
int customer[1001]; //접수창구 걸리는 시간, //정비창구 걸리는 시간
priority_queue<int, vector<int>, greater<int>> Aready; //접수창구 대기
queue<pair<int, int> > Bready; //정비창구 대기 (idx, time)
vector<pair<int, int> > waitA(21, {0, 0}); //접수창구, 정비창구 벡터(고객번호, 남은 시간)
vector<pair<int, int> > waitB(21, {0, 0});
int ans = 0, total = 0;

//접수창구-파라미터 시간
void SolveFirst(int tm){
    //시간이 되면 일단 해당되는 시간에 들어오는 고객이 있는지 확인
    for(int i = 1; i <= K; i++){
        //해당 시간이 같으면 우선순위큐에 인덱스를 푸쉬
        if(customer[i] <= tm){
            Aready.push(i);
            customer[i] = 99999;
        }
    }

    //대기중인 손님들 중 빈 창구 확인하거나 시간 줄이기
    for(int i = 1; i <= N; i++){
        //빈창구일때
        if(waitA[i].first == 0){
            //접수 대기중인 사람들 있을 때
            if(!Aready.empty()){
                waitA[i].first = Aready.top();
                waitA[i].second = a[i];
                Aready.pop();
            }
        }
        //빈창구가 아닐때 시간 줄이기
        else{
            waitA[i].second--;
            //접수창구에서 볼일 끝나면 정비창구로 이동
            if(waitA[i].second == 0){
                Bready.push({waitA[i].first, i});
                waitA[i].first = 0;
                if(!Aready.empty()){
                    waitA[i].first = Aready.top();
                    waitA[i].second = a[i];
                    Aready.pop();
                }
            }
        }
    }
}

//정비창구
void SolveSecond(int tm)
{
    //정비창구가 비어있는 곳으로 이동
    for(int i = 1; i <= M; i++){
        //정비 창구가 비어있으면
        if(waitB[i].first == 0){
            if(!Bready.empty()){
                waitB[i].first = Bready.front().first;
                waitB[i].second = b[i];
                if(Bready.front().second == A && i == B){
                    ans += Bready.front().first;
                }
                Bready.pop();
            }
        }
        else{
            waitB[i].second--;
            if(waitB[i].second == 0){
                total++;
                waitB[i].first = 0;
                if(!Bready.empty()){
                    waitB[i].first = Bready.front().first;
                    waitB[i].second = b[i];
                    if (Bready.front().second == A && i == B)
                    {
                        ans += Bready.front().first;
                    }
                    Bready.pop();
                }
            }
        }
    }
}

int main(){
    //freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> N >> M >> K >> A >> B;
        for(int i = 1; i <= N; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= M; i++){
            cin >> b[i];
        }

        for(int i = 1; i <= K; i++){
            cin >> customer[i];
        }

        //접수창구, 정비창구
        int t = 0;
        while(total < K){
            SolveFirst(t);
            SolveSecond(t);
            //시간 증가
            t++;
        }
        if(ans == 0){
            ans = -1;
        }
        cout << '#' << tc << ' ' << ans << '\n';

        //init
        while(!Aready.empty()){
            Aready.pop();
        }
        while (!Bready.empty())
        {
            Bready.pop();
        }
        waitA.clear();
        waitB.clear();
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        ans = 0;
        total = 0;
    }
    return 0;
}
