#include <stdio.h>
#include <time.h>

int eh_primo(int numero){
   int contador = 2;

    while (contador < numero){
        if ((numero%contador) == 0){
            return 0;
        }
        contador += 1;  
    }       
    return 1; 
}

int main(){
    int i;
    double segundos;
    clock_t time; 

    
    for (i = 2; segundos < 60000; i += 1){
        time = clock();
        if ((eh_primo(i)) == 1){
            printf("%d\n", i);
        } 
        time = clock() - time ;

        segundos += ((double)time)/((CLOCKS_PER_SEC/1000));  
    } 

    return 0;
}