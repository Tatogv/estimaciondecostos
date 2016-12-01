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
*  Revisión y correción: Dante Bazaldua.              *
*                                                     *
*******************************************************/


float Plazo(void) {
  int plazo=0;
  float pena=0;//penalizacion por plazo
  char opc1, opc2;

  printf("\n\tPLAZO.\n");
  do {
    printf("\n1.-El plazo que tienes para desarrollar el Sistema de Software es:\n");
    printf("A. Fijo\nB. Variable\n");
    scanf("%c",&opc1);
    opc1=toupper(opc1);
    getchar();
    
    switch(opc1) {
    case 'A'://Plazo fijo
      do {
	printf("\nHay penalizacion al excederse del plazo establecido?\n");
	printf("A. No hay penalizacion\nB.Si hay penalizacion\n");
	scanf("%c",&opc2);
	opc2=toupper(opc2);
	getchar();

	if(opc2=='A') {//No hay penalizacion
	  pena=1.5;//$
	  do {
	    printf("\nEn cuantas semanas debe estar el Sistema de Software?\n");
	    scanf("%d",&plazo);
	    if(plazo<1) {
	      printf("\nNumero invalido. Vuelve a intentarlo.\n\n");
	    }
	  }while(plazo<1);
	}
	else if(opc2=='B') {//Hay penalizacion
	  pena=2.5;//$
	  do {
	    printf("\nEn cuantas semanas debe estar el Sistema de Software?\n");
	    scanf("%d",&plazo);
	    if(plazo<1) {
	      printf("\nNumero invalido. Vuelve a intentarlo.\n\n");
	    }
	  }while(plazo<1);
	}
	else {
	  printf("\nOpcion invalida. Vuelve a intentarlo.\n\n");
	}

      }while((opc2!='A')&&(opc2!='B'));
      break;

    case 'B'://Plazo variable
      do {
	printf("\nEn cuantas semanas debe estar el Sistema de Software?\n");
	scanf("%d",&plazo);
	if(plazo<1) {
	  printf("\nNumero invalido. Vuelve a intentarlo.\n\n");
	}
      }while(plazo<1);
      break;

    default:
      printf("\nOpcion invalida. Vuelve a intentarlo.\n\n");
      break;
    }//switch

  }while((opc1!='A')&&(opc1!='B'));

  pena=pena*plazo;//$
  return pena;
}//Plazo
