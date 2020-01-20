/* 
Por: Oscar Henríquez
Fecha: Enero 2020
Version: 1.1
Notas: PEP3 ejercicio 2
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> /* Librería para variables de tipo booleana. */

char LETRAS[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char sopaLetras[10][10];

void crearSopa(){
  int i,j;

  for(i=0;i<10;i++)
    for(j=0;j<10;j++)
    sopaLetras[i][j]=LETRAS[rand()%26];
}

  void mostrarSopa(){
    int i,j;

    for(i=0;i<10;i++){
      for(j=0;j<10;j++)
        printf("%c ",sopaLetras[i][j]);
        printf("\n");
    }
  }

  bool comprobarPalabra(char *palabraBuscada, int posI, int posJ){
    bool comprobado = false; //Variable que se retorna para indicar si la palabra fue encontrada.
    char letra = palabraBuscada[1];  //Variable que va iterando su posición a medida que va encontrando las letras que conforman la palabra que se busca.
    int coincidencias = 1, k; //Variable que nos indica el número de coincidencias.
    int i = posI, j = posJ;
    int iPrev = i, jPrev = j; //Variables que sirven para no buscar en la posicion anterior


    for(k=0;k<3;k++) {
      /* busca arriba de la posición de la letra actual (i, j). */

      /* Se comprueba que sólo compare en posiciones validas de la sopa de letras,
         ademas de que no vuelva a comparar en una posición que ya ha comparado
         y que el número de coincidencias sea menor a cuatro (tamaño máxino de la palabra que se desea buscar). */

      if (i-1 >= 0 && i-1 != iPrev && coincidencias < 4) {

        /* Si la letra en la sopa de letras es igual a letra de la palabra que se esta buscando
           entonces se aumenta las coincidencias en uno, la letra a buscar se actualiza como también
           la posición actual de la letra (i, j) y de la posición previa (iPrev, jPrev). */


        if (sopaLetras[i-1][j] == letra) {
          coincidencias++;
          letra = palabraBuscada[coincidencias];
          iPrev = i;
          i--;
        }
      }

      /* busca a la derecha de la posición de la letra actual (i, j). */
      if (j+1 <= 9 && j+1 != jPrev && coincidencias < 4) {

        if (sopaLetras[i][j+1] == letra) {
          coincidencias++;
          letra = palabraBuscada[coincidencias];
          jPrev = j;
          j++;
        }
      }

      /* busca abajo de la posición de la letra actual (i, j). */
      if (i+1 <= 9 && i+1 != iPrev && coincidencias < 4) {

        if (sopaLetras[i+1][j] == letra) {
          coincidencias++;
          letra = palabraBuscada[coincidencias];
          iPrev = i;
          i++;
        }
      }

      /* busca a la izquierda de la posición de la letra actual (i, j). */
      if (j-1 >= 0 && j-1 != jPrev && coincidencias < 4) {

        if (sopaLetras[i][j-1] == letra) {
          coincidencias++;
          letra = palabraBuscada[coincidencias];
          jPrev = j;
          j--;
        }
      }
    }

    /* Si el número de coincidencias es igual a la longitud de la palabra entonces
       BINGO!! se da por exitosa la búsqueda. */
    if (coincidencias == 4)comprobado = true;

    return comprobado;
  }

  void buscarPalabra(char *palabraBuscada){
    char letra = palabraBuscada[0]; //Letra inicial de la palabra a buscar
    bool palabraEncontrada = false;
    int i,j;

    for(i=0;i<10;i++){
      for(j=0;j<10;j++){
                /* Si se encuentra una letra en la sopa de letras que coincida con la letra
           inicial de la palabra, se comprueba si esta forma la palabra completa
           en las posiciónes adyacentes a esta. */
        if (sopaLetras[i][j] == letra) {
                    /* Si se halla la palabra en la sopa de letras se fuerza i y j para salir
             del ciclo e indicar que la busqueda fue exitosa. */

          if(comprobarPalabra(palabraBuscada, i, j)){
            palabraEncontrada = true;
            i = 10;
            j = 10;
          }
        }
      }
    }
    /* se comprueba si la palabra fue encontrada y se muestra en pantalla
        el mensaje correspondiente. */
    if (palabraEncontrada) {
      printf("La palabra: %c%c%c%c fue encontrada en la sopa de letras\n\n", palabraBuscada[0],palabraBuscada[1],palabraBuscada[2],palabraBuscada[3]);
    }
    else{
      printf("La palabra: %c%c%c%c NO fue encontrada en la sopa de letras\n\n", palabraBuscada[0],palabraBuscada[1],palabraBuscada[2],palabraBuscada[3]);
    }

  }

  int main(){
    srand (time(NULL)); //Inicializa la funcion para generar numeros aleatorios
    crearSopa();
    char palabraBuscada[4]= {LETRAS[rand()%26],LETRAS[rand()%26],LETRAS[rand()%26],LETRAS[rand()%26]};
    printf("\nSopa de Letras\n");
    mostrarSopa();
    printf("\nLa palabra a buscar es: %c%c%c%c\n\n",palabraBuscada[0],palabraBuscada[1],palabraBuscada[2],palabraBuscada[3]);
    buscarPalabra(palabraBuscada); //Paso la palabra generada a mi fucnion

    return 0;
  }
