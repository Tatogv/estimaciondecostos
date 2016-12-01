#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
int lang=0, bandera=0;

      

 while(bandera==0)
   {
 printf("Favor de digitar 1 si el lenguaje deseado es jav, 2 java script, 3 c, 4 c sharp\n"); 
     scanf("%i", &lang); 
     printf("lang %i\n, bandera %i\n",lang, bandera);   

 if(lang==1||lang==2||lang==3||lang==4)
     {
     printf("El valor ingresado  es valido\n"); 
     bandera=1; 
     }
  else
     {
       bandera=0; 
       printf("el valor no es correcto\n");
     }     
 }

printf("el valor es correcto\n");
}

