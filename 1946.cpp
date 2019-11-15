#include<iostream>
#include<vector>
using namespace std;
int T;
int num;
int cnt = 0;

int main(){
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        cin >> num;
        vector<pair<int, int> > v;
        int t1;
        int t2;
        for(int i = 0; i < num; i++){
            cin >> t1 >> t2;
            v.push_back(make_pair(t1, t2));
        }
        sort(v.begin(), v.end());
        cnt = 1;
        t2 = v[0].second;
        for(int i = 1; i < v.size(); i++){
            if(v[i].second < t2){
                cnt += 1;
                t2 = v[i].second;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
