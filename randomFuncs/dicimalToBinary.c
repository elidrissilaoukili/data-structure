#include<stdio.h>

void convert(int dicimal){
    int rem;
    int arr[10], i = 0;
    while (dicimal > 0)
    {
        rem = dicimal % 2;
        arr[i] = rem;
        i++;
        dicimal /= 2;
    }
    for (int j = i-1; j >= 0; j--)
        printf("%d", arr[j]);
}

int main(){
    int dicimal = 13;
    convert(dicimal);
    return 0;
}