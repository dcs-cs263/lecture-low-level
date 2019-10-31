#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void malicious() {
    printf("I am malicious!\n");
}

void print_array(long* array, int len) {
    for(int i=0; i<len; i++) {
        printf("array[%p] = %p\n", array+i, (void*)array[i]);
    }
}

void stack_overflow() {
    char tmp[8];

    for(int i=0; i<8; i++) {
        tmp[i] = 0;
    }

    long* ptr = (long*)tmp;
    ptr = ptr + 2;

    printf("Before stack overflow:\n");
    print_array(tmp, 3);

    *ptr = &malicious + 4;

    printf("%p\n", &malicious);

    print_array(tmp, 3);
}

int main() {
    stack_overflow();

exit: return 0;
}