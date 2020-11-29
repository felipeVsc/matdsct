#include <stdio.h>

/*
falta fazer para que seja com n entrada e nao apenas 3

*/

int* pegarEntrada(){
    int n;
    scanf("%d\n",&n);
    int listaRx[n] = {};
    int listaMx[n] = {};
    static int matriz[n][n] = {{},{}};
    for(int cont = 0;cont<=n;cont++){
        scanf("%d %d\n",&listaRx[cont],&listaMx[cont]);
    }
    for(int teste = 0; teste<=n,teste++){
        matriz[teste][0] = listaRx[teste];
        matriz[teste][1] = listaMx[teste];
    }

    return matriz;
}
int multiplicaM(int listaMx[], int tamanho){
    // maitrz m[x][0 = r1 e m[x][1] = m1
    
    int mzao = 1;
    for(int z=0;z<tamanho;z++){
        mzao=mzao*listaMx[z];
    }
    return mzao;
}
int validarCoprimos(int matriz[],int tamanho){
    // peguei a matriz, quero destrinchar
    int listaRx[tamanho] = {};
    int listaMx[tamanho] = {};
    
    for(int desmonte = 0; desmonte<tamanho,desmonte++){
        
        listaRx[desmonte] = matriz[desmonte][0];
        
        listaMx[desmonte] = matriz[desmonte][1]; 
    }

    int qntdCoprimos = 0;
    for(int x=0; x<tamanho;x++){
        for(int z=0;z<tamanho;z++){
            if (calculomdc(listaMx[x],listaMx[y])!=1 && listaMx[x]!=listaMx[y]){
                break;
            }
            else{
                qntdCoprimo+=1;
            }
        }
    }
    if(qntdCoprimo==pow(tamanho,2){
        return multiplicaM(listaMx,tamanho);
    }
    else{
        return 0;
    }
}


int calcularTeoremaRestoChines(){
    // maitrz m[x][0 = r1 e m[x][1] = m1
    int matriz = pegarEntrada();    
    int tamanhoMatriz = sizeof(matriz);
    int mzao = validarCoprimos(matriz,tamanhoMatriz);
    int listaM_pequeno_x[tamanhoMatriz] = {};
    int listaCongruencia[tamanhoMatriz] = {};
    for(int y=0;y<tamanhoMatriz;y++){
        listaM_pequeno_x[y]=mzao/matriz[y][1];
    }
    // testar essa parte do <= pra ver se ta certo
    for(int p=0; p<tamanhoMatriz;p++){
        // pasas congruencia onde listaMx[0]*x = 1 mod(matriz[0][1]) e joga o resultado na lista congruencia = 35x = 1 mod(9)
        //listaCongruencia[p] = congruencia(35,1,9);
    }
    int xzero = 1;
    for(int k=0;k<tamanhoMatriz;k++){
        xzero = xzero+(listaM_pequeno_x[k]*listaCongruencia[k]*matriz[k][0];
    }
    return xzero%mzao;
}
int main(){
    // formato de entrada: (x = r mod(m) ) entrada: sequencia de r e m
    calcularTeoremaRestoChines();
}