#include <stdio.h>
#include <time.h>

//Disciplina: Programação Estruturada e Modular
//Prof. Carlos Veríssimo

//Objetivo do Programa: implementar o algoritmo do "Bubble Sort"
//Data - 03/10/2024
//Autor: Luis Fellipe Franco Arakaki

int quantidade;

//Declaração de funções
void entrada(int numeros[quantidade], int quantidade);
void exibir(int numeros[quantidade], int quantidade);
void ordenar(int numeros[quantidade], int quantidade);

int main()
{
    quantidade = 60;
    
    //Define o array que será ordenado
    int numeros[60] = {
        5, 3, 8, 4, 2,
        115, 113, 118, 114, 112,
        125, 123, 128, 124, 122,
        35, 33, 38, 34, 32,
        45, 43, 48, 44, 42,
        55, 53, 58, 54, 52,
        65, 63, 68, 64, 62,
        75, 73, 78, 74, 72,
        85, 83, 88, 84, 82,
        95, 93, 98, 94, 92,
        15, 13, 18, 14, 12,
        25, 23, 28, 24, 22
    };
    
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    printf("Array inicial: ");
    exibir(numeros, quantidade);
    ordenar(numeros, quantidade-1);
    printf("Array ordenado: ");
    exibir(numeros, quantidade);
    
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}

void exibir(int numeros[quantidade], int quantidade)
{
    //Exibe os elementos do array
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
    
    //Comando a ser executado enquanto a variável 'mudancas' for igual a 1
    while(mudancas == 1)
    {
        //Define a variável 'mudancas' como 0, encerrando o loop 'while' caso não ocorra mudança de posição
        mudancas = 0;
        //Percorre os itens do array comparando os elementos adjacentes e 
        //colocando o menor na posição mais próxima do início e
        //o maior na posição mais próxima do fim
        for(int i = 0;i<quantidade;i++)
        {
            //Caso o número mais próximo do ínicio seja maior que o mais próximo do fim
            //realiza a mudança de posições no array
            if(numeros[i] > numeros[i+1])
            {
                //Utiliza a variavel 'temporario' para armazenar o valor do elemento maior
                temporario = numeros[i];
                //Joga o valor menor na posição mais próxima do início
                numeros[i] = numeros[i+1];
                //Joga o valor maior, armazenado na variavel 'temporario' para a posição mais próxima do fim
                numeros[i+1] = temporario; 
                //Define a variavel 'mudancas' como 1 para que o loop 'while' continue e o processo se repita
                //até que o array inteiro esteja organizado
                mudancas = 1;
            }
        }
    }
    
    return;
}