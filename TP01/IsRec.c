#include <stdio.h>
#include <stdbool.h>

int tamanho(char *ent)
{ // conta o tamnho da entrada
    int resp = 0;
    while (ent[resp] != '\0')
    {
        resp++;
    }
    return resp;
}

bool Devoler(char *ent) // verifica se deve ler ou nao
{ 
    int tam = tamanho(ent);
    return tam == 3 && ent[0] == 'F' && ent[1] == 'I' && ent[2] == 'M';
}

bool ehVogal(char c, const char *vog, int j) // verifica se um caractere é vogal para quando chega no \0
{ 
    return vog[j] != '\0' && (c == vog[j] || ehVogal(c, vog, j + 1));
}

bool SoVogais(const char *ent, int i) // percorre a string de entrada 
{ 
    return ent[i] == '\0' || (ehVogal(ent[i], "aeiouAEIOU", 0) && SoVogais(ent, i + 1));
}

bool ehConsoante(char c, const char *conso, int j) { // verifica recursivamente se o caractere é consoante 
    return conso[j] != '\0' && (c == conso[j] || ehConsoante(c, conso, j + 1));
}

bool SoConsoantes(const char *ent, int i) { // verifica se a string tem apenas consoantes 
    return ent[i] == '\0' ||(ehConsoante(ent[i], "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", 0)
                          && SoConsoantes(ent, i + 1));
}

bool ehDigito(char c, const char *dig, int j) { // verifica se um caractere é dígito 
    return dig[j] != '\0' && (c == dig[j] || ehDigito(c, dig, j + 1));
}

bool SoInt(const char *ent, int i) { // verifica se é inteiro 

    return ent[i] == '\0' ||((ehDigito(ent[i], "0123456789", 0)
                          || (i == 0 && (ent[i] == '-' || ent[i] == '+')))
                          && SoInt(ent, i + 1));
}

bool SoReal(const char *ent, int i, int pontos) { //verifica se é so int verifica se tem - ou +  na primeira posiçao
                                                  // e permite somente um ponto ou virgula 
    return ent[i] == '\0' ||
           ((ehDigito(ent[i], "0123456789", 0)
             || (i == 0 && (ent[i] == '-' || ent[i] == '+'))
             || ((ent[i] == '.' || ent[i] == ',') && pontos == 0))
            && SoReal(ent, i + 1,
                      pontos + ((ent[i] == '.' || ent[i] == ',') && pontos == 0)));
}

void Printresultados(bool resp[4]) { // funçao q print os resultados se for verdadeira as funçoes printa sim 
                                     //se for falso printa nao 
    printf("%s ", resp[0] ? "SIM" : "NAO");
    printf("%s ", resp[1] ? "SIM" : "NAO");
    printf("%s ", resp[2] ? "SIM" : "NAO");
    printf("%s\n", resp[3] ? "SIM" : "NAO");
}

int main()
{

    char ent[1000];

    scanf(" %[^\n]", ent);

    while (!Devoler(ent))
    {

        bool resp[4]; // cria 4 bools para cada funçao 

        resp[0] = SoVogais(ent, 0);
        resp[1] = SoConsoantes(ent, 0);
        resp[2] = SoInt(ent, 0);
        resp[3] = SoReal(ent, 0, 0);

        Printresultados(resp);

        scanf(" %[^\n]", ent);
    }

    return 0;
}