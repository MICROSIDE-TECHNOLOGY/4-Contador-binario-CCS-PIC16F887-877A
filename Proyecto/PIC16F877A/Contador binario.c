/*
  AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
  FECHA: JUNIO 2019
*/

/*
------------------------------------------------------------------------------------------
 Implementar un contador binario que incrementar� cada vez que se presione un bot�n,
 este ser� configurado como entrada digital. Para visualizar el conteo se utilizan 8 LEDs.
------------------------------------------------------------------------------------------
*/

#include <16F877A.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(clock=20Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 

#define Boton PIN_A2                            //Asigna el pin A2 al boton BOOT del X-TRAINER

byte cont =0;

void SisInit (void)

  {
    set_tris_b (0b00000000);                                      //Configura todo el puerto B como salida
    set_tris_a (0b11111111);                                      //Configura todo el puerto A como entrada
  }

 
void main(void)

  {

   SisInit ();

   while (1)                                                     //Mientras sea verdadero se ejecuta el siguiente c�digo

    {
     if (!input (Boton))                                         //Pregunta el estado del boton

      {
        cont++;                                                  //Se incrementa el contador
        output_b (cont);                                         //Se asigna el valor del cont al puerto B y se despliega el valor
        Delay_ms (5);                                            //Retardo
        while (!input (Boton));                                  //Mientras el bot�n se mantenga igual a cero
        Delay_ms (5);                                            //Retardo

     }

   }

}
