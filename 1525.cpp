#include <iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<string>
using namespace std;

string start;
string become = "123456780";
set<string> visit;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int BFS(){
    queue<pair<string, int> > q;
    q.push(make_pair(start, 0));
    visit.insert(start);

    while(!q.empty()){
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == become){
            return cnt;
        }

        int d = cur.find('0');
        int x = d / 3;
        int y = d % 3;

        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && ny >= 0 && nx < 3 && ny < 3){
                string update = cur;
                swap(update[x*3+y], update[nx*3+ny]);
                if(visit.find(update) == visit.end()){
                    visit.insert(update);
                    q.push(make_pair(update, cnt+1));
                }
            }
        }
    }
    return -1;
}


int main(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int tmp;
            cin >> tmp;
            char a = tmp + '0';
            start += a;
        }
    }

    int ans = BFS();
    cout << ans << '\n';
    return 0;
}
