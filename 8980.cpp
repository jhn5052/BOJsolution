#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10001

int N, M, C;
int weight = 0;
pair<int, pair<int, int> > Order[MAX];
int Truck[2001] = { 0 };

//도착점 기준 오름차순
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.second.first == b.second.first)
    {
        if(a.first < b.first){
            return true;
        }
    }
    else if (a.second.first < b.second.first)
    {
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C >> M;
    int x, y, z;
    for(int i = 0; i < M; i++){
        cin >> x >> y >> z;
        Order[i].first = x; //sender
        Order[i].second.first = y; //receiver
        Order[i].second.second = z; // num
    };

    //sorting
    sort(Order, Order+M, cmp);

    //트럭에 적재할 수 있는 최댓값 구하기
    for(int i = 0; i < M; i++){
        int truck_weight = 0;
        int sender = Order[i].first;
        int reciv = Order[i].second.first;
        int num = Order[i].second.second;

        //실을 수 있는 최대값 찾기
        for(int j = sender; j < reciv; j++){
            truck_weight = max(truck_weight, Truck[j]);
        }

        truck_weight = min(num, C-truck_weight); //트럭에 실을 수 있는 최솟값
        for (int j = sender; j < reciv; j++)
        {
            Truck[j] += truck_weight;
        }
        weight += truck_weight;
    }
    
    cout << weight << '\n';
    return 0;
}