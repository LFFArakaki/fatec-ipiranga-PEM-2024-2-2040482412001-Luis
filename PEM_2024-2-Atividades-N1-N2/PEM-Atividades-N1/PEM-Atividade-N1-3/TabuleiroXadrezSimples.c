#include <stdio.h>
#include <string.h>

//Disciplina: Programação Estruturada e Modular
//Prof. Carlos Veríssimo

//Objetivo do Programa: exibir um tabuleiro de xadrez
//Data - 29/08/2024
//Autor: Luis Fellipe Franco Arakaki

int main() {
    
    char linha1[50], linha2[50], linha3[50], linha4[50], linha5[50], linha6[50], linha7[50], linha8[50];
    char linha[50], index[50], indexINV[50];
    
    strcpy(linha1, "8|PT1|PC1|PB1|PD1|PR1|PB2|PC2|PT2|8");
    strcpy(linha2, "7|PP1|PP2|PP3|PP4|PP5|PP6|PP7|PP8|𝘓");
    strcpy(linha3, "6| X | X | X | X | X | X | X | X |9");
    strcpy(linha4, "5| X | X | X | X | X | X | X | X |S");
    strcpy(linha5, "4| X | X | X | X | X | X | X | X |߈");
    strcpy(linha6, "3| X | X | X | X | X | X | X | X |Ɛ");
    strcpy(linha7, "2|BP1|BP2|BP3|BP4|BP5|BP6|BP7|BP8|↊");
    strcpy(linha8, "1|BT1|BC1|BB1|BD1|BR1|BB2|BC2|BT2|⇂");
    strcpy(linha, " |-------------------------------| ");
    strcpy(index, "   a   b   c   d   e   f   g   h");
    strcpy(indexINV, "   ɐ   q   ɔ   p   ǝ   ɟ   ɓ   ɥ");
    
    printf("%s",indexINV);
    printf("\n%s",linha);
    printf("\n%s",linha1);
    printf("\n%s",linha);
    printf("\n%s",linha2);
    printf("\n%s",linha);
    printf("\n%s",linha3);
    printf("\n%s",linha);
    printf("\n%s",linha4);
    printf("\n%s",linha);
    printf("\n%s",linha5);
    printf("\n%s",linha);
    printf("\n%s",linha6);
    printf("\n%s",linha);
    printf("\n%s",linha7);
    printf("\n%s",linha);
    printf("\n%s",linha8);
    printf("\n%s",linha);
    printf("\n%s",index);


    return (0);
}