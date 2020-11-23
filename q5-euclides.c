#include <stdio.h>
int calcula_mdc(int x, int y){ 
    int resto;
    
    while (resto > 0){        
        resto = y%x;
        y  = x;
        x = resto;
    }

    return y;
}

int main(){
    int n1, n2, mdc;
    
    printf("digite dois numeros:");
    scanf("%d%d", &n1, &n2);

    if(n1 > n2){
        mdc = calcula_mdc (n2, n1);    
    }
    else{
        mdc = calcula_mdc(n1, n2);
    }   
    
    printf("%d\n", mdc);
    return 0;
}