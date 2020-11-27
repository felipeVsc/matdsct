#include <stdio.h>
#include <math.h>
#include <string.h>
int* decomporPrimo(int num){

    /*
    passando em ponteiro e tem que receber em ponteiros
    pq o C eh mto chato

    p receber: 

    int* nomeVariavel = decomporPrimo(num)
    se fizer nomeVariavel[x] resultara no valor
    */

    static int numeros[15] = {};
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
    
    for(int x = pos; x<16;x++){
        numeros[x] = 0;
    }
    return numeros;
    
    
    
}
// retirar depois esse int ACIMA qnd for colocar no codigo geral pq essa parte ja eh da questao 3
int tamanhoArray(int tamanho, int array[]){
    int contador = 0;
    while (contador<tamanho){
        if(array[contador]==0){
            return contador-1;
        }
        else{
            contador+=1;
        }
    }
}
int* tirarRepetidos(int num1, int num2){
    static int l3[10] = {};
    int pos = 0;
    int* listaNum1 = decomporPrimo(num1);
    // forma a lista sem repeticao do num1
    for(int x=0;x<=(tamanhoArray(sizeof(listaNum1),listaNum1));x++){
        int t = 0; // apenas variavel de controle, n importa
        for(int k=0;k<=(tamanhoArray(sizeof(listaNum1),listaNum1));k++){
        if(listaNum1[x]!=l3[k]){
            t+=1;
            if(t==(tamanhoArray(sizeof(listaNum1),listaNum1)+1)){
                t=0;
                l3[pos]=listaNum1[x];
                pos+=1;
            }  
        }
    }
    }

    int* listaNum2 = decomporPrimo(num2);
// forma a lista sem repeticao do num2
    pos = (tamanhoArray(sizeof(l3),l3)+1);
    for(int z=0;z<(tamanhoArray(sizeof(listaNum2),listaNum2)+1);z++){
        int t = 0;
        for(int k=0;k<=tamanhoArray(sizeof(listaNum2),listaNum2);k++){
            if(listaNum2[z]!=l3[k]){
                    t+=1;  
                    
                if(t==(tamanhoArray(sizeof(listaNum2),listaNum2)+1)){
                    t=0;
                    l3[pos]=listaNum2[z];
                    pos+=1;
                }  
            }
        }
    }
    // mostra os numeros, falta colocar isso da retornar uma array 
    return l3;
}
// usar essa para gerar, p n ficar muito grande a outra fazer o esquema de retornar uma array
int* calcularMdcMmc(int num1,int num2){
    /*
    calcularMdcMmc(num1,num2) vai retornar na posicao 0 o MDC e na posicao 1 o mmc.
    so usar calcularMdcMmc(num1,num2)[x] sendo x o que vc quer
    */
    int* l3 = tirarRepetidos(num1,num2);
    int l4[10][10] = {{},{}}; // valor e sua qntd l1 de numeros (fatores primos do primeiro numero)
    int l5[10][10] = {{},{}}; // valor e sua qntd l2 de numeros (fatores primos do segundo numero)
    
    int* l1 = decomporPrimo(num1); // decompoe e coloca numa lista
    int pos = 0; // controle da posicao
    int qntdmax = 0; // quantidade de repetidos
    for(int x = 0; x<=tamanhoArray(sizeof(l3),l3);x++){
        for(int z=0;z<=tamanhoArray(sizeof(l1),l1);z++){
            if(l3[x]==l1[z]){
                qntdmax+=1;
            }
            l4[pos][0] = l3[x];
            l4[pos][1] = qntdmax;
            }
            pos+=1;
            qntdmax=0;
        }

    int* l2 = decomporPrimo(num2); // decompoe e coloca numa lista
    int pos1=0; // controle da posicao na lista
    int qntdmax2=0; // qntd repetidos
    
    for(int p = 0; p<=tamanhoArray(sizeof(l3),l3);p++){
        for(int j=0;j<=(tamanhoArray(sizeof(l2),l2));j++){
            if(l3[p]==l2[j]){
                qntdmax2+=1;
            }
            l5[pos1][0] = l3[p];
            l5[pos1][1] = qntdmax2;
        }
        pos1+=1;
        qntdmax2=0;
    }
 
    double mdc = 1;
    double mmc = 1;
    for(int pp=0; pp<=tamanhoArray(sizeof(l3),l3);pp++){
        int potencia = 0;
        int qntdnum = 0; // pra fazer os expoentes
        int qntdnum2 = 0; // pra fazer os expoentes 2
        for(int pp1=0; pp1<6;pp1++){
            if(l3[pp]==l4[pp1][0]){
                qntdnum = l4[pp1][1];
            }
        }
        for(int pp2=0; pp2<6;pp2++){
            if(l3[pp]==l5[pp2][0]){
                qntdnum2 = l5[pp2][1];
            }
        }
        if(qntdnum>qntdnum2){ // aqui pega o maior pr fazer o mdc
            potencia = qntdnum;
            mdc=mdc*pow(l3[pp],potencia);
        }
        else{
            potencia=qntdnum2;
            mdc=mdc*pow(l3[pp],potencia);
        }
        if(qntdnum>qntdnum2){ // aqui vai pegar o menor p fazer mmc
            potencia = qntdnum2;
            mmc=mmc*pow(l3[pp],potencia);
            
        }
        else{
            potencia = qntdnum;
            mmc=mmc*pow(l3[pp],potencia);
        }
    }
    static int listaMdcMmc[2];
    listaMdcMmc[0] = mdc;
    listaMdcMmc[1] = mmc;
    
    return listaMdcMmc;

    
}
    