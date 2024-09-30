/*


          ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗
          ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║
          ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║
          ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║
          ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗
          ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝

   ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
  ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
  ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
  ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
  ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
   ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝


  Autor: Digital Codesign
  Version: 1.0.0
  Fecha de creación: Septiembre de 2024
  Fecha de version: Septiembre de 2024
  Repositorio: https://github.com/DigitalCodesign/MentorBit-RGB
  Descripcion:
    Este sketch es un ejemplo de como cambiar aleatoriamente el color mostrado en el led 
    RGB en un corto intervalo de tiempo                                                                                                                 
*/

// Se incluye la libreria MentirBitRGB
#include <MentorBitRGB.h>

// Se define el pin al cual se va a conectar el led RGB
#define RGB_PIN 24

// Se crean las variables en donde se va a guardar el numero del color mostrado en el led
uint8_t rojo;
uint8_t verde;
uint8_t azul;

// Se crea el objeto led_rgb
MentorBitRGB led_rgb(RGB_PIN);

void setup(){
    // Se inicializa el led rgb
    led_rgb.begin();
}

void loop(){
    // Se asigna un valor aleatorio a las variables de los colores
    rojo = random(0,255);
    verde = random(0,255);
    azul = random(0,255);
    // Se enciende el led con los colores indicados
    led_rgb.cambiarColor(rojo, verde, azul);
    // Pequeño delay para ver el cambio de color
    delay(100);
}