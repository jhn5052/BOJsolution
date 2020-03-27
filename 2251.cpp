#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int A, B, C;
bool visit[201][201][201] = { false };
queue<pair<pair<int, int>, int> > q;
vector<int> v;

void BFS(){
  while(!q.empty()){
    int a = q.front().first.first;
    int b = q.front().first.second;
    int c = q.front().second;
    q.pop();

    if(visit[a][b][c] == true){
      continue;
    }
    visit[a][b][c] = true;

    if(a == 0){
      v.push_back(c);
    }

      //A->B
    if(a + b > B){
      q.push(make_pair(make_pair(a+b-B, B), c));
    }
    else{
      q.push(make_pair(make_pair(0, a+b), c));
    }

      //A->C
    if(a+c > C){
      q.push(make_pair(make_pair(a+c-C, b),C));
    }
    else{
      q.push(make_pair(make_pair(0, b), a+c));
    }
      
          
    //B->A
    if(b+a > A){
      q.push(make_pair(make_pair(A, b+a-A), c));
    }
    else{
      q.push(make_pair(make_pair(b+a, 0), c));
    }

    //B->C
    if(b+c > C){
      q.push(make_pair(make_pair(a, b+c-C), C));
    }
    else{
      q.push(make_pair(make_pair(a, 0), b+c));
    }

  //C->A
    if(c+a > A){
      q.push(make_pair(make_pair(A, b), c+a-A));
    }
    else{
      q.push(make_pair(make_pair(c+a, b), 0));
    }      
      
    //C->B
    if(c+b > B){
      q.push(make_pair(make_pair(a, B), c+b-B));
    }
    else{
      q.push(make_pair(make_pair(a, c+b), 0));
    }
  }
}


int main(){
    cin >> A >> B >> C;
    q.push(make_pair(make_pair(0, 0), C));
    BFS();
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    return 0;
}

