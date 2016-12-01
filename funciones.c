/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: Chemoso, Fernando, Cjaa92, Ricardo
 *
 * Created on 28 November 2016, 6:05 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PESO_EI  3
#define PESO_EO  4
#define PESO_EQ  3
#define PESO_ILF 7
#define PESO_EIF 7
#define JAVA_L   53
#define C_L      97
#define CSHARP_L 54
#define JAVASC_L 47
#define JAVA_S   28095
#define C_S      27143
#define CSHARP_S 24571
#define JAVASC_S 27375

/*
 *
 */
float func_ufp(int ei, int eo, int eq, int ilf, int eif);
float func_fp(float ufp, int total);
float func_ldc(float fp, int lang);
float func_energia(int tipo, float ldc);
float func_meses(int tipo, float energia);
float func_personas(float energia, float meses);
float func_total(float personas, float meses, int lang);
int func_ask();


/*int main(int argc, char** argv) {
    float ldc,tipo=1,lang=1,energia,meses,personas,total;
    int fp, ufp;
    ufp = func_ufp(4,4,3,4,0);
    fp = func_fp(ufp, 43);
    ldc = func_ldc(fp,lang);
    energia = func_energia(tipo,ldc);
    meses = func_meses(tipo, energia);
    personas = func_personas(energia, meses);
    total = func_total(personas, meses, lang);
    printf("%.2f",total);

    return (EXIT_SUCCESS);
    }*/

float func_ufp(int ei, int eo, int eq, int ilf, int eif)
{
    return((ei*PESO_EI)+(eo*PESO_EO)+(eq*PESO_EQ)+(ilf*PESO_ILF)+(eif*PESO_EIF));
}

float func_fp(float ufp, int total)
{
    float caf;
    caf = (.65+(.01*total));
    return(round(ufp)*caf);

}

float func_ldc(float fp, int lang)//lang = lenguaje, 1 == java, 2 == javascript, 3 == c, 4 == c#
{
    if(lang == 1)
    {
        return(round(fp)*JAVA_L);
    }
    if(lang == 2)
    {
        return(round(fp)*JAVASC_L);
    }
    if(lang == 3)
    {
        return(round(fp)*C_L);
    }
    if(lang == 4)
    {
        return(round(fp)*CSHARP_L);
    }
}

float func_energia(int tipo, float ldc)
{
    float a,b;
    ldc=round(ldc)/1000;
    if(tipo == 1)//organico
    {
        a = 2.4;
        b = 1.05;
        return(a*(pow(ldc,b)));
    }
    if(tipo == 2)//medio
    {
        a = 3;
        b = 1.12;
        return(a*(pow(ldc,b)));
    }
    if(tipo == 3)//organico
    {
        a = 3.6;
        b = 1.2;
        return(a*(pow(ldc,b)));
    }
}


float func_meses(int tipo, float energia)
{
    float c,d;
    if(tipo == 1)//organico
    {
        c = 2.5;
        d = .38;
        return(c*(pow(energia,d)));
    }
    if(tipo == 2)//medio
    {
        c = 2.5;
        d = .35;
        return(c*(pow(energia,d)));
    }
    if(tipo == 3)//organico
    {
        c = 2.5;
        d = .32;
        return(c*(pow(energia,d)));
    }
}

float func_personas(float energia, float meses)
{
    return(energia/meses);
}


float func_total(float personas, float meses, int lang)
{
    if(lang == 1)
    {
        //printf("%.2f, %.2f",personas,meses);
        return(round(personas)*round(meses)*JAVA_S);
    }
    if(lang == 2)
    {
        return(round(personas)*round(meses)*JAVASC_S);
    }
    if(lang == 3)
    {
        return(round(personas)*round(meses)*C_S);
    }
    if(lang == 4)
    {
        return(round(personas)*round(meses)*CSHARP_S);
    }
}

int func_ask() {//Retorna el total de la suma elegida por los usuarios en respuesta a las preguntas
  int i,valor,error=0;
  int total=0;
  char Pregunta[15][91];



  strcpy(Pregunta[0],"¿Se requiere comunicacion de datos?");
  strcpy(Pregunta[1],"¿Existen funciones o procesos distribuidos?");
  strcpy(Pregunta[2],"¿Es critico el rendimiento?");
  strcpy(Pregunta[3],"¿Se ejecutara el sistema en un entorno operativo fuerte y existente fuertemente utilizado?");
  strcpy(Pregunta[4],"¿El sistema tendra una carga transaccional alta o baja?");
  strcpy(Pregunta[5],"¿Se requiere comunicacion de datos?");
  strcpy(Pregunta[6],"Nivel de disponibilidad");
  strcpy(Pregunta[7],"Eficiencia de usuario final requerida");
  strcpy(Pregunta[8],"Actualizacion en linea");
  strcpy(Pregunta[9],"Complejidad de procesamiento");
  strcpy(Pregunta[10],"¿Sistema debe estar diseñado e implantado para ser reutilizable?");
  strcpy(Pregunta[11],"¿Se requiere que este diseñado para ser facil de instalar y portar?");
  strcpy(Pregunta[12],"Facilidad de uso");
  strcpy(Pregunta[13],"¿Soportar multiples instalaciones");
  strcpy(Pregunta[14],"¿Diseñado para facilitar cambios?");

  for (i = 0; i <= 14; i++) {
    do{
      system("clear");
      printf("Utilizando numeros del 0 al 5.\nResponde la pregunta:\n%s\n",Pregunta[i]);
      scanf("%d",&valor);
      if ((valor>5)||(valor<0)) {
	       printf("Intenta de nuevo\n");
	       error=1;
      }else{
	       total=total+valor;
	       error=0;
      }
    }while(error==1);
    valor=0;
  }
  return total;
}
