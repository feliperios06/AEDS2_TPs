#include <stdio.h>
#include <stdbool.h>

void somadigitos(int ent)
{
    int resp = 0;

    while(ent != 0){
        resp += ent % 10;
        ent = ent / 10;
    }

    printf("%d\n",resp);
}

int main()
{

    int ent;

    while (scanf("%d",&ent) != EOF)
    {

        somadigitos(ent);

    }

    return 0;
}
//Felipe de Faria Rios Coelho