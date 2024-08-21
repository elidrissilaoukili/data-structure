#include <stdio.h>

// Un+1 = Un + 2*Un-1


void print_sequence(int n){
    int U0 = 1, U1 = 2, Un;
    for (int i = 2; i <= n; i++)
    {
        Un = U1 + 2 * U0;
        U0 = U1;
        U1 = Un;

        printf("U%d = %d\n", i, Un);
    }
}

int main(){
    int n;
    printf("Entre le nombre de sequence pour caluler le terme suivant:\n");
    printf("***** Un+1 = Un + 2*Un-1 ***** \n n = ");
    scanf("%d", &n);
    print_sequence(n);
    
}

