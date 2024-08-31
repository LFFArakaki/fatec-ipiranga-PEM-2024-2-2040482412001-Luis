#include <stdio.h>
#include <string.h>

#define B "\e[47m"
#define P "\e[40m"
#define R "\e[0m"

//Disciplina: Programação Estruturada e Modular
//Prof. Carlos Veríssimo

//Objetivo do Programa: exibir um tabuleiro de xadrez
//Data - 29/08/2024
//Autor: Luis Fellipe Franco Arakaki

int main() {

    char reiP[20], reiB[20], damaP[20], damaB[20], cavaloP1[20], cavaloP2[20], cavaloB1[20], cavaloB2[20];
    char bispoP1[20], bispoP2[20], bispoB1[20], bispoB2[20], torreP1[20], torreP2[20], torreB1[20], torreB2[20];
    char peaoP1[20], peaoP2[20], peaoP3[20], peaoP4[20], peaoP5[20], peaoP6[20], peaoP7[20], peaoP8[20];
    char peaoB1[20], peaoB2[20], peaoB3[20], peaoB4[20], peaoB5[20], peaoB6[20], peaoB7[20], peaoB8[20];
    char borda0[16], borda1[16], borda2[16], borda3[16], borda4[16], borda5[16], borda6[16], borda7[16], borda8[16];
    char borda9[16], borda10[16], borda11[16], borda12[16], borda13[16], borda14[16], borda15[16], borda16[16], borda17[16];
    char vazio1[20], vazio2[20], linha[100], index[100], indexINV[100], espacoBranco[16], espacoPreto[16];
    int i;

    strcpy(borda0, R " |" );
    strcpy(borda17, R "|" );
    strcpy(borda1, R "8|" );
    strcpy(torreP1, B "  PT1  ");
    strcpy(cavaloP1, P "  PC1  ");
    strcpy(bispoP1, B "  PB1  ");
    strcpy(damaP, P "  PD1  ");
    strcpy(reiP, B "  PR1  ");
    strcpy(bispoP2, P "  PB2  ");
    strcpy(cavaloP2, B "  PC2  ");
    strcpy(torreP2, P "  PT2  ");
    strcpy(borda2, R "|8" );
    strcpy(borda3, R "7|" );
    strcpy(peaoP1, P "  PP1  ");
    strcpy(peaoP2, B "  PP2  ");
    strcpy(peaoP3, P "  PP3  ");
    strcpy(peaoP4, B "  PP4  ");
    strcpy(peaoP5, P "  PP5  ");
    strcpy(peaoP6, B "  PP6  ");
    strcpy(peaoP7, P "  PP7  ");
    strcpy(peaoP8, B "  PP8  ");
    strcpy(borda4, R "|𝘓" );
    strcpy(borda5, R "6|" );
    strcpy(vazio1, B "   X   " );
    strcpy(vazio2, P "   X   " );
    strcpy(borda6, R "|9" );
    strcpy(borda7, R "5|" );
    strcpy(borda8, R "|S");
    strcpy(borda9, R "4|" );
    strcpy(borda10, R "|߈" );
    strcpy(borda11, R "3|" );
    strcpy(borda12, R "|Ɛ" );
    strcpy(borda13, R "2|" );
    strcpy(peaoB1, B "  BP1  ");
    strcpy(peaoB2, P "  BP2  ");
    strcpy(peaoB3, B "  BP3  ");
    strcpy(peaoB4, P "  BP4  ");
    strcpy(peaoB5, B "  BP5  ");
    strcpy(peaoB6, P "  BP6  ");
    strcpy(peaoB7, B "  BP7  ");
    strcpy(peaoB8, P "  BP8  ");
    strcpy(borda14, R "|↊");
    strcpy(borda15, R "1|" );
    strcpy(torreB1, P "  BT1  ");
    strcpy(cavaloB1, B "  BC1  ");
    strcpy(bispoB1, P "  BB1  ");
    strcpy(damaB, B "  BD1  ");
    strcpy(reiB, P "  BR1  ");
    strcpy(bispoB2, B "  BB2  ");
    strcpy(cavaloB2, P "  BC2  ");
    strcpy(torreB2, B "  BT2  ");
    strcpy(borda16, R "|⇂" );
    strcpy(linha, R "  --------------------------------------------------------");
    strcpy(index, R "     a      b      c      d      e      f      g      h");
    strcpy(indexINV, R "     ɐ      q      ɔ      p      ǝ      ɟ      ɓ      ɥ");
    strcpy(espacoBranco, B "       ");
    strcpy(espacoPreto, P "       ");

    printf("\n%s",indexINV);
    printf("\n%s\n%s",linha, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoBranco, espacoPreto);
        }
    i=0;
    printf("%s\n%s%s%s%s%s%s%s%s%s%s\n%s",borda17, borda1, torreP1, cavaloP1, bispoP1, damaP, reiP, bispoP2, cavaloP2, torreP2, borda2, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoBranco, espacoPreto);
        }
    i=0;
    printf("%s\n%s",borda17, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoPreto, espacoBranco);
        }
    i=0;
    printf("%s\n%s%s%s%s%s%s%s%s%s%s\n%s",borda17, borda3, peaoP1, peaoP2, peaoP3, peaoP4, peaoP5, peaoP6, peaoP7, peaoP8, borda4, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoPreto, espacoBranco);
        }
    i=0;
    printf("%s\n%s",borda17, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoBranco, espacoPreto);
        }
    i=0;
    printf("%s\n%s%s%s%s%s%s%s%s%s%s\n%s",borda17, borda5, vazio1, vazio2, vazio1, vazio2, vazio1, vazio2, vazio1, vazio2, borda6, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoBranco, espacoPreto);
        }
    i=0;
    printf("%s\n%s",borda17, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoPreto, espacoBranco);
        }
    i=0;
    printf("%s\n%s%s%s%s%s%s%s%s%s%s\n%s",borda17, borda7, vazio2, vazio1, vazio2, vazio1, vazio2, vazio1, vazio2, vazio1, borda8, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoPreto, espacoBranco);
        }
    i=0;
    printf("%s\n%s",borda17, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoBranco, espacoPreto);
        }
    i=0;
    printf("%s\n%s%s%s%s%s%s%s%s%s%s\n%s",borda17, borda9, vazio1, vazio2, vazio1, vazio2, vazio1, vazio2, vazio1, vazio2, borda10, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoBranco, espacoPreto);
        }
    i=0;
    printf("%s\n%s",borda17, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoPreto, espacoBranco);
        }
    i=0;
    printf("%s\n%s%s%s%s%s%s%s%s%s%s\n%s",borda17, borda11, vazio2, vazio1, vazio2, vazio1, vazio2, vazio1, vazio2, vazio1, borda12, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoPreto, espacoBranco);
        }
    i=0;
    printf("%s\n%s",borda17, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoBranco, espacoPreto);
        }
    i=0;
    printf("%s\n%s%s%s%s%s%s%s%s%s%s\n%s",borda17, borda13, peaoB1, peaoB2, peaoB3, peaoB4, peaoB5, peaoB6, peaoB7, peaoB8, borda14, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoBranco, espacoPreto);
        }
    i=0;
    printf("%s\n%s",borda17, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoPreto, espacoBranco);
        }
    i=0;
    printf("%s\n%s%s%s%s%s%s%s%s%s%s\n%s", borda17, borda15, torreB1, cavaloB1, bispoB1, damaB, reiB, bispoB2, cavaloB2, torreB2, borda16, borda0);
    for(i=0;i<4;i++)
        {
            printf("%s%s",espacoPreto, espacoBranco);
        }
    i=0;
    printf("%s\n%s",borda17, linha);
    printf("\n%s\n",index);

    return (0);
}