#include <stdio.h>

int main()
{
    int i, n;
    float num, soma, menor, maior, nota, notaF;
    
    i = 0;
    menor = 11;
    maior = -1;
    
    for(i==0;i<5;i++)
    {
        printf("Insira o número de questões: ");
        scanf("%i",&n);
        if(n<=2)
        {
            i--;
            printf("É necessário ter no mínimo 3 questões.\n");
            continue;
        }
        for(n=n;n>0;n--)
        {
            printf("Insira as notas do candidato(uma por vez): ");
            scanf("%f",&num);
            if(num<0||num>10)
            {
                n++;
                printf("Por favor inserir uma nota válida");
                printf("\n(Entre 0 e 10)\n");
                continue;
            }
            else
            {
                if(num>maior)
                {
                    maior = num;
                }
                if(num<menor)
                {
                    menor = num;
                }
                soma = soma + num;
            }
        }
            nota = soma - menor - maior;
            notaF = notaF + nota;
            printf("Nota nessa categoria é = %.2f\n",nota);
            soma = 0;
            nota = 0;
            maior = -1;
            menor = 11;
    }
    printf("Nota final do candidato é = %.2f",notaF);

    return 0;
}