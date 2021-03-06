/*              Esta biblioteca contém as funções
               matemáticas para utilizacao da main

                Davi Petris e Henrique Layber                  */

#include <stdlib.h>
#include <math.h>
#include "../headers/distancias.h"

float absF(float num){
    if (num < 0){
        num = num * (-1);
    }

    return num;
}

//implementa a distância euclidiana sobre um vetor
float euclidesVetor(float *vetorTarget, int *tamTarget, float *vetorTraining){
    int i;
    float acc = 0;


    for(i = 0; i < *tamTarget; i++)
        acc += (vetorTarget[i] - vetorTraining[i]) * (vetorTarget[i] - vetorTraining[i]);
    
    float resultado = sqrt(acc);

    return resultado;
}

//Início do bloco Minkowski

//implementa Minkowski sobre um vetor (terminando a formula dele)
float minkowskiVetor(float *vetorTarget, int *tamTarget, float *vetorTraining, float r){
    int i;
    float dif, acc = 0;

    for(i = 0; i < *tamTarget; i++){
        acc += absF(vetorTarget[i] - vetorTraining[i]);        
    }
    float resultado = pow(acc, r);
    resultado = pow(acc, 1/r);

    return resultado;
}

// distrnacia de Chebysshev aplicada em um vetor
float chernobylVetor(float *vetorTarget, int *tamTarget, float *vetorTraining){
    float max = -1, atual;

    for(int i = 0; i < *tamTarget; i++){
        atual = sqrt((vetorTarget[i] - vetorTraining[i]) * (vetorTarget[i] - vetorTraining[i]));
        if(atual > max) max = atual;
    }
    
    return max;
}