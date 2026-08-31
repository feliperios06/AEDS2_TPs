#include <stdio.h>
#include <stdbool.h>

int tamanho(char *ent) // conta o tamnho da entrada ate o \0
{
    int resp = 0;
    while (ent[resp] != '\0')
    {
        resp++;
    }
    return resp;
}

bool Devoler(char *ent) // verifica se deve ou nao continuar lendo
{
    return tamanho(ent) == 3 && ent[0] == 'F' && ent[1] == 'I' && ent[2] == 'M';
}

void ordena(char *palavra) // ordeana a entrada para facilitar a ontagem
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

 
void contador(char *ent){  // conta os caracteres diferetes depois de ja ordenado
  int tam = tamanho(ent);
  int resp = 0;
  ordena(ent);

  for(int i = 0; i < tam; i++){
    if(ent[i]!= ent[i+1]){ // a cada caracter diferente conta 1 
       resp++;
    }
  }

  printf("%d\n",resp); // print da respostas
}


int main()
{

    char ent[200];
    scanf(" %[^\n]", ent);

    while (!Devoler(ent))
    {
        contador(ent);
        scanf(" %[^\n]", ent);
    }

    return 0;
}
//Felipe de Faria Rios Coelho