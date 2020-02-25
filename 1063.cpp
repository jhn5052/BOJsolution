#include <iostream>
#include <cstring>
using namespace std;
int N;
string k;
string stone;

bool isRange(int r, int c){
    if (r < 0 || c > 8 || r < 0 || c > 8){
        return false;
    }
    else {
        return true
    }
}


int main(){
    cin >> k >> stone >> N;
    int k_r = int(k[0] - 'A');
    int k_c = 9 -int(k[1]);
    int s_r = int(stone[0] - 'A');
    int s_c = 9 - int(stone[1]);
    int n_kr;
    int n_kc;
    int n_sr;
    int n_sc;
    for(int i = 0; i < N; i++){
        string order;
        cin >> order;
        if(strcmp(order, "A") == 0){
            if(isRange(k_r + 1, k_c)){
                if(k_r + 1  == s_r){
                    s_r += 1;
                }
                k_r += 1;
            }
        }
        else if(strcmp(order, "L") == 0){
            if(isRange(k_r - 1, k_c)){
                    if(k_r - 1 == s_r){
                        s_r -= 1;
                    }
                    k_r -= 1;
            }
        }

        else if(strcmp(order, "B") == 0){
            if(isRange(k_r, k_c - 1)){
                if(k_c - 1 == s_c){
                    s_c -= 1;
                }
                k_c -= 1;
            }
        }
       
        else if(strcmp(order, "T") == 0){
            if(isRange(k_r, k_c + 1)){
                if(k_c + 1 == s_c){
                    s_c += 1;
                }
                k_c += 1;
            }
        }

        else if(strcmp(order, "RT") == 0){
            if(isRange(k_r + 1, k_c + 1)){
                if((k_r + 1) == (s_r + 1) && ()
        }


