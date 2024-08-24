#include <stdio.h>

//Disciplina: Programação Estruturada e Modular
//Prof. Carlos Veríssimo

//Objetivo do Programa: calcular a bateria de testes realizada por um candidato
//Data - 23/08/2024
//Autor: Luis Fellipe Franco Arakaki

int main()
{
        //Declaração das variáveis a serem usadas no programa
        //(Exceto os arrays que serão usados para segurar as notas informadas, 
        //que dependem de outras variáveis para saberem quantos itens irão conter)
    int q, p;
    float menor, maior, nota, notaF, minNota, maxNota;
        
        //Pede ao usuário que informe o número de provas realizadas nessa bateria de testes
    printf("Digite quantas provas foram realizadas pelo candidato:\n");
    scanf("%i",&p);
        
    if(p<1)
    {
       printf("Pelo menos 1 prova deve ter sido realizada!\n");
       return(0);
    }
        
        //Começa um loop 'for' onde irá pedir os parâmetros de cada prova realizada
        //e calcular as notas para cada prova específica e a nota final do candidato
    for(p=p;p>0;p--)
    {
            //Pede ao usuário que informe quantas questões foram feitas na prova
            //Determinando assim quantas notas devem ser informadas
        printf("Digite quantas questões foram avaliadas na prova %i:\n",p);
        printf("(Mínimo de 3 questões)\n");
        scanf("%i",&q);
            
            //Apresenta uma mensagem de erro caso seja informado um número de questões menor que 3
        if(q<=2)
        {
            printf("Por favor digite um número válido de questões!");
            printf("\n(Mínimo de 3 questões)\n\n");
                
                //Adiciona 1 a variável 'p' para que o loop ainda aconteça o número de vezes correto
            p++;
                //Comando 'continue' reinicia o loop 'for' sem correr pelo resto das instruções
            continue;
        }
            //Caso o número de questões informado seja válido segue o programa
        else
        {
                //Define os arrays 'notas' e 'notasFinais', que irão armazenar respectivamente:
                //as notas de cada questão nessa prova específica e a nota final de cada uma das provas
                //O array 'notas' pode armazenar 'q' notas, sendo 'q' o número de questões informado pelo usuário
                //O array 'notasFinais' pode armazenar 'p' notas, sendo 'p' o número de provas informado pelo usuário
            float notas[q], notasFinais[p];
                
                //Pede ao usuário que defina a nota máxima e mínima que pode ser tirada nessa prova
                //(Necessário caso o critério mude de prova a prova)
            printf("Qual a maior nota possível de se tirar?\n");
            scanf("%f",&maxNota);
            printf("Qual a menor nota possível de se tirar?\n");
            scanf("%f",&minNota);
                
                //Apresenta mensagem de erro caso a variável 'minNota' seja maior que a variável 'maxNota'
            if(minNota>maxNota)
            {
                printf("A menor nota possível não pode ser maior que a maior nota possível\n\n");
                    //Adiciona 1 a variável 'p' para que o loop ainda aconteça o número de vezes correto
                p++;
                    //Comando 'continue' reinicia o loop 'for' sem correr pelo resto das instruções
                continue;
            }
                
                //Define as variáveis 'maior' e 'menor' que armazenarão os extremos, com base nos valores informados acima
            maior = minNota;
            menor = maxNota;
                
                //Pede ao usuário que informe as notas obtidas pelo candidato nessa prova
                //(Podem ser informadas todas na mesma linha separadas por espaço,
                //ou uma de cada vez, apertando enter após cada entrada)
            printf("Insira as notas obtidas pelo candidato:\n");
            printf("(Entre %.2f e %.2f)\n",minNota, maxNota);
            for(q=q;q>0;q--)
            {
                scanf("%f",&notas[q]);
                    
                    //Caso uma ou mais das notas informadas não se encaixe no intervalo definido pelo usuário,
                    //apresenta ao mesmo uma mensagem de erro avisando que uma nota inválida foi detectada e 
                    //pedindo para que seja informada uma nota válida para substituí-la
                if(notas[q] < minNota || notas[q] > maxNota)
                {
                    printf("Detectamos nota(s) inválida(s)!");
                    printf("\nPor favor insira uma nota válida para substituí-la!");
                    printf("\n(Entre %.2f e %.2f)\n\n",minNota, maxNota);
                        
                        //Soma 1 à variável 'q' para que o loop ainda aconteça o número de vezes correto
                    q++;
                        //Comando 'continue' reinicia o loop 'for' sem correr pelo resto das instruções
                    continue;
                }
                    //Caso a nota informada seja menor que a nota armazenada na variável 'menor'
                    //define essa nova nota como a menor nota informada
                    //(Sempre verdade na primeira rotação do loop, pois a variável 'menor' foi definida com base na nota máxima possível)
                if(menor>notas[q])
                {
                    menor = notas[q];
                }
                    //Caso a nota informada seja maior que a nota armazenada na variável 'maior'
                    //define essa nova nota como a maior nota informada
                    //(Sempre verdade na primeira rotação do loop, pois a variável 'maior' foi definida com base na nota mínima possível)
                if(maior<notas[q])
                {
                    maior = notas[q];
                }
                    //Soma todas as notas informadas pelo usuário para essa prova e as armazena na variável 'nota'
                nota += notas[q];
            }
                //Subtrai a menor e a maior nota, armazenadas em suas respectivas variáveis, da soma de todas as notas informadas,
                //armazenada na variável 'nota', obtendo assim a nota do candidato para essa prova excluindo os extremos
            nota = nota - menor - maior;
                //Informa ao usuário a nota obtida pelo candidato na prova indicada
            printf("Nota do candidato na prova %i = %.2f\n\n",p, nota);
                //Adiciona a nota obtida ao array 'notasFinais', onde ficaram armazenadas as notas de cada prova
            notasFinais[p] = nota;
                //Soma as notas de cada prova contidas no array 'notasFinais', obtendo assim a nota final do candidato
                //e a armazenando na variável 'notaF'
            notaF += notasFinais[p];
                //Reseta a variável 'nota' para que ela possa ser usada novamente para armazenar a nota da próxima prova
            nota = 0;
        }
    }
        //Informa ao usuário a nota final do candidato
    printf("Nota final do candidato = %.2f",notaF);
    
    return 0;
}