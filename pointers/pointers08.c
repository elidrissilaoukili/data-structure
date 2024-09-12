#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point points[3] = {{1, 2}, {3, 4}, {5, 6}};
    struct Point *ptr = points;

    (ptr + 1)->x = 10;
    (*(ptr + 2)).y = 20;

    printf("%d, %d, %d, %d\n", points[0].x, points[1].x, points[2].x, points[2].y);

    return 0;
}
