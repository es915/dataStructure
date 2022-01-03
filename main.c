#include <stdio.h>

// 시작 서브 도착
// 1. 큰원반을 제외한 n-1개의 원반을 서브로 옮김
// 2. 큰원반을 시작->도착 이동
// 3. n-1개의 원반을 서브에서 시작 (시작점->서브)
// 4. 원반이 하나일때 2번 적용

void hanoi(int n, char start, char sub, char finish){
    if(n==1) {
        printf("원반 %d %c에서 %c로 이동1\n", n, start, finish);
    } else {
        hanoi(n-1, start, finish, sub);
        printf("원반 %d %c에서 %c로 이동2\n", n, start, finish);
        hanoi(n-1, sub, start, finish);
    }
}

int main () {

    hanoi(3, 'A', 'B', 'C');

    return 0;
}
