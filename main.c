#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand(time(NULL));
    // 1970년도 부터 현재까지의 시간을 초단위로 셈
    // -> 숫자가 달라짐 -> 그에 따른 새로운 난수들이 출력됨

    // 1에서 6까지 난수 출력
    printf("주사위 결과 : %d\n", rand()%6 + 1);
    
    int human, computer, due=0, win=0, lose=0;
    while(1) {
        printf("가위 1, 바위 2, 보 3\n");
        printf("내려고 하는 값 : ");
        scanf("%d", &human);

        computer = rand()%3 + 1;

        if(human==computer) {
            printf("Due\n");
            due++;
        } else if(human==1&&computer==3) {
            printf("Win\n");
            win++;
        } else if(human==2&&computer==1) {
            printf("Win\n");
            win++;
        } else if(human==3&&computer==2) {
            printf("Win\n");
            win++;
        } else {
            printf("Lose\n");
            lose++;
            break;
        }
    }

    printf("승 : %d, 무 : %d, 패 : %d\n", win, due, lose);

    return 0;
}
