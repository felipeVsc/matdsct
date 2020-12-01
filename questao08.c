#include <stdio.h>

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

int* calcula_mdc(int x, int y, int z){
    int resto = 1;    
    int contador = 0;
    int quocientes[100];
    int x_inicial = x;
    int mod = y;
    int s;
    static int mdc_s[2];

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

    mdc_s[0] = x; // em primeiro lugar sempre o MDC

    s = coeficientes (quocientes, contador, mod); 
    mdc_s[1] = s; // em segundo lugar sempre o inverso

    return mdc_s;
}

int* congruencia_d (int a, int b, int m, int mdc){
    int d = mdc;
    int A, B, M, inverso, x;
    int contador = 0;
    static int solucoes[100];

    if(b%d == 0){ //b divide d
        A = a/d;       
        B = b/d;        
        M = m/d;     

        int* novo_mdc_s =  calcula_mdc(A, M, B);
        inverso = novo_mdc_s[1];

        x = inverso * B;

        if(x > M){
            x = x % M;
        }    

        while (d > 0){
            solucoes[contador] = x + contador * M;
            d -= 1;
            contador += 1;
        }
    }
    else{
        printf("nao tem solução\n");
    }
    return solucoes;
}

int congruencia_coprimos(int a, int b, int m, int s){
    int x;   

    x = (s*b);

    if(x > m){
        x = x % m;
    } 
    return x;    
}

int mediadora (int a, int b, int m){
    int solucao;
    int* resultado =  calcula_mdc(a, m, b);
    int mdc =  resultado[0];
    int s = resultado[1];
    int k = 0;

    if (mdc == 1){
        solucao = congruencia_coprimos(a, b, m, s); //1 unica solução        
        // printf("s: %d", solucao); // tirei
        return solucao;
    } 
    else{
        int* solucoes = congruencia_d(a, b, m, mdc);
        while(k < mdc){
            if (solucoes[k] == 0){
                return 0;
            }
            else{
                printf("s%d: %d\n", k, solucoes[k]); //ainda nao sei como fazer pra essa função retornar a lista 
                k += 1;
            }
            
        }        
    }    
}

int main (){
    int a,b,m;

    scanf("%d%d%d", &a, &b, &m); 

    mediadora(a, b, m);

    return 0;
}