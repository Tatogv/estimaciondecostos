#include "libraries.h"

/******************************************************
*  Lenguaje - A trav�s de una pregunta se determinan  *
*            los idiomas que tendría que manejar el  *
*            sistema.				      *						
*  Parámetros:                                        *
*          Ninguno.                                   *
*                                                     *
*  Valor de retorno:                                  *
*    float pena = El tiempo total del proyecto.       *
*                                                     *
*******************************************************/


float Lenguaje(void) {
  float lenguaje=0;
  char opc;

  printf("\n\tLENGUAJE.\n");
  do {
  printf("\n4.- Cuantos idiomas estaran disponibles para los usuarios?\n");
  printf("A. Un idioma\nB. Bilingue\nC. Trilingue\nD. Mas de 3 idiomas\n");
  scanf("%c",&opc);
  opc=toupper(opc);
  getchar();

  switch(opc) {
  case 'A':
    lenguaje=L1;//$
    break;
  case 'B':
    lenguaje=L2;//$
    break;
  case 'C':
    lenguaje=L3;//$
    break;
  case 'D':
    lenguaje=L4;//$
    break;
  default:
    printf("\nOpcion invalida. Vuelve a intentarlo.\n\n"); 
    break;
  }//switch
  
  }while((opc!='A')&&(opc!='B')&&(opc!='C')&&(opc!='D'));

  return lenguaje;  
}//Lenguaje
