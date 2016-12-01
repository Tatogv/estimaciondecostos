#include "libraries.h"

/******************************************************
*  Plazo - Calcula el plazo y penalización de un pro- *
*          yecto de software.                         *
*  Parámetros:                                        *
*          Ninguno.                                   *
*                                                     *
*  Valor de retorno:                                  *
*    float pena = El tiempo total del proyecto.       *
*                                                     *
*  Autor: Miguel Izaguirre.                           *
*  Revisión y correcióLeonardo lopez.              *
*                                                     *
*******************************************************/

float Plataforma(void) {
  float plataforma=0;
  char opc;

  printf("\n\tPLATAFORMA.\n");
  do {
    printf("\n2.-La plataforma en la que vas a desarrollar el Sistema de Software es:\n");
    printf("A. C/C++\nB. Java\nC. Python\nD. Otro\n");
    scanf("%c",&opc);
    opc=toupper(opc);
    getchar();

    switch(opc) {
    case 'A':
      plataforma=P1;//$
      break;
    
    case 'B':
      plataforma=P2;//$
      break;

    case 'C':
      plataforma=P3;//$
      break;
    
    case 'D':
      plataforma=P4;//$
      break;
    
    default:
      printf("\nOpcion invalida. Vuelve a intentarlo.\n\n");
      break;
    }//switch
  
  }while((opc!='A')&&(opc!='B')&&(opc!='C')&&(opc!='D'));

  return plataforma;  
}//Plataforma

