#include <stdio.h>
#include <stdbool.h>

int tamanho(char *ent){ //conta o tamanho
   int resp = 0;

   while(ent[resp] != '\0'){
         resp++;
   }
    return resp;
}

bool Devoler(char *ent){ // verifica se deve ler ou nao 
      return tamanho(ent) == 3 && ent[0] == 'F' && ent[1] == 'I' && ent[2] == 'M'; 
}

void cifra(char *ent, char *resp , int tam, int i){ //faz a cifra de forma recursiva 
   
    if(i < tam){

        resp[i] = (char)(ent[i] + 3);
        cifra(ent,resp,tam,i + 1);

    }else{
        resp[i] = '\0';
    }

}


int main(){
   char ent[1000];
   char resp[1000];
   int tam = 0;
   

   scanf(" %[^\n]", ent);

   while(!Devoler(ent)){
    
    tam = tamanho(ent);

    cifra(ent,resp,tam,0); // i sempre comeca em 0 

    printf("%s\n",resp);

    scanf(" %[^\n]", ent);
   }


    return 0;
}
//Felipe de Faria Rios Coelho