/* 
Por: Oscar Henríquez
Fecha: Enero 2020
Version: 1.6
Notas: PEP3 ejercicio 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char const *argv[]) {

  /*
  La solución del problema se baso en casos, lo cuales se dividen en

  inconsistencia: Donde la suma de los valores de cada tripleta son distintos
  ejemplo: (1,2,3) y (2,1,1)

  única representación: las tripletas tiene una sola representación.

  varias representaciones: las tripletas tienen mas de una representación.

  */

  
  int a1, b1, c1, a2, b2, c2;
  printf("\nPor favor ingrese las dos tripletas.\n* Ejemplo de entrada: (1,2,1)(1,2,1):\n");
  scanf("(%d,%d,%d)(%d,%d,%d)", &a1, &b1, &c1, &a2, &b2, &c2);


  /*Solución dividida por casos*/
  /*Verificando inconsistencia en tripletas*/
  if ( (a1 + b1 + c1 != a2 + b2 + c2) || ( (a1 == 3 || b1 == 3 || c1 == 3 ) && (a2 == 0 || b2 == 0 || c2 == 0 )
         || (a1 == 0 || b1 == 0 || c1 == 0 ) && (a2 == 3 || b2 == 3 || c2 == 3 ))) {
     printf("Las tripletas no tienen representacion (inconsistencia).\n");
  }
  /*Caso 1: Tripletas pares*/
  else if (a1 == b1 && b1 == c1 && a2 == b2 && b2 == c2) {
    /*Caso 1.1: Las tripletas corresponden a los valores (3,3,3)(3,3,3)*/
    if ((a1 == a2 && a1 == 3) || (a1 == a2 && a1 == 0)){
      printf("Las tripletas tienen representacion unica.\n");
    }
    /*Caso 1.2: Las tripletas corresponden a los valores (2,2,2)(2,2,2), (1,1,1)(1,1,1), (0,0,0)(0,0,0)*/
    else {
       printf("Las tripletas no tienen representacion unica.\n");
    }
  }

  /*Caso 2: Tripletas descendientes o ascendientes*/
  else if ( ( (a1 > b1 && b1 > c1) && (a2 > b2 && b2 > c2) ) || ( (a1 < b1 && b1 < c1) && (a2 < b2 && b2 < c2) ) || ( ( (a1 > b1 && b1 > c1) && (a2 < b2 && b2 < c2) ) || ( (a1 < b1 && b1 < c1) && (a2 > b2 && b2 > c2) ) )) {
    printf("Las tripletas tienen representacion unica.\n");
  }

 /*Casos especiales:
La solución se basó por filtros, después de que las tripletas hayan pasado los filtros
quedan casos especiales, como los siguientes: */

  else if ( ( a1 + b1 + c1 == 3 ) && ( a2 == 3 || b2 == 3 || c2 == 3 ) ||
           ( a2 + b2 + c2 == 3 ) && ( a1 == 3 || b1 == 3 || c1 == 3 ) ) {
              printf("Las tripletas tienen representacion unica.\n");
           }
  /*Deducción, si en las dos tripletas la suma de sus valores es 2, inmediatamente las tripletas tienen
    representación única*/
  else if ( (a1 + b1 + c1 == 2 && a2 + b2 + c2 == 2 )  || (a1 + b1 + c1 == 1 && a2 + b2 + c2 == 1 ) ) {
      printf("Las tripletas tienen representacion unica.\n");
  }

    /*Deducción, la suma de las tripletas es igual a 5, si alguna de las tripletas
    tienen un cero las tripletas tiene representación única, no se pueden realizar combinaciones*/

  else if ( (a1 + b1 + c1 == 5 && a2 + b2 + c2 == 5 ) ) {
    if (!( ( a1 == 0 || b1 == 0 || c1 == 0 ) || ( a2 == 0 || b2 == 0 || c2 == 0 ) ))
      printf("Las tripletas no tienen representacion unica.\n");
    else {
      printf("Las tripletas tienen representacion unica.\n");

    }
  }
  /*último caso, si la resta absoluta de cada tripleta es igual a 1, entonces las tripletas tienen representación única*/
  
  else if (abs(a1 - b1 - c1) == 1 && abs(a2 - b2 - c2)) {
      printf("Las tripletas tienen representacion unica.\n");
  }
  else {
    printf("Las tripletas no tienen representacion unica. ");
  }

  return 0;
}
