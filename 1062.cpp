#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, K;
vector<string> word;
bool alpha[26] = { false };
int result = 0;

void Find(int s, int cnt){
    if(cnt == K){
        //result
        bool flag = false;
        int ans = 0;
        for(int i = 0; i < N; i++){
            flag = false;
            for(int j = 0; j < word[i].size(); j++){
                if(!alpha[word[i][j] - 'a']){
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                ans += 1;
            }
        }
        result = result > ans ? result : ans;
        return;
    }
     //벡터에 들어있는거 하나씩 빼서 체크해보고 갯수 확인
    for(int i = s; i < 26; i++){
        if(alpha[i]){
            continue;
        }
        alpha[i] = true;
        Find(i, cnt+1);
        alpha[i] = false;
    }
}

int main()
{
    string s;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        word.push_back(s);
    }
    if (K <= 4)
    {
        cout << 0 << '\n';
        return 0;
    }

    //anta ~ tica가 있어야 최소 한단어 읽을 수 있음
    alpha[(int)'a' - 'a'] = true;
    alpha[(int)'n' - 'a'] = true;
    alpha[(int)'t' - 'a'] = true;
    alpha[(int)'i' - 'a'] = true;
    alpha[(int)'c' - 'a'] = true;
    K -= 5;

    Find(0, 0);
    cout << result << '\n';
    return 0;
}