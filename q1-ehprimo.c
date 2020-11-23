#include <stdio.h>
int eh_primo(int numero, int contador){
    
    if (numero == 0 || numero == 1){
        return 0;
    }

    while (contador < numero){
        if ((numero%contador) == 0){
            return 0;
        }
        contador += 1;  
    }
       
    return 1; 
}

int main (){
    int numero, resultado;
    int contador = 2;
    
    printf("digite um numero:");
    scanf("%d", &numero);   
    
    resultado = eh_primo(numero, contador);    

    if (resultado == 1){
        printf("eh primo\n");
    }
    else{
        printf("nao eh primo\n");
    }
    
    return 0;
}