#include <iostream>

void SetElements(int index, int **array, int value = 0)
{
    (*array)[*(&index)] = value;
}

int main()
{
    int *point1, *point2;
    point1 = new int[1]; // Allocate memory for 1 integer
    point2 = new int[2]; // Allocate memory for 2 integers

    *point1 = 0;                     // point1[0] = 0
    SetElements(*&*point1, &point2); // SetElements(0, &point2)

    point1[0] = 1;                            // point1[0] = 1
    SetElements(*&*point1, &point2, *point1); // SetElements(1, &point2, 1)

    std::cout << point2[(*point1)] << point2[(*point1) - 1]; // Outputs point2[1] and point2[0]

    delete[] point1; // Free memory allocated to point1
    delete[] point2; // Free memory allocated to point2
}
