#include <stdio.h>

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
  int ei, eo, eq, ilf, eif, tot=0, lang = 0, tipo = 0, opc, bandera;
  float ldc = 0, energia, meses, personas, total, fp, ufp = 0;
  
  system("clear");
  printf(" ----- Bienvenido al sistema de calculo del costo de un proyecto de software. ----- ");
  printf("\n\n    Este programa realiza el calculo de un sistema de software por medio de la utilizacion de Puntos de Funcion.\nPresione enter para continuar.\n");
  
  getchar();
 
  while(1){
 
    system("clear");

    printf(" ----- MENU PRINCIPAL ----- ");
    printf("\n\nPara seleccionar una opcion teclee el numero indicado y presione enter. Si desea modificar alguna seccion vuelva a seleccionar la opcion. Se necesitan haber llenado todos los campos antes de obtener el costo total del proyecto.\n");
    if(ufp == 0){
      printf("\n1. Calcular Puntos de Funcion.");
    }
    else{
      printf("\n1. Calcular Puntos de Funcion. ---------------> %.0f", ufp);
    }


    if(tot == 0){
      printf("\n2. Calcular complejidad.");
    }
    else{
      printf("\n2. Calcular complejidad. ---------------------> %d", tot);
      printf("\n     Puntos de Funcion ajustados: %.0f ", fp); 
    }


    if(lang == 0){
      printf("\n3. Seleccionar lenguaje de programacion.");
    }
    else if(lang == 1){
      printf("\n3. Seleccionar lenguaje de programacion. -----> Java");
    }
    else if(lang == 2){
      printf("\n3. Seleccionar lenguaje de programacion. -----> Javascript");
    }
    else if(lang == 3){
      printf("\n3. Seleccionar lenguaje de programacion. -----> C");
    }
    else if(lang == 4){
      printf("\n3. Seleccionar lenguaje de programacion. -----> C#");
    }
    if(lang != 0){
      ldc = func_ldc(fp, lang);
      printf("\n     Total de lineas de codigo estimadas: %.0f LDC", ldc);
    }


    if(tipo == 0){
      printf("\n4. Seleccionar el tipo de proyecto.");
    }
    else if(tipo == 1){
      printf("\n4. Seleccionar el tipo de proyecto. ----------> Organico");
    }
    else if(tipo == 2){
      printf("\n4. Seleccionar el tipo de proyecto. ----------> Medio");
    }
    else if(tipo == 3){
      printf("\n4. Seleccionar el tipo de proyecto. ----------> Embebido");
    }

    printf("\n5. Calcular costo total del proyecto.");

    printf("\n6. Salir.");

    printf("\n\nOPCION: ");

    scanf("%d", &opc);

    switch(opc){

    case 1:

      system("clear");
      printf("     Para calcular los Puntos de Funcion del programa conteste las siquientes preguntas:\n");
      printf("\n\n¿Cuantas entradas de usuario tiene el sistema?\n");
      scanf("%d", &ei);
      printf("\n¿Cuantas salidas de usuario tiene el sistema?\n");
      scanf("%d", &eo);
      printf("\n¿Cuantas peticiones de usuario tiene el sistema?\n");
      scanf("%d", &eq);
      printf("\n¿Cuantos archivos manejara el sistema?\n");
      scanf("%d", &ilf);
      printf("\n¿Cuantas cuantas interfaces externas manejara el sistema?\n");
      scanf("%d", &eif);
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

      energia = func_energia(tipo, ldc);

      break;

    case 6:

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
