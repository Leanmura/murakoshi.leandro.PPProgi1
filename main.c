#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*1. Dada una estructura ePais cuyos campos son id(int), nombre(20 caracteres), infectados(int), recuperados(int) y muertos(int).
Desarrollar una función llamada actualizarRecuperados que reciba el país y los recuperados del dia y que acumule estos a los que
ya tiene el país. La función no devuelve nada. *

2. Crear una función que se llame invertirCadena que reciba una cadena de caracteres como parámetro y su responsabilidad es invertir
los caracteres de la misma. Ejemplo si le pasamos UTN-FRA la deja como ARF-NTU *

3. Crear una función que se llame ordenarCaracteres que reciba una cadena de caracteres como parámetro y su responsabilidad es
ordenarlos caracteres de manera ascendente dentro de la cadena. Ejemplo si le pasamos "algoritmo" la deja como "agilmoort" */

typedef struct{
    int id;
    char nombre[20];
    int infectados;
    int recuperados;
    int muertos;
}ePais;

void actualizarRecuperados(ePais* pais, int recHoy);


void invertirCadena(char cadena[]);


void ordenarCaracteres(char cadena[]);


int main()
{
    ePais pais = {200, "Argentina", 300, 100, 100};
    actualizarRecuperados(&pais, 20);
    printf("%d\n\n", pais.recuperados);

    char cadena[] = {"LADadec"};
    invertirCadena(cadena);
    printf("%s", cadena);
    printf("\n\n");

    ordenarCaracteres(cadena);
    printf("%s", cadena);

    return 0;
}

void actualizarRecuperados(ePais *pais, int recHoy)
{
    (*pais).recuperados = (*pais).recuperados + recHoy;
}

void invertirCadena(char cadena[])
{
    char aux;
    int tam;
    tam = strlen(cadena);
    //printf("%d", tam);
    for(int i=1; i-1< tam/2; i++)
    {
        aux = cadena[i-1];
        cadena[i-1] = cadena[tam-i];
        cadena[tam-i] = aux;
    }
    /*for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam;j++)
        {
            aux = cadena[i];
            cadena[i]= cadena[j];
            cadena[j]=aux;
        }
    }*/

}

void ordenarCaracteres(char cadena[])
{
    int tam = strlen(cadena);
    char aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if((cadena[i]-cadena[j]) >0)
            {
               aux = cadena[i];
               cadena[i] = cadena[j];
               cadena[j] = aux;
            }
        }
    }
}
