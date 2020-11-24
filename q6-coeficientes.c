#include <stdio.h>
int coeficientes (int x, int y, int quocientes[], int i){
    int matriz_st [100];
    int novo_anterior = 0; //antepenultimo st
    int anterior = 1; //penultimo st
    int contador = 0;
    int i_inicial = i+1; //porque array tem 1 posição a menos (por causa do 0)
    int st;

    for (i; i >= 0; i--){
        st = quocientes[i] * anterior + novo_anterior;
        matriz_st[contador] = st;
        
        novo_anterior = anterior;
        anterior = st;
        
        printf("matriz %d: %d\n", contador,  matriz_st[contador]);

        contador += 1;
    }

    if (i_inicial%2 == 0){
        printf("%d %d\n", matriz_st[contador-1], -matriz_st[contador-2]);
    } 
    else{
        printf("%d %d\n", -matriz_st[contador-1], matriz_st[contador-2]);
    }
}

int calcula_mdc(int x, int y, int quocientes[]){ 
    int resto, q;
    int i = 0;

    for (resto = 1; resto > 0; i++){     
        q = y/x;      
        quocientes[i] = q;
        printf("divisao(%d, %d) = %.d\n", x, y, quocientes[i]);    
    
        resto = y%x;
        y  = x;
        x = resto; 

    }
    
    coeficientes(x, y, quocientes, (i-2));

    return y;
}

int main(){
    int n1, n2, mdc;
    int quocientes[100];
    
    printf("digite dois numeros:");
    scanf("%d%d", &n1, &n2);

    if(n1 > n2){
        mdc = calcula_mdc (n2, n1, quocientes);    
    }
    else{
        mdc = calcula_mdc(n1, n2, quocientes);
    } 
    printf("mdc(%d, %d): %d\n", n1, n2, mdc);
    return 0;
}