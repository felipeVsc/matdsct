#include <stdio.h>

void coeficientes (int quocientes[], int contador){
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
    
    printf("s:%d t:%d\n", st[0], st[1]);
}

int calcula_mdc(int x, int y){
    int resto = 1;    
    int contador = 0;
    int quocientes[100];
    int st;

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


    coeficientes (quocientes, contador);
    
    return x;
}

int main(){
    int n1, n2, mdc;    
    scanf("%d%d", &n1, &n2);
    if (n2 == 0){
        /*OBS:nao sei como fazer pra ele retonar o coeficiente certo 
        nsse caso. quem quiser ajudar agradeço*/
        mdc = calcula_mdc(n2,n1); 
    }
    else{
        mdc = calcula_mdc(n1,n2); 
    }
    printf("mdc: %d\n", mdc);   

    return 0;
}