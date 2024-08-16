#include <iostream>
using namespace std;

// functions
void kaprekarf(int number);
void decompose(int array[], int number);
void sort_array(int array[], int size);
int bring_num_one(int array[], int size);
int bring_num_two(int array[], int size);

int main()
{
    int number;
    cout << "Enter the number from 4 digits: ";
    cin >> number;

    kaprekarf(number);

    return 0;
}

void kaprekarf(int number)
{
    int array[4];
    int size = 4, kaprekar, number_one, number_two;

    kaprekar = number;

    do
    {
        number = kaprekar;
        decompose(array, number);
        sort_array(array, size);

        number_one = bring_num_one(array, size);
        number_two = bring_num_two(array, size);

        kaprekar = number_two - number_one;

        cout << kaprekar << " = " << number_two << " - " << number_one << endl;

    } while (kaprekar != number && kaprekar != 0);
}

void decompose(int array[], int number)
{
    int i;
    while (i < 4)
    {
        array[i] = number % 10;
        number /= 10;
        i++;
    }
}

void sort_array(int array[], int size)
{
    int i, j, current;
    for (i = 1; i < size; i++)
    {
        current = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > current)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}

int bring_num_one(int array[], int size)
{
    int num1 = array[0];
    for (int i = 1; i < size; i++)
        num1 = ((num1 * 10) + array[i]);
    return num1;
}

int bring_num_two(int array[], int size)
{
    int num2 = array[size - 1];
    for (int i = size - 2; i >= 0; i--)
        num2 = ((num2 * 10) + array[i]);
    return num2;
}

// Happy learning ELIDRISSI ☻☻☻☻☺☺☺