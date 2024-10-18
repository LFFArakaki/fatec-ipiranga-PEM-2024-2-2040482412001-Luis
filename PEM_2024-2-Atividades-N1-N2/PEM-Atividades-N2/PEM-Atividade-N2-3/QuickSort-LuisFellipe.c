#include <stdio.h>

//Disciplina: Programação Estruturada e Modular
//Prof. Carlos Veríssimo

//Objetivo do Programa: Representar o diagrama de blocos do "QuickSort"
//Data - 18/10/2024
//Autor: Luis Fellipe Franco Arakaki

void quickSort(int arr[], int limInferior, int limSup);
int particao(int arr[], int limInf, int limSup);
void troca(int posicao1, int posicao2);
void printArray(int arr[], int n);

int arr[] = {100, 70, 90, 90, 10, 40, 30};
int n = sizeof(arr)/sizeof(arr[0]);

int main()
{
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printf("\n");
    printArray(arr, n);

    return 0;
}

void quickSort(int arr[], int limInferior, int limSup)
{
    if(limInferior < limSup)
    {
        int indParticao = particao(arr, limInferior, limSup);
        quickSort(arr, limInferior, indParticao-1);
        quickSort(arr, indParticao+1, limSup);
    }
    
    return;
}

int particao(int arr[], int limInf, int limSup)
{
    int pivo = arr[limSup];
    int ind = limInf-1;
    
    for(int j=limInf;j<limSup;j++)
    {
        if(arr[j]<=pivo)
        {
            ind = ind+1;
            troca(ind, j);
        }
    }
    troca(ind+1, limSup);
    return ind+1;
}

void troca(int posicao1, int posicao2)
{
    int temp = arr[posicao1];
    arr[posicao1] = arr[posicao2];
    arr[posicao2] = temp;
    
    return;
}

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%i ", arr[i]);
    }
    
    return;
}