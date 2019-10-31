#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_array(char* array, int len) {
    for(int i=0; i<len; i++) {
        printf("array[%p] = %d\n", array+i, array[i]);
    }
}

void stack_overflow(const char* ptr) {
    char tmp[8];

    printf("Before stack overflow:\n");
    print_array(tmp, 64);

    strcpy(tmp, ptr);

    printf("After stack overflow:\n");
    print_array(tmp, 64);
}

int main() {
    char* a = "This string is longer than 8 bytes!";
    
    stack_overflow(a);

    return 0;
}