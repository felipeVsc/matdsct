#include <stdio.h>

//funções copiadas da q6
int coeficientes (int quocientes[], int contador, int mod){
    int matriz_st[100];
    int st[2];
    int c_inicial = contador;
    int t = 0;
    int s = 1;
    int i = 0;

    if (contador == 0){ //contador é par
        st[0] = t; //esse é meu s
        st[1] = s; //esse é meu t        
    }
    else if(contador == 1){ //contador é ímpar
        st[0] = s + t; //esse é meu s
        st[1] = (quocientes[0] * s + t) * -1; //esse é meu t
    }
    else {
        contador -=1;
        while (contador >= 0){
            matriz_st[i] = quocientes[contador] * s + t;
            t = s;
            s = matriz_st[i];

            contador -= 1;
            i += 1; 
        }
        if(c_inicial%2 == 0){ // se contador for par, o s tem que ser negativo
            st[0] =  matriz_st[i-2] * -1; //esse é meu s
            st[1] = matriz_st[i-1]; //esse é meu t
        } 
        else{ // se o contador é impar, o t tem que ser negativo
            st[0] =  matriz_st[i-2]; //esse é meu s
            st[1] = matriz_st[i-1] * -1; //esse é meu t
        }
    }
    
    s = st[0]; 
    if (s < 0){
        while (s < 0 && s < mod){ //0 incluso ou nao?
            s = s + mod;
        }        
    }
    return s;
}

int calcula_mdc(int x, int y){
    int resto = 1;    
    int contador = 0;
    int quocientes[100];
    int s;
    int mod = y;

    while (resto > 0){       
        resto = x%y; 
            
        if (resto == 0) //pq nao queremos incluir o valor do quociente quando o resto é 0
        {
            x = y; // garante o valor do mdc
            break;        
        }  
        else 
        {
            quocientes[contador] = x/y; 
            x = y;      
            y = resto;
            contador += 1;
        }        
    }

    s = coeficientes (quocientes, contador, mod); 

    return s; /* nessa questão retorna s e nao o mdc.
             solução futura seria retornar um vetor com mdc e s*/
}

int main(){
    int a, mod, inverso;  
 
    scanf("%d%d", &a, &mod);
    
    inverso = calcula_mdc(a,mod);       
    
    printf("inverso de %d mod %d: %d\n", a, mod, inverso);
    
    return 0;
}