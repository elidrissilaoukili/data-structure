#include <stdio.h>

void func1(int *a) {
    *a += 10;
}

void func2(int *b) {
    *b += 20;
}

void func3(int *c) {
    *c += 30;
}

int main() {
    void (*func_ptr[3])(int *) = {func1, func2, func3};
    int x = 5;

    for (int i = 0; i < 3; i++) {
        func_ptr[i](&x);
    }

    printf("%d\n", x);
    return 0;
}
