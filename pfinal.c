/***********************************************************************
 * @author Miiguel Andres Izaguirre Valerio                            *
 * final.c                                                             *
 * @date Nov 30 2016                                                   *
 * En el main se da una breve descripcion del objetivo del programa.   *
 ***********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

extern void Prediagnostico(void);//Funcion para llevar al menu principal

int main(int argc, char *argv[]) {
  char c;//letra para leer la opcion del usuario
  
  system("clear");
  if(argc>1) {//opcion para ingresar el nombre del usuario
    printf("Bienvenido %s!\n",argv[1]);
  }
  else {
    printf("Bienvenido Usuario!\n");
  }
  printf("Este programa te ayudara a saber, siguiendo ciertos parametros, a cuanto deberias cotizar tu Sistema de Software.\nEmpecemos...\n\n");
  
  do {//inicio de ciclo do_while
    printf("A: Continuar\nB:Salir\n");
    scanf("%c",&c);//obtener la entrada
    c=toupper(c);//pasar a mayuscula
    getchar();
    
    if(c=='A') {
      system("clear");

      Prediagnostico();//llamar a funcion externa
      
    }
    else if(c=='B') {
      system("clear");
      printf("Bye.\n");
      exit(1);//salir del programa
    }
    else {
      printf("\nOpcion invalida. Vuelve a intentarlo.\n\n");
    }
  }while(c!='A');//hasta que se decida salir
  
  return 0;
}//main

