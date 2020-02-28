#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;
vector<bool> v(1000001, false);

int goldbach(){
    for(int i = 2; i <= sqrt(1000000); i++){
        if(v[i] == false){
            for(int j = i*2; j <= 1000000; j += i){
                if(v[j] == false){
                    v[j] = true;
                }
            }
        }
    }
    return 0;
}

int main(){
    int n;
    v[1] = true;
    goldbach();
    while(1){
        scanf("%d", &n);
        if(n == 0){
            break; //exit
        }
        for(int i = n-1; i > 1; i--){
            if(v[i] == false){
                int tmp = n - i;
                if(v[tmp] == false){
                    printf("%d = %d + %d\n", n, tmp, i);
                    break;
                }
            }
        }
    }
    return 0;
}
