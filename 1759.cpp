#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> pw;
bool visit[16] = { false };
int DFS(int cnt, int idx){
    if(cnt == L){
        int n1 = 0, n2 = 0;
        for(int i = 0; i < C; i++){
            if(visit[i] == true){
                if(pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u'){
                    n1 += 1;
                }
                else{
                    n2 += 1;
                }
            }
        }
        if(n1 >= 1 && n2 >= 2){
            for(int i = 0; i < C; i++){
                if(visit[i] == true){
                    cout << pw[i];
                }
            }
            cout << '\n';
        }
        return 0;
    }
    for(int i = idx+1; i < C; i++){
        if(visit[i] == false){
            visit[i] = true;
            DFS(cnt+1, i);
            visit[i] = false;
        }
    }
    return 0;
}


int main(){
    cin >> L >> C;
    for(int i = 0; i < C; i++){
        char t;
        cin >> t;
        pw.push_back(t);
    }
    sort(pw.begin(), pw.end());
    DFS(0, -1);
    return 0;
}

