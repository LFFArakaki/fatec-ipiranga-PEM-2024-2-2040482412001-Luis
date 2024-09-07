#include <stdio.h>
#include <string.h>

#define PRETAS "\x1b[30m"
#define BRANCAS "\x1b[37m"
#define CLARO "\e[0;104m"
#define ESCURO "\e[44m"
#define R "\e[0m"
#define LINHAS 8
#define COLUNAS 8
#define CARACTERES 24

//Disciplina: Programação Estruturada e Modular
//Prof. Carlos Veríssimo

//Objetivo do Programa: exibir o "Mate Pastor" em um tabuleiro de xadrez
//Data - 03/09/2024
//Autor: Luis Fellipe Franco Arakaki

char tabuleiro[LINHAS][COLUNAS][CARACTERES] = { 
    {PRETAS "PT1", PRETAS "PC1", PRETAS "PB1", PRETAS "PD1", PRETAS "PR1", PRETAS "PB2", PRETAS "PC2", PRETAS "PT2"},
    {PRETAS "PP1", PRETAS "PP2", PRETAS "PP3", PRETAS "PP4", PRETAS "PP5", PRETAS "PP6", PRETAS "PP7", PRETAS "PP8"},
    {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
    {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
    {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
    {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
    {BRANCAS "BP1", BRANCAS "BP2", BRANCAS "BP3", BRANCAS "BP4", BRANCAS "BP5", BRANCAS "BP6", BRANCAS "BP7", BRANCAS "BP8"},
    {BRANCAS "BT1", BRANCAS "BC1", BRANCAS "BB1", BRANCAS "BD1", BRANCAS "BR1", BRANCAS "BB2", BRANCAS "BC2", BRANCAS "BT2"},
};
char* fundoClaro = CLARO;
char* fundoEscuro = ESCURO;
int i, j;

void Exibir(){
    
    char bordas[18][16] = {
        R " |", R "8|", R "|8", R "7|", R "|𝘓", R "6|", R "|9", R "5|", R "|S", 
        R "4|", R "|߈", R "3|", R "|Ɛ", R "2|", R "|↊", R "1|", R "|⇂", R "|"
    };
    char linha[100], index[100], indexINV[100], espacoBranco[16], espacoPreto[16];
    int cont, borda;
    
    strcpy(linha, R "  --------------------------------------------------------");
    strcpy(index, R "     a      b      c      d      e      f      g      h");
    strcpy(indexINV, R "     ɐ      q      ɔ      p      ǝ      ɟ      ɓ      ɥ");
    strcpy(espacoBranco, CLARO "       ");
    strcpy(espacoPreto, ESCURO "       ");
  
    printf("\n%s",indexINV);
    printf("\n%s",linha);
    for(i=0;i<LINHAS;i=i+2)
    {
        printf("\n%s",bordas[0]);
        for(cont=0;cont<4;cont++)
        {
            printf("%s%s",espacoBranco, espacoPreto);
        }
        cont=0;
        printf("%s\n%s",bordas[17], bordas[borda+1]);
        for(j=0;j<COLUNAS;j++)
        {
            if(j%2==0)
            {
                printf("%s  %s  ",fundoClaro, tabuleiro[i][j]);
            }
            else
            {
                printf("%s  %s  ",fundoEscuro, tabuleiro[i][j]);
            }
        }
        j=0;
        printf("%s\n%s",bordas[borda+2], bordas[0]);
        for(cont=0;cont<4;cont++)
        {
            printf("%s%s",espacoBranco, espacoPreto);
        }
        cont=0;
        printf("%s\n%s",bordas[17], bordas[0]);
        for(cont=0;cont<4;cont++)
        {
            printf("%s%s",espacoPreto, espacoBranco);
        }
        cont=0;
        printf("%s\n%s",bordas[17], bordas[borda+3]);
        for(j=0;j<COLUNAS;j++)
        {
            if(j%2==0)
            {
                printf("%s  %s  ",fundoEscuro, tabuleiro[i+1][j]);
            }
            else
            {
                printf("%s  %s  ",fundoClaro, tabuleiro[i+1][j]);
            }
        }
        j=0;
        printf("%s\n%s",bordas[borda+4], bordas[0]);
        for(cont=0;cont<4;cont++)
        {
            printf("%s%s",espacoPreto, espacoBranco);
        }
        cont=0;
        printf("%s",bordas[17]);
        borda = borda+4;
    }
    printf("\n%s", linha);
    printf("\n%s\n\n",index);
    i=0;
    j=0;
    cont=0;
    borda=0;
}

void Mover(char peça[CARACTERES], char destino[CARACTERES]){
    
    int comp;
    
    for(i=0;i<LINHAS;i++)
    {
        for(j=0;j<COLUNAS;j++)
        {
            comp = strcmp(tabuleiro[i][j], "...");
            if(comp == 0)
            {
                strcpy(tabuleiro[i][j], "   ");
            }
        }
    }
    strcpy(destino, peça);
    strcpy(peça, "...");
    Exibir();
    
}

int main() {
    
    Exibir();
    printf("\n                          JOGADA 1");
    printf("\nAs peças brancas iniciam o jogo movendo o peão de e2 para e4\n");
    Mover(tabuleiro[6][4], tabuleiro[4][4]);
    printf("\n   As peças pretas respondem movendo o peão de e7 para e5\n");
    Mover(tabuleiro[1][4], tabuleiro[3][4]);
    printf("\n                          JOGADA 2");
    printf("\nAs peças brancas movem o bispo de f1 para c4, atacando o peão\n");
    printf("                           em f7\n");
    Mover(tabuleiro[7][5], tabuleiro[4][2]);
    printf("\n  As peças pretas respondem movendo o cavalo de b8 para c6,\n");
    printf("                  defendendo o peão em e5\n");
    Mover(tabuleiro[0][1], tabuleiro[2][2]);
    printf("\n                          JOGADA 3");
    printf("\nAs peças brancas movem a dama de d1 para f3, atacando o peão\n");
    printf("                 em f7 e ameaçando xeque-mate\n");
    Mover(tabuleiro[7][3], tabuleiro[5][5]);
    printf("\nAs peças pretas não notam a ameaça de mate e movem o bispo de f8\n");
    printf("                          para c5\n");
    Mover(tabuleiro[0][5], tabuleiro[3][2]);
    printf("\n                          JOGADA 4");
    printf("\nAs peças brancas capturam o peão em f7 com a dama e ganham o jogo\n");
    Mover(tabuleiro[5][5], tabuleiro[1][5]);
    
    return (0);
}