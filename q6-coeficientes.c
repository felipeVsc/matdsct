#include <stdio.h>
int coeficientes (int quocientes[], int i){
    int matriz_st [100];
    int novo_anterior = 0; //antepenultimo st
    int anterior = 1; //penultimo st
    int contador = 0;
    int i_inicial = i; 
    int st;

    for (i; i >= 0; i--){
        st = quocientes[i] * anterior + novo_anterior;
        matriz_st[contador] = st;
        
        novo_anterior = anterior;
        anterior = st;

        contador += 1;
    }

    if (i_inicial%2 == 0){
        printf("s:%d t:-%d\n", matriz_st[contador-2], matriz_st[contador-1]);
    } 
    else{
        printf("s:-%d  t:%d\n", matriz_st[contador-2], matriz_st[contador-1]);
    }
}

int calcula_mdc(int x, int y, int quocientes[]){ 
    int resto, q;
    int i = 0;
    
    for (resto = 1; resto > 0; i++){     
        q = x/y;      
        quocientes[i] = q;
        resto = x%y;

        x  = y;
        y = resto; 
    }

    coeficientes(quocientes, i);    
    return x;
}

int verifica_numeros(int n1, int n2){
    int mdc;
    int quocientes[100];

    if (n1 == 0){
        mdc = n2;
        coeficientes(quocientes, 1); // 1 pra entrar na segunda condição (contador = 2)
    }  
    else if (n2 == 0){
        mdc = n1;
        coeficientes(quocientes, 2); // 2 pra entrar na primeira condição (contador = 3)
    }  
    else{
        mdc = calcula_mdc(n1, n2, quocientes);
    } 

    return mdc;
}

int main(){
    int n1, n2;
    
    printf("digite dois numeros:");
    scanf("%d%d", &n1, &n2);
   
    printf("mdc = %d\n", verifica_numeros(n1, n2)); //verifica numeros vai distribuir os casos de n1 e n2 entre as funções 
    return 0;
}