#include <stdio.h>

void map(int a[], int len, int (*f)(int)) {
    printf("map\n");
    for (int i = 0; i < len; i++) {
        a[i] = f(a[i]); 
    }
}

int inc(int i) {
    printf("inc\n");
    return i + 1;
}

int main() {
    int a[] = {0, 0, 7};
    int len = sizeof a / sizeof a[0]; // # of elements
    map(a, len, inc); // inc is a function pointer
    printf("{%d, %d, %d}\n", a[0], a[1], a[2]);
}
