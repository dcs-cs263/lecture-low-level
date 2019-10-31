#include <stdlib.h>
#include <stdio.h>

char* my_memcpy(char* dest, const char* src, int len) 
{
    for(int i=0; i<len; i++) {
        dest[i] = src[i];
    }

    return dest;
}

void print_array(char* array, int len) {
    for(int i=0; i<len; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

int main() {
    char* a = malloc(6);
    
    for(int i=0; i<6; i++) {
        a[i] = i;
    }

    printf("Contents of `a` (size 6) after initialisation:\n");
    print_array(a,6);

    char* b = malloc(3);

    printf("\nFirst six bytes starting at `b` (size 3) after initialisation:\n");
    print_array(b,6);

    my_memcpy(b,a,6);

    printf("\nFirst six bytes starting at `b` (size 3) after memcpy:\n");
    print_array(b,6);

    return 0;
}