#include <stdio.h>
#include "funciones.c"

extern float func_ufp(int ei, int eo, int eq, int ilf, int eif);
extern float func_fp(float ufp, int tot);
extern float func_ldc(float fp, int lang);
extern float func_energia(int tipo, float ldc);
extern float func_meses(int tipo, float energia);
extern float func_personas(float energia, float meses);
extern float func_total(float personas, float meses, int lang);
extern int func_ask();//Funcion preguntas de factor ambiental

int main(void)
{
  int ei, eo, eq, ilf, eif, tot=-1, lang = 0, tipo = 0, opc, bandera;
  float ldc = 0, energia, meses, personas, total, fp, ufp = 0;

  system("clear");
  printf(" ----- Bienvenido al sistema de calculo del costo de un proyecto de software. ----- ");
  printf("\n\n    Este programa realiza el calculo de un sistema de software por medio de la utilizacion de Puntos de Funcion.\nPresione enter para continuar.\n");

  getchar();

  while(1){

    system("clear");
    printf(" ----- MENU PRINCIPAL ----- ");
    printf("\n\nPara seleccionar una opcion teclee el numero indicado y presione enter. Si desea modificar alguna seccion vuelva a seleccionar la opcion. Se necesitan haber llenado todos los campos antes de obtener el costo total del proyecto.\n");
    printf("\n1. Calcular Puntos de Funcion.");
    printf("\n2. Calcular complejidad.");
    printf("\n3. Seleccionar lenguaje de programacion.");
    printf("\n4. Seleccionar el tipo de proyecto.");
    printf("\n5. Salir.");

    printf("\n**************************************************");
    printf("\n            Informacion  Proporcionada            ");
    if(ufp != 0)
      printf("\n  Puntos de Funcion:           %.0f", ufp);
    if(tot != -1){
      printf("\n  Nivel de Complejidad:        %d", tot);
      printf("\n  Puntos de Funcion Ajustados: %.0f ", fp);
    }
    if(lang == 1)
      printf("\n  Lenguage de Programacion:    Java");
    else if(lang == 2)
      printf("\n  Lenguage de Programacion:    JavaScript");
    else if(lang == 3)
      printf("\n  Lenguage de Programacion:    C");
    else if(lang == 4)
      printf("\n  Lenguage de Programacion:    C#");
    if(lang != 0){
      ldc = func_ldc(fp, lang);
      printf("\n  Lineas de codigo estimadas:  %.0f LDC",ldc);
    }
    if(tipo == 1)
      printf("\n  Tipo de proyecto:            Organico");
    else if(tipo == 2)
      printf("\n  Tipo de proyecto:            Medio");
    else if(tipo == 3)
      printf("\n  Tipo de proyecto:            Embebido");
    if(tipo !=0 && ldc!=0){
      energia = func_energia(tipo, ldc);
      meses = func_meses(tipo, energia);
      personas = func_personas(energia, meses);
      total = func_total(personas, meses, lang);

      printf("\n**************************************************");
      printf("\n               Estimado del Proyecto              ");

      printf("\n  Duracion Estimada:           %.0f meses", meses);
      printf("\n  Numero de Personas:          %.0f personas", personas);
      printf("\n  Costo Total:                 $%.2f pesos.", total);
    }
    printf("\n\n$ ");

    scanf("%d", &opc);

    switch(opc){

    case 1:

      system("clear");
      printf("     Para calcular los Puntos de Funcion del programa conteste las siquientes preguntas:\n");
      printf("\n\n¿Cuantas entradas de usuario tiene el sistema?\n");
      scanf("%d", &ei);
      system("clear");
      printf("\n¿Cuantas salidas de usuario tiene el sistema?\n");
      scanf("%d", &eo);
      system("clear");
      printf("\n¿Cuantas peticiones de usuario tiene el sistema?\n");
      scanf("%d", &eq);
      system("clear");
      printf("\n¿Cuantos archivos manejara el sistema?\n");
      scanf("%d", &ilf);
      system("clear");
      printf("\n¿Cuantas cuantas interfaces externas manejara el sistema?\n");
      scanf("%d", &eif);
      system("clear");
      ufp = func_ufp(ei, eo, eq, ilf, eif);
      system("clear");
      printf("     Los puntos de funcion sin ajustar son: %.0f", ufp);
      getchar();
      getchar();

      break;

    case 2:

      tot=func_ask();

      fp = func_fp(ufp, tot);

      break;

    case 3:

      system("clear");
      bandera = 0;
      while(bandera==0)
	{
	  printf("  Por favor digite  el lenguaje deseado:\n\n1. Java.\n2. Javascript.\n3. C.\n4. C#.\n\nOPCION:  ");
	  scanf("%d", &lang);

	  if(lang==1||lang==2||lang==3||lang==4)
	    {
	      printf("El valor ingresado  es valido\n");
	      bandera=1;
	    }
	  else
	    {
	      bandera=0;
	      printf("La opcion ingresada no es valida. Por favor intente de nuevo.\n");
	    }
	}

    break;

    case 4:

      system("clear");

      printf("Ingrese el tipo del proytecto.\n\n1. Organico --> Equipos pequeños con buena experiencia trabajando en proyectos poco rigidos.\n2. Medio --> Equipos de tamaño medio trabajando en proyectos con requerimientos rigidos y poco rigidos combinados.\n3. Embebido --> proyectos con una gran cantidad de restricciones.\n\n");

      printf("OPCION: ");
      scanf("%d", &tipo);

      break;

    case 5:

      exit(0);

      break;

    default:

      system("clear");
      printf("Opcion invalida, por favor intente de nuevo.\n");
      getchar();
      getchar();
    }

  }

  return 0;
}
