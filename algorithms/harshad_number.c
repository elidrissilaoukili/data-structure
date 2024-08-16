#include <stdio.h>
void decompose(int ah[], int x)
{
    int i = 0;
    while (i < 2)
    {
        ah[i] = x % 10;
        x = x / 10;
        i++;
    }
}

int sumof(int ah[])
{
    int i, s = 0;
    for (i = 0; i < 2; i++)
        s += ah[i];
    return s;
}

int finalTest(int x, int sum)
{
    if (x % sum == 0)
        printf("%d is a Harshad number. \n", x);
    else
        printf("%d is NOT a Harshad number. \n", x);
}

void testHar(int a[], int size)
{
    int i, x, ah[2], sum;
    for (i = 0; i < size; i++)
    {
        x = a[i];

        decompose(ah, x);

        sum = sumof(ah);

        finalTest(x, sum);
    }
}

int main()
{
    // The array contains all the numbers that you want to add
    int a[] = {81, 15, 19, 20};

    // Generate the size of the array
    int size = sizeof(a) / sizeof(a[0]);

    testHar(a, size);

    return 0;
}

// for letting the user to check by enter the number at a time.
// write the same code, but no need to the first array
// you need just to get the elements that have been represented as x in the above code
// the second array is matter, because, it stores the values of the element x in it.
/*
    x = ab;
    secondArray = [a, b]; or [b, a] // that depends on how you decomposed the element x
*/

// you can do this by see if this mathmatic way works
// any number x that is equal to this equation [b^n = x] is a harshad number.

// Harshad number is a number that has two integers, for instance ab
// and this ab if we devide it by the sum of itself (a + b), the remainder equal to zero

/*
    // basically:
        ab / a + b = c and the remainder == 0

*/

// ☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻
/* THIS WAS AN ALGORITHM EXAM  IN THE UNIVERSITY SIDI MUHAMMAD IBN ABDULLAH IN MOROCCO */
// ☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻☻
// ELIDRISSI LAOUKILI MOHAMMED
// elidrissilaoukili.netlify.app
