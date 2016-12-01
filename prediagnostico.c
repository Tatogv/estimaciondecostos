#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/******************************************************************************************************
 *Prediagnostico() La funcion despliega el menu con las variables necesarias para cotizar el sistema. *
 * @param void                                                                                        *
 * @return void                                                                                       *
 ******************************************************************************************************/
void Prediagnostico(void);

/*Funciones para Prediagnostico*/
extern float Plazo(void);//calcular el plazo
extern float Plataforma(void);//determinar el lenguaje
extern float Alcance(void);//determinar el numero de personas objetivo
extern float Lenguaje(void);//seleccionar el numero de idiomas
extern float Modulos(void);//preguntar la cantidad de modulos necesarios y el numero de lineas

void Prediagnostico(void) {
  struct pre {/*Estructura para guardar todas las variables necesarias*/
    float plazo;//cuantas semanas
    float plataforma;//en que lenguaje
    float alcance;//penetracion a los usuarios
    float lenguaje;//idiomas disponibles
    float modulos;//cantidad de modulos
    int programadores;//numero de programadores
    float total;//costo total del prediagnostico
  }pre;
  
  int i;//contador
  char opc;//leer la opcion
  /*Inicializar las variables de la estructura en 0*/
  pre.plazo=0;
  pre.plataforma=0;
  pre.alcance=0;
  pre.lenguaje=0;
  pre.modulos=0;
  pre.programadores=0;
  pre.total=0;
  
  system("clear");
  do {//inicio de do_while
    printf("\t\t\t PRE-DIAGNOSTICO\n");
    printf("A. Plazo\nB. Plataforma\nC. Alcance\nD. Lenguaje\nE. Modulos\nF. Miembros del equipo\nG. Cotizar Sistema de software\nH. Salir\n>:");
    scanf("%c",&opc);
    getchar();
    opc=toupper(opc);//pasarla a mayuscula

    switch(opc) {//inicio de switch
    case 'A'://Plazo
      system("clear");
      pre.plazo=Plazo();//llamar a la funcion
      printf("\npre.plazo=%.2f\n",pre.plazo);
      getchar();
      break;
      
    case 'B'://Pltaforma
      system("clear");
      pre.plataforma=Plataforma();//llamar a la funcion
      printf("\npre.plataforma=%.2f\n",pre.plataforma);
      break;

    case 'C'://Alcance
      system("clear");
      pre.alcance=Alcance();//llamar a la funcion
      printf("\npre.alcance=%.2f\n",pre.alcance);
      break;

    case 'D'://Lenguaje
      system("clear");
      pre.lenguaje=Lenguaje();//llamar a la funcion
      printf("\npre.lenguaje=%.2f\n",pre.lenguaje);
      break;

    case 'E'://Modulos
      system("clear");
      pre.modulos=Modulos();//llamar a la funcion
      printf("\npre.modulos=%.2f\n",pre.modulos);
      break;

    case 'F'://Miembros
      system("clear");
      printf("\n\tMIEMBROS DEL EQUIPO.\n");

      do {//inicio de do_while
	printf("\nAdemas del lider de proyecto, cuantos programadores desarrollan el Sistema de Software?\n");
	scanf("%d",&pre.programadores);
	if(pre.programadores<0) {
	  printf("\nNumero invalido. Vuelve a intentarlo.\n\n");
	}
      }while(pre.programadores<0);//No se cuenta el gestir, es decir, (pre.programadores +1)

      break;

    case 'G'://Cotizacion
      system("clear");
      pre.total=pre.plazo + pre.plataforma + pre.alcance + pre.lenguaje + pre.modulos;//costo total de los parametros del prediagnostico
      printf("\npre.total=%.2f\n",pre.total);
      break;

    case 'H'://Salida
      printf("\nSe ha salido del menu.\n");
      break;

    default://Cualquier otra opcion
      printf("\nOpcion invalida. Vuelve a intentarlo.\n\n");
      break;
    }//switch

  }while(opc!='H');
  
}//Prediagnostico

