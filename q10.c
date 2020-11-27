#include <stdio.h>

/*
falta fazer para que seja com n entrada e nao apenas 3

*/

int* pegarEntrada(){
    int listaRx[10] = {};
    int listaMx[10] = {};
    static int matriz[10][10] = {{},{}};
    for(int cont = 0;cont<=3;cont++){
        scanf("%d %d",&listaRx[cont],&listaMx[cont]);
    }
    for(int teste = 0; teste<=10,teste++){
        matriz[teste][0] = listaRx[teste];
        matriz[teste][1] = listaMx[teste];
    }

    return matriz;
}
int multiplicaM(int listaMx[]){
    // maitrz m[x][0 = r1 e m[x][1] = m1
    
    int mzao = 1;
    for(int z=0;z<=3;z++){
        mzao=mzao*listaMx[z];
    }
    return mzao;
}
int validarCoprimos(int matriz[]){
    // peguei a matriz, quero destrinchar
    int listaRx[10] = {};
    int listaMx[10] = {};
    
    for(int teste = 0; teste<=10,teste++){
        
        listaRx[teste] = matriz[teste][0];
        
        listaMx[teste] = matriz[teste][1]; 
    }

    int qntdCoprimos = 0;
    for(int x=0; x<sizeof(listaMx);x++){
        for(int z=0;z<sizeof(listaMx);z++){
            if (calculomdc(listaMx[x],listaMx[y])!=1 && listaMx[x]!=listaMx[y]){
                break;
            }
            else{
                qntdCoprimo+=1;
            }
        }
    }
    if(qntdCoprimo==pow(sizeof(listaMx),2){
        return multiplicaM(listaMx);
    }
    else{
        return 0;
    }
}


int calcularTeoremaRestoChines(){
    // maitrz m[x][0 = r1 e m[x][1] = m1
    int matriz = pegarEntrada();    
    int mzao = validarCoprimos(matriz);
    int listaM_pequeno_x[10] = {};
    int listaCongruencia[10] = {};
    for(int y=0;y<=3;y++){
        listaM_pequeno_x[y]=mzao/matriz[y][1];
    }
    
    for(int p=0; p<=3;p++){
        // pasas congruencia onde listaMx[0]*x = 1 mod(matriz[0][1]) e joga o resultado na lista congruencia = 35x = 1 mod(9)
        listaCongruencia[p] = congruencia(35,1,9);
    }
    int xzero = 1;
    for(int k=0;k<=3;k++){
        xzero = xzero+(listaM_pequeno_x[k]*listaCongruencia[k]*matriz[k][0];
    }
    return xzero%mzao;
}
int main(){
    // formato de entrada: (x = r mod(m) ) entrada: sequencia de r e m
    calcularTeoremaRestoChines();
}