#include <stdio.h>

int* decomporPrimo(int num){

    /*
    passando em ponteiro e tem que receber em ponteiros
    pq o C eh mto chato

    p receber: 

    int* nomeVariavel = decomporPrimo(num)
    se fizer nomeVariavel[x] resultara no valor
    */
    static int numeros[15];
    int contador;
    int pos = 0;
    contador = 2;
    while (contador<=num){
        if(num%contador==0){
            num = num/contador;
            numeros[pos] = contador;
            pos+=1; 
        }
        else if(num==1){
            break;
        }
        else{
            contador+=1;
        }
    }
  
    return numeros;
    
}

int main(){
    int num;
    scanf("%d",&num);
    
    int* teste = decomporPrimo(num);
    for (int z = 0; z<(sizeof(teste));z++){
        if (teste[z]==0){
            break;
        }
        else{
            printf("%d ",teste[z]);    

        }
    }
    
}