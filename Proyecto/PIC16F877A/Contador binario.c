/************************************************************************************************
Company:
Microside Technology Inc.
File Name:
Contador binario.c
Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/*
------------------------------------------------------------------------------------------
 Implementar un contador binario que incrementará cada vez que se presione un botón,
 este será configurado como entrada digital. Para visualizar el conteo se utilizan 8 LEDs.
------------------------------------------------------------------------------------------
*/

#include <16F877A.h>                  //Incluye el microcontrolador con el que se va a trabajar 
#use delay (clock=20Mhz, crystal )    //Tipo de oscilador y frecuencia dependiendo del microcontrolador 

#define Boton PIN_A2                  //Asigna el pin A2 al boton BOOT del X-TRAINER

byte cont = 0;
 
void main ( void ) {
   set_tris_b ( 0b00000000 );         //Configura todo el puerto B como salida
   set_tris_a ( 0b11111111 );         //Configura todo el puerto A como entrada

   while ( 1 ) {                      //Mientras sea verdadero se ejecuta el siguiente código
      if ( !input ( Boton ) ) {       //Si el botón está presionado
        cont++;                       //Se incrementa el contador
        output_b ( cont );            //Se asigna el valor del cont al puerto B y se despliega el valor
        Delay_ms ( 5 );               //Retardo
        while ( !input ( Boton ) );   //Mientras el botón se mantenga presionado
        Delay_ms ( 5 );               //Retardo
     }
   }
}
