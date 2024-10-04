#include <stdio.h>

//Disciplina: Programação Estruturada e Modular
//Prof. Carlos Veríssimo

//Objetivo do Programa: implementar o algoritmo do "Bubble Sort"
//Data - 03/10/2024
//Autor: Luis Fellipe Franco Arakaki

int quantidade;

void entrada(int numeros[quantidade], int quantidade);
void exibir(int numeros[quantidade], int quantidade);
void ordenar(int numeros[quantidade], int quantidade);

int main()
{
    printf("Digite quantos números quer ordenar:\n");
    scanf("%i",&quantidade);
    if(quantidade <= 1)
    {
        printf("\nQuantidade de números deve ser maior que 1\n\n");
        main();
    }
    printf("\n");
    
    int numeros[quantidade];
    
    entrada(numeros, quantidade);
    printf("Array inicial: ");
    exibir(numeros, quantidade);
    ordenar(numeros, quantidade-1);
    printf("Array ordenado: ");
    exibir(numeros, quantidade);

    return 0;
}

void entrada(int numeros[quantidade], int quantidade)
{
    printf("Digite os números a serem ordenados:\n");
    for(int i = 0;i<quantidade;i++)
    {
        scanf("%i",&numeros[i]);
    }
    printf("\n");
    
    return;
}

void exibir(int numeros[quantidade], int quantidade)
{
    for(int i = 0;i<quantidade;i++)
    {
        printf("|%i",numeros[i]);
    }
    printf("|\n");
    
    return;
}

void ordenar(int numeros[quantidade], int quantidade)
{
    int temporario, mudancas;
    mudancas = 1;
    
    while(mudancas == 1)
    {
        mudancas = 0;
        for(int i = 0;i<quantidade;i++)
        {
            if(numeros[i] > numeros[i+1])
            {
                temporario = numeros[i];
                numeros[i] = numeros[i+1];
                numeros[i+1] = temporario; 
                mudancas = 1;
            }
        }
    }
    
    return;
}