#ifdef _WIN32
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "forca.h"
#include <stdlib.h>
#include <time.h>
#endif

char chutes[26];
int chutes_Dados = 0;
char palavraSecreta[TAMANHO_PALAVRA];

void ft_cabecalho(){
    printf("<----------------------------->\n");
    printf("|     Quem é esse Pokémon     |\n");
    printf("<----------------------------->\n");
}

char toUpperCase (char letra){
    return (letra >= 'a' && letra <= 'z') ? letra - 32 : letra;
}

void toUpperCaseString(char *str){
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toUpperCase(str[i]);
    }
}

void ft_chute(){
 char chute;
        printf("Qual a letra? ");
        scanf(" %c", &chute);

        chutes[chutes_Dados] = chute;
        chutes_Dados++;
        for (int i = 0; i < chutes_Dados; i++){
            chutes[i] = toUpperCase(chutes[i]);
        }
}

int ft_verificar_chute(char letra){
    int achou = 0;
        for (int j = 0; j < chutes_Dados; j++)
        {
            if (chutes[j] == letra)
            {
                achou = 1;
                break;
            }
        }
        return achou;
}

void ft_desenhar_forca(){
    int erros = ft_chutes_errados();

    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |     %c%c%c%c%c    \n", (erros >= 1 ? '(': ' '), (erros >= 1 ? '*': ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? '*': ' '), (erros >= 1 ? ')': ' '));
    printf(" |      %c%c%c   \n", (erros >= 3 ? '\\': ' '), (erros >= 2 ? '|': ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '), (erros >= 4 ? '\\' : ' '));
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    printf ("Você já deu %d chutes\n", chutes_Dados);

    for (int i = 0; i < strlen(palavraSecreta); i++)
    {
        if ('_' == palavraSecreta[i]){
            printf(" - ");
            continue;
        }
        
        int achou = ft_verificar_chute(palavraSecreta[i]);
        
        if (achou)
        {
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void ft_adicionar_palavra(){
    char quer;
    printf("Você quer adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);

    if (toUpperCase(quer) == 'S'){
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novaPalavra);
        toUpperCaseString(novaPalavra);
        
        FILE *f = fopen("palavras.txt", "r+");

        if (f == 0){
            printf("Desculpe, mas não foi possivel abrir o arquivo de palavras. \n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d\n", qtd);
        fseek(f, 0, SEEK_END);

        fprintf(f, "\n%s", novaPalavra);
        fclose(f);
        printf("A palavra %s foi adicionada com sucesso!\n\n", novaPalavra);
    }
}

void ft_escolher_palavra(){
 FILE *f = fopen("palavras.txt", "r");

 if (f == 0){
    printf("Desculpe, mas não foi possível abrir o arquivo de palavras.\n");
    exit(1);
 }

    int qtd_palavras;
    fscanf(f, "%d", &qtd_palavras);

    srand(time(0));
    int palavra_selecionada = rand() % qtd_palavras;

    for (int i = 0; i <= palavra_selecionada; i++){
        fscanf(f, "%s", palavraSecreta);
    }
    fclose(f);
}

int ft_acertou(){
    for (int i = 0; i < strlen(palavraSecreta); i++){
        if (palavraSecreta[i] == '_') continue; // Ignora espaços

        if(!ft_verificar_chute(palavraSecreta[i])){
            return 0; // Não acertou
        }
    }
    return 1; // Acertou
}

int ft_chutes_errados(){
    int erros = 0;
    for (int i = 0; i < chutes_Dados; i++) {
        int existe = 0;
        if (chutes[i] == '_') continue; // Ignora espaços
        for (int j = 0; j < strlen(palavraSecreta); j++) {
            if (palavraSecreta[j] == '_') continue; // Ignora espaços
            if (chutes[i] == palavraSecreta[j]) {
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros;
}

int ft_enforcou(){
    return ft_chutes_errados() >= 5;    
}

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    int enforcou = 0;
    ft_cabecalho();
    ft_escolher_palavra();

    do
    {
        ft_desenhar_forca();
        ft_chute(chutes, &chutes_Dados);
    } while (!ft_acertou() && !ft_enforcou());
    if (ft_acertou()){
        printf("\nParabéns, você ganhou!\n\n");
        printf("              ___________\n");
        printf("             '._==_==_=_.''\n");
        printf("             .-\\:      /-.\n");
        printf("            | (|:.  C  |) |\n");
        printf("             '-|:.     |-'\n");
        printf("               \\::.    /\n");
        printf("                '::. .'\n");
        printf("                  ) (\n");
        printf("                _.' '._\n");
        printf("               /________\\\n");
        printf("              /__________\\\n");
        printf("                 |    |\n");
        printf("              ___|____|___\n");
        printf("             /____________\\\n");
    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavraSecreta);
        printf("    _______________         \n");
        printf("   /               \\       \n");
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
    ft_adicionar_palavra();
}