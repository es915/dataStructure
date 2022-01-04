#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int comInput[3];
    int i, j;
    
    srand(time(NULL));

    for(i=0; i<3; i++) {
        comInput[i] = rand()%9;

        for(j=0; j<i; j++) {
            if(comInput[j]==comInput[i]) { // 중복됬을 때
                i--; // 저장된 i를 다시 빼줌 = 원점
            }
        }
    }

    int strike;
    int ball;
    int n;
    int input[3];

    while(1) {
        n = 0;
        strike = 0;
        ball = 0;
        
        printf("숫자 3개 입력 : ");
        scanf("%d %d %d", &input[0], &input[1], &input[2]);

        if((input[0]>=0&&input[0]<=9) || (input[1]>=0&&input[1]<=9) || (input[2]>=0&&input[2]<=9)) {
            for(i=0; i<3; i++) {
                for(j=0; j<3; j++) {
                    if(input[i]==input[j]) {
                        strike++;
                    } else {
                        ball++;
                    }
                }
            }
        } else {
            continue; // 처음으로 돌아감
        }

        n++;
        printf("현재 시도 횟수 : %d \n", n);
        printf("%dStrike, %dBall\n", strike, ball);

        if(strike==3) {
            break;
        }
    }

    return 0;
}
