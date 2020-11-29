#include <stdio.h>
#include <math.h>
extern int mediadora();

int calculamdc(int x, int y){
    int resto = 1;    
    int contador = 0;

    while (resto > 0){       
        resto = x%y; 
        x = y;      
        y = resto;
           
        contador += 1;
               
    }    
    return x;
}

int multiplicaM(int listaMx[], int tamanho){
    // maitrz m[x][0 = r1 e m[x][1] = m1
    
    int mzao = 1;
    for(int z=0;z<tamanho;z++){
        mzao=mzao*listaMx[z];
    }
    return mzao;
}
int validarCoprimos(int listaRx[], int listaMx[]){
    // peguei a matriz, quero destrinchar
    
    int qntdCoprimo = 0;
    for(int x=0; x<3;x++){
        for(int z=0;z<3;z++){
            if (calculamdc(listaMx[x],listaMx[z])!=1 && listaMx[x]!=listaMx[z]){
                break;
            }
            else{
                qntdCoprimo+=1;
            }
        }
    }
    if(qntdCoprimo==pow(3,2)){
        return multiplicaM(listaMx,3);
    }
    else{
        return 0;
    }
}

int calcularTeoremaRestoChines(){
    // maitrz m[x][0 = r1 e m[x][1] = m1
    static int listaRx[3] = {};
    static int listaMx[3] = {};
    
    scanf("%d %d\n",&listaRx[0],&listaMx[0]);
    scanf("%d %d\n",&listaRx[1],&listaMx[1]);
    scanf("%d %d",&listaRx[2],&listaMx[2]);

    int mzao = validarCoprimos(listaRx,listaMx);

    int listaM_pequeno_x[3] = {};
    int listaCongruencia[3] = {};
    for(int y=0;y<3;y++){
        listaM_pequeno_x[y]=mzao/listaMx[y];
    }

    for(int p=0; p<3;p++){
        // pasas congruencia onde listaMx[0]*x = 1 mod(matriz[0][1]) e joga o resultado na lista congruencia = 35x = 1 mod(9)
        listaCongruencia[p] = mediadora(listaM_pequeno_x[p],1,listaMx[p]);
    }
    
    int xzero = 0;
    for(int k=0;k<3;k++){
        xzero = xzero+(listaM_pequeno_x[k]*listaCongruencia[k]*listaRx[k]);
    }
    double final = xzero%mzao;
    return final;
}
int main(){
    // formato de entrada: (x = r mod(m) ) entrada: sequencia de r e m
    printf("%d\n",calcularTeoremaRestoChines());
}