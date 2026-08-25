#include <stdio.h>
#include<stdbool.h>

int tamanho(char *ent){
	int resp = 0;
	int i = 0;
	while(ent[i] != '\0'){
          if(ent[i] != ' '){
           resp++;
	  }
           i++;
	}

return resp;
}

bool Devoler(char *ent){
return tamanho(ent) == 3 && ent[0] == 'F' && ent[1] == 'I' && ent[2] == 'M';
}

void verifica(char *ent){
 int tam = tamanho(ent);
 bool valida = true;
 char p1[100];
 char p2[100];
 int i , j = 0;

for(i = 0;i < (tam/2); i++){
       p1[j] = ent[i]; 
       j++;       
}

i++;

for(i;i != '\0';i++){
	p2[j] = ent[i];
        j++;
}

j++;
p2[j] = '\0';


for(int x = 0; x < tamanho(p1); x++){
    int z = 0 ;
    char tmp = p2[x];
    if(tmp == p1[z]){
       p2[x] = "";
       z++;
    }
}    
for(int y = 0 ; y < tamanho(p1); y++){
	if(p2[y] != ""){
		valida =  false;
	}
}

   if(valida){
   printf("SIM\n");
   }else{
   printf("NAO\n");
   }
}

int main(){

  char ent[200];
  scanf(" %[^\n]",ent);

   while(!Devoler(ent)){

     verifica(ent);
     scanf(" %[^\n]",ent);

   }

return 0;
}
