#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

// naive implementation
// call sequence matters

void *my_malloc(size_t size) {
    printf("my_malloc(%lu)\n", (unsigned long) size);
    void *p = sbrk(size);
    if (p == (void *) -1) {
        return NULL;
    }
    return p;
}

void my_free(void *p) {
    printf("my_free(%p)\n", p);
    int result = brk(p);
    if (result == -1) {
        perror("brk");
        exit(-1);
    }
}

void test1() {
    int *p = my_malloc(sizeof(int));
    int *q = my_malloc(sizeof(int));
    int *r = my_malloc(sizeof(int));
    printf("%p: %d\n", (void *) p, *p);
    printf("%p: %d\n", (void *) q, *q);
    printf("%p: %d\n", (void *) r, *r);
    // call my_free() in reverse order
    my_free(r);
    my_free(q);
    my_free(p);
    // assert memory has been freed
    assert(sbrk(0) == (void *) p);
}

void test2() {
    int *p = my_malloc(sizeof(int));
    int *q = my_malloc(sizeof(int));
    int *r = my_malloc(sizeof(int));
    printf("%p: %d\n", (void *) p, *p);
    printf("%p: %d\n", (void *) q, *p);
    printf("%p: %d\n", (void *) r, *p);
    // call my_free() in any order
    my_free(p);
    my_free(r);
    my_free(q);
    // assert memory has been freed
    assert(sbrk(0) == (void *) p);
}

int main(void) {
    test1();
    test2();
    return 0;
}
