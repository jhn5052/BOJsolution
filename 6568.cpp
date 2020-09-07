#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 32

int MEM[MAX];
int pc = 0;
int ans = 0;

int Decoding(int instruction){
    int op = instruction / MAX;
    int value = instruction % MAX;
    pc = (pc + 1) % MAX; //넘어가면 안됨(5bit)

    if (op == 0)
    {
        //STA = 메모리 주소 x에 가산기의 값을 저장한다.
        MEM[value] = ans;
    }
    else if (op == 1)
    {
        //LDA = 메모리 주소 x의 값을 가산기로 불러온다.
        ans = MEM[value];
    }

    else if (op == 2)
    {
        //BEQ = 가산기의 값이 0이면 PC 값을 x로 바꾼다.
        if(ans == 0){
            pc = value;
        }

    }
    else if (op == 4)
    {
        //DEC = 가산기 값을 1 감소시킨다.
        ans = (ans + 255) % 256;
    }
    else if (op == 5)
    {
        //INC = 가산기 값을 1 증가시킨다.
        ans = (ans + 1) % 256;
    }
    else if (op == 6)
    {
        //JMP = PC 값을 x로 바꾼다.
        pc = value;
    }
    else if (op == 7)
    {
        //HLT = 프로그램을 종료한다.
        return -1;
    }
    return 0;
}


int main(){
    int tmp;
    while(true){
        //input
        pc = 0;
        ans = 0;
        memset(MEM, 0, sizeof(MEM));
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < 8; j++){
                if(scanf("%1d", &tmp) < 0){
                    return 0;
                }
                if (tmp == 1)
                {
                    MEM[i] += pow(2, 7 - j);
                }
            }
        }

        //decoding
        while(true){
            //명령어 불러오기
            int ins = MEM[pc];
            //해독
            int res = Decoding(ins);
            if(res == -1){
                break;
            }
        }
        for(int i = 7; i >= 0; i--){
            printf("%1d", (ans>>i)&1);
        }
        printf("\n");
    }
    return 0;
}