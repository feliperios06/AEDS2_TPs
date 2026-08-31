#include <stdio.h>
#include <stdbool.h>

int tamanho(char *ent) // conta o tamnho da entrada tirando o espaço 
{
    int resp = 0;
    int i = 0;
    while (ent[i] != '\0')
    {
        if (ent[i] != ' ')
        {
            resp++;
        }
        i++;
    }

    return resp;
}

int tamanhoTotal(char *ent) //conta a entrada com o espaço
{
    int i = 0;
    while (ent[i] != '\0')
    {
        i++;
    }
    return i;
}

bool Devoler(char *ent) //veriifca se deve ler ou nao 
{
    return tamanho(ent) == 3 && ent[0] == 'F' && ent[1] == 'I' && ent[2] == 'M';
}

void ordenar(char *palavra)  // ordena as palavras tendo em vista q dividi ela em duas
{
    int tam = tamanho(palavra);

    for (int i = 0; i < tam; i++)
    {
        for (int j = i + 1; j < tam; j++)
        {
            if (palavra[i] > palavra[j])
            {
                char tmp = palavra[i];
                palavra[i] = palavra[j];
                palavra[j] = tmp;
            }
        }
    }
}

char minuscula(char c) // transforma os caracteres maiusculos em minusculos
{
    char tmp = c;
    if (c >= 'A' && c <= 'Z')
    {
        tmp = c + 32; 
    }
    return tmp;
}

void verifica(char *p1, char *p2) //verifica se sao anagramas ou nao fazendo a verificaçao de char por char ja q estao ordenados 
{ 

    bool valida = true;
    char palavra1[100];
    char palavra2[100];
    int i;

    for (i = 0; p1[i] != '\0'; i++) // passa as palavras para a funçao e depois ordena
    {
        palavra1[i] = minuscula(p1[i]);//entes de passar verifica se todos sao minusculas pra n dar erro  
    }
    palavra1[i] = '\0';

    for (i = 0; p2[i] != '\0'; i++)
    {
        palavra2[i] = minuscula(p2[i]);
    }
    palavra2[i] = '\0';

    ordenar(palavra1);
    ordenar(palavra2);

    if (tamanho(palavra1) == tamanho(palavra2))
    {
        for (int i = 0; i < tamanho(palavra1) && valida == true; i++)
        {
            if (palavra1[i] != palavra2[i])
            {
                valida = false;
            }
        }
    }
    else
    {
        valida = false;
    }

    if (valida) //printa as respostas tendo como base o valida  
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }
}

void separar(char *ent){ // funçao q separa a entrada em duas palavras
    int i, j = 0;
    char p1[100];
    char p2[100];

    for(i = 0; ent[i] != ' ' && ent[i] != '\0'; i++){
        p1[i] = ent[i];
    }
    p1[i] = '\0';

    if(ent[i] == ' '){
        i++;
    }

    for( ; ent[i] != '\0'; i++){
        p2[j] = ent[i];
        j++;
    }
    p2[j] = '\0';

    verifica(p1, p2);
}


int main()
{

    char ent[200];
    scanf(" %[^\n]", ent);

    while (!Devoler(ent))
    {
        separar(ent);
        scanf(" %[^\n]", ent);
    }

    return 0;
}
//Felipe de Faria Rios Coelho