#include <stdio.h>
#include <stdbool.h>

int tamanho(char *ent){
      int resp = 0;
    while(ent[resp] != '\0'){
        resp++;
    }
    return resp;
}

bool Devoler(char *ent){
    int tam = tamanho(ent);
   return tam == 3 && ent[0] == 'F' && ent[1] == 'I' && ent[2] == 'M';
}

void Invertida(char *ent){
   char resp[150];
  int j = 0;
   for(int i = tamanho(ent) - 1; i >= 0  ; i--){
    resp[j] = ent[i];
    j++;
   }
   resp[j] = '\0';
   
   printf("%s\n", resp);

}

int main(){

    char ent[150];

    scanf(" %[^\n]",ent);

while(!Devoler(ent)){

    Invertida(ent);
    scanf(" %[^\n]",ent);
}

    return 0;
}
//Felipe de Faria Rios Coelho