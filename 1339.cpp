#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int N;
int alpha[26];
vector<int> tmp;

int main(){
 cin >> N;
 string s;
 for(int i = 0; i < N; i++){
   cin >> s;
   for(int j = 0; j < s.length(); j++){
     alpha[s[j] - 'A'] += (int)pow(10, s.length() - j - 1); 
   }
 }

 int cnt = 9;
 int sum = 0;
 for(int i = 0; i < 26; i++){
   if(alpha[i] > 0){
     tmp.push_back(alpha[i]);
   }
 }
 sort(tmp.begin(), tmp.end());
 for(int i = tmp.size()-1; i >= 0; i--){
   sum += tmp[i] * cnt;
   cnt--;
 }
 cout << sum << '\n';
 return 0;
}
