#include "libraries.h"

/******************************************************
*  Alcance - Permite tener una visión global del modo *
*            de desarrollo de los posibles sistemas   *
*            a desarrollar.                           *
*  Parámetros:                                        *
*          Ninguno.                                   *
*                                                     *
*  Valor de retorno:                                  *
*    float alcance = Una constante que evalua el      *
*          el alcance teniendo como referencia a      *
*          cantidad de personas entre 0 < x > 100 .   *
*                                                     *
*  Autor: Miguel Izaguirre.                           *
*  Revisión y correción: Dante Bazaldua.              *
*                                                     *
*******************************************************/


float Alcance(void) {
  float alcance=0;
  char opc1,opc2;

  printf("\n\tALCANCE.\n");
  do {
    printf("\n3.- El alcance que tendra tu Sistema de Software a los usuarios es de tipo:\n");
    printf("A. Stand-alone (una maquina)\nB. Compartido (en la red)\n");
    scanf("%c",&opc1);
    opc1=toupper(opc1);
    getchar();

    if(opc1=='A') {
      do {
	printf("\nPara cuantos usuarios (aprox.)?\n");
	printf("A. 1-50 usuarios\nB. 50-100 usuarios\nC. Mas de 100 usuarios\n");
	scanf("%c",&opc2);
	opc2=toupper(opc2);
	getchar();

	switch(opc2) {
	case 'A':
	  alcance=A1*1.5;//$
	  break;
	case 'B':
	  alcance=A1*2.5;//$
	  break;
	case 'C':
	  alcance=A1*3.5;//$
	  break;
	default:
	  printf("\nOpcion invalida. Vuelve a intentarlo.\n\n");
	  break;
	}//switch

      }while((opc2!='A')&&(opc2!='B')&&(opc2!='C'));
    }
    else if(opc1=='B') {
      do {
	printf("\nPara cuantos usuarios (aprox.)?\n");
	printf("A. 1-50 usuarios\nB. 50-100 usuarios\nC. Mas de 100 usuarios\n");
	scanf("%c",&opc2);
	opc2=toupper(opc2);
	getchar();

	switch(opc2) {
	case 'A':
	  alcance=A2*1.5;//$
	  break;
	case 'B':
	  alcance=A2*2.5;//$
	  break;
	case 'C':
	  alcance=A2*3.5;//$
	  break;
	default:
	  printf("\nOpcion invalida. Vuelve a intentarlo.\n\n");
	  break;
	}//switch

      }while((opc2!='A')&&(opc2!='B')&&(opc2!='C'));
    }
    else {
      printf("\nOpcion invalida. Vuelve a intentarlo.\n\n");
    }

  }while((opc1!='A')&&(opc1!='B'));

  return alcance;
}//Alcance
