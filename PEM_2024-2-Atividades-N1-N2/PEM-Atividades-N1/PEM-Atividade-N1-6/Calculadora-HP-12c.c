#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//Disciplina: Programação Estruturada e Modular
//Prof. Carlos Veríssimo

//Objetivo do Programa: calculadora utilizando RPN
//Data - 19/09/2024
//Autor: Luis Fellipe Franco Arakaki

#define TAMANHOPILHA 5
#define TAMANHOENTRADA 200

char entrada[TAMANHOENTRADA];
int contador;
float calculadora[TAMANHOPILHA];

void converter(char entrada[TAMANHOENTRADA]);
void soma();
void subtracao();
void multiplicacao();
void divisao();
void operacaoSeguida(int i);
void passarValor(float resultado);
void exibirPilha();
void verificaRepetir();

int main()
{
    printf("Insira uma expressão RPN\n");
    printf("Numeros devem estar separados por ';'\n");
    printf("Ex: '5;1;2+4*+3-'\n");
    scanf("%s",entrada);
	converter(entrada);
	if(contador>=TAMANHOPILHA)
    {
        return 0;
    }
    printf("\nRESULTADO FINAL: %.2f", calculadora[1]);
    verificaRepetir();

    return 0;
}

void converter(char entrada[TAMANHOENTRADA]){
    
    float convertido;
    int comprimento = strlen(entrada);
    
    for(int i=0;i<comprimento;i++)
    {
        if(isdigit(entrada[i]))
        {
		    convertido = convertido * 10 + ( entrada[i] - '0' );
        }
        else
        {
            contador++;
            if(contador>=TAMANHOPILHA)
            {
                printf("Expressão inválida!\n");
                return;
            }
            calculadora[contador] = convertido;
            convertido = 0;
            if(entrada[i] == '+')
            {
                exibirPilha();
                operacaoSeguida(i);
                soma();
            }
            if(entrada[i] == '-')
            {
                exibirPilha();
                operacaoSeguida(i);
                subtracao();
            }
            if(entrada[i] == '*')
            {
                exibirPilha();
                operacaoSeguida(i);
                multiplicacao();
            }
            if(entrada[i] == '/')
            {
		if(calculadora[contador] == 0)
		{
		   printf("Divisão por 0 não pode ocorrer!\n");
		   contador = 5;
		   return;
		}
                exibirPilha();
                operacaoSeguida(i);
                divisao();
            }
        }
	}
}

void soma(){
    
    float resultado;
    
    if(contador <= 1)
    {
        exibirPilha();
        return;
    }
    else
    {
        resultado = calculadora[contador-1] + calculadora[contador];
        passarValor(resultado);
        exibirPilha();
    }
}

void subtracao(){
    
    float resultado;
    
    if(contador <= 1)
    {
        calculadora[contador] = calculadora[contador] - 2*calculadora[contador];
        exibirPilha();
        return;
    }
    else
    {
        resultado = calculadora[contador-1] - calculadora[contador];
        passarValor(resultado);
        exibirPilha();
    }
}

void multiplicacao(){
    
    float resultado;
    
    if(contador <= 1)
    {
        calculadora[contador] = 0;
        exibirPilha();
        return;
    }
    else
    {
        resultado = calculadora[contador-1]*calculadora[contador];
        passarValor(resultado);
        exibirPilha();
    }
}

void divisao(){
    
    float resultado;

    if(contador <= 1)
    {
        calculadora[contador] = 0;
        exibirPilha();
        return;
    }
    else
    {
        resultado = calculadora[contador-1]/calculadora[contador];
        passarValor(resultado);
        exibirPilha();
    }
}

void operacaoSeguida(int i){
    
    if(isdigit(entrada[i-1]) == 0)
    {
        contador--;
    }
}

void passarValor(float resultado){
    
    calculadora[contador-1] = resultado;
    calculadora[contador] = 0;
    contador--;
}

void exibirPilha(){
    
    printf("\nPILHA:");
    for(int i=1;i<TAMANHOPILHA;i++)
    {
        printf("\n%.2f",calculadora[i]);
    }
    printf("\n");
}

void verificaRepetir(){
    
    int resposta;
    
    printf("\n\nDeseja inserir outra expressão RPN?\n");
    printf("(0=sim/1=nao)\n");
    scanf("%i",&resposta);
    if(resposta == 0)
    {
        contador = 0;
        main();
    }
    else
    {
        if(resposta != 1)
        {
            printf("\nPor favor insira uma resposta válida!");
            verificaRepetir();
        }
        else
        {
            printf("\nObrigado por usar nossa calculadora Fatec-HP12c");
            return;
        }
    }
    
}
