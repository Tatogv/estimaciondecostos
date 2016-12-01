/*
 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

extern int Prediagnostico(void);
void Diagnostico(void);
/*Funciones Diagnostico*/


int main(int argc, char *argv[]) {
  char usuario[30], c;
  int i, miembros=0;
  
  system("clear");
  if(argc>1) {
    printf("Bienvenido %s!\n",argv[1]);
  }
  else {
    printf("Bienvenido Usuario!\n");
  }
  printf("Este programa te ayudara a saber, siguiendo ciertos parametros, a cuanto deberias cotizar tu Sistema de Software.\nEmpecemos...\n\n");
  
  do {
    printf("A: Continuar\nB:Salir\n");
    scanf("%c",&c);
    c=toupper(c);
    getchar();
    
    if(c=='A') {
      system("clear");

      miembros=Prediagnostico();//funcion
      
      for(i=0;i<=miembros;i++) {
	if(i==0) {
	  system("clear");
	  printf("\t\t\t DIAGNOSTICO PARA ADMINISTRADOR DEL EQUIPO\n");
	}
	else {
	  system("clear");
	  printf("\t\t\t DIAGNOSTICO PARA MIEMBRO %d\n",i);
	}
	Diagnostico();//funcion
      }//for
      
    }
    else if(c=='B') {
      system("clear");
      printf("Bye.\n");
      exit(1);
    }
    else {
      printf("\nOpcion invalida. Vuelve a intentarlo.\n\n");
    }
  }while(c!='A');
  
  return 0;
}//main


void Diagnostico(void) {

}
