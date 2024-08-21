#include <stdio.h>

// X0 = A strictement positif 
// Xn = Xn-1 / 2 si Xn-1 est pair
// Xn = 3 * Xn-1 + 1 si Xn-1 est impair


void print_sequence(int A){
    int X0 = A, Xn;
    printf("MEX0 = %d ", X0);
    while (X0 != 1)
    {
        if (X0 % 2 == 0)
        {
            Xn = X0 / 2;
            X0 = Xn;
        } else {
            Xn = 3 * X0 + 1;
            X0 = Xn;
        }
        printf("MEXn = %d ", Xn);
    }
}

void print_sequence_Ch(int A) {  
  int Xn = A;  
  printf("CHXn = %d ", Xn);  
  while (Xn != 1) {  
    if (Xn % 2 == 0) {  
      Xn = Xn / 2;  
    } else {  
      Xn = 3 * Xn + 1;  
    }  
    printf("CHXn = %d ", Xn);  
  }  
}  

int main(){
    print_sequence(5);
    printf("\n");
    print_sequence_Ch(5);
    
}

