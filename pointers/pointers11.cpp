#include <iostream>

// Function that matches the signature `char *(*abc)(float *, float **)`
char *process(float *f, float **fp)
{
    static char result[100];
    snprintf(result, sizeof(result), "Float value: %.2f, Float pointer value: %.2f", *f, **fp);
    return result;
}

int main()
{
    // Declare a function pointer of type `char *(*)(float *, float **)`
    char *(*abc)(float *, float **) = process;

    float value = 5.5;
    float *ptr = &value;
    float **ptr_to_ptr = &ptr;

    // Use the function pointer to call the function
    char *result = abc(ptr, ptr_to_ptr);

    // Output the result
    std::cout << result << std::endl;

    return 0;
}
