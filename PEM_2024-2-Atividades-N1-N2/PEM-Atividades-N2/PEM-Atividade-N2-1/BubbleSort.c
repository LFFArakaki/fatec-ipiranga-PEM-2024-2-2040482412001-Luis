#include <stdio.h>

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
    //Pede a entrada de quantos números o array terá
    printf("Digite quantos números quer ordenar:\n");
    scanf("%i",&quantidade);

    //Apresenta erro caso o número informado seja 1 ou menor
    //Pois não é possível ordenar 1 elemento de mais de uma forma e não é possível ter número de elementos negativos
    if(quantidade <= 1)
    {
        printf("\nQuantidade de números deve ser maior que 1\n\n");
        main();
    }
    printf("\n");
    
    //Define o array que será ordenado
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
    //Pede a entrada dos elementos do array
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