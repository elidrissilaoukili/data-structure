#include <stdio.h>  
#include <stdlib.h>  
struct liste {  
    int donnee;  
    struct liste *suivant;  
};  
void add(int valeur, struct liste *lst) {  
    struct liste *nouveau = (struct liste *)malloc(sizeof(struct liste));  
    nouveau->donnee = valeur;  
    nouveau->suivant = NULL;  

    if (lst->suivant == NULL) {  
        lst->suivant = nouveau; 
    } else {  
        struct liste *tmp = lst;  
        while (tmp->suivant != NULL) {  
            tmp = tmp->suivant;  
        }  
        tmp->suivant = nouveau;  
    }  
}  
// ///////////////////////////////
// extra
// ///////////////////////////////

void freeList(struct liste *lst) {  
    struct liste *temp;  
    while (lst != NULL) {  
        temp = lst;  
        lst = lst->suivant;  
        free(temp);  
    }  
}  
void display(struct liste *temp) {  
    while (temp != NULL) {  
        printf("%d -> ", temp->donnee);  
        temp = temp->suivant;  
    }  
    printf("NULL\n");  
}  
int main() {  
    struct liste *lst = (struct liste *)malloc(sizeof(struct liste)); 
    lst->suivant = NULL; 

    lst->donnee = 0; 
    add(5, lst);   
    add(10, lst);   
    add(15, lst);  

    display(lst->suivant);   
    
    free(lst);
    
    return 0;  
}
