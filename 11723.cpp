#include<cstdio>
#include<cstring>

int main(){
    int N, t;
    int x;
    char op[7];
    int bit = 0;
    scanf("%d", &N);
    t = N;
    while(N--){
        scanf("%s", op);
        if(!strcmp(op, "add")){
            scanf("%d", &x);
            x--;
            bit |= (1 << x);
        }
        else if(!strcmp(op, "remove")){
            scanf("%d", &x);
            x--;
            if((bit & (1 << x)) != 0){
                bit &= ~(1 << x);
            }
        }
        else if(!strcmp(op, "check")){
            scanf("%d", &x);
            x--;
            if((bit & (1 << x)) != 0){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
        else if(!strcmp(op, "toggle")){
            scanf("%d", &x);
            x--;
            if((bit & (1 << x)) != 0){
                bit &= ~(1 << x);
            }
            else{
                bit |= (1 << x);
            }
        }
        else if(!strcmp(op, "all")){
            bit = -1;
        }
        else if(!strcmp(op, "empty")){
            bit = 0;
        }

    }
    return 0;
}
