/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular           *
*          Prof. Carlos Veríssimo                         *
*---------------------------------------------------------*
* Objetivo do Programa: Refatorar e modularizar o código  *
*   ***PROGRAMA CODIFICADO DE FORMA MODULAR**             *          
* Data – 12/09/2024                                       * 
* Autor: Luis Fellipe Franco Arakaki                      *
*--------------------------------------------------------*/
#include <stdio.h>
// tabuleiro com as peças na posição inicial
char vetor[8][8] = {
    {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'}    };

void exibir();
void mover(int linhaDestino, int colunaDestino, int linhaPeca, int colunaPeca);
void jogada(int linhaDestino, int colunaDestino, int linhaPeca, int colunaPeca);

int main() {
printf("Tabuleiro inicial:\n");
exibir();
   
printf("Após jogada #1 das Brancas (Peão do Rei e2 para e4):\n");
jogada(4, 4, 6, 4);

printf("Após jogada #1 das Pretas (Peão do Rei e7 para e5):\n");
jogada(3, 4, 1, 4);

printf("Após jogada #2 das Brancas (Bispo do Rei f1 para c4):\n");
jogada(4, 2, 7, 5);

printf("Após jogada #2 das Pretas (Cavalo da Dama b8 para c6):\n");
jogada(2, 2, 0, 1);

printf("Após jogada #3 das Brancas (Dama d1 para h5):\n");
jogada(3, 7, 7, 3);

printf("Após jogada #3 das Pretas (Cavalo do Rei g8 para f6):\n");
jogada(2, 5, 0, 6);

printf("Após jogada #4 das Brancas (Dama h5 captura Peão f7 - Xeque Mate):\n");
jogada(1, 5, 3, 7);

return 0;
}

void exibir(){
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", vetor[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mover(int linhaDestino, int colunaDestino, int linhaPeca, int colunaPeca){
    
    vetor[linhaDestino][colunaDestino] = vetor[linhaPeca][colunaPeca];
    vetor[linhaPeca][colunaPeca] = '.';
}

void jogada (int linhaDestino, int colunaDestino, int linhaPeca, int colunaPeca){
    
    mover(linhaDestino, colunaDestino, linhaPeca, colunaPeca);
    exibir();
}