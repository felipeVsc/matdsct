#include <stdio.h>
int calcula_mdc(int x, int y){
    int resto = 1;    
    int contador = 0;

    while (resto > 0){       
        resto = x%y; 
        x = y;      
        y = resto;
           
        contador += 1;
               
    }    
    return x;
}

int main(){
    int n1, n2, mdc; 

    scanf("%d%d", &n1, &n2);

    if (n2 == 0){
        mdc = calcula_mdc(n2,n1); 
    }
    else{
        mdc = calcula_mdc(n1,n2); 
    }
    printf("mdc: %d\n", mdc);  

    return 0;
}