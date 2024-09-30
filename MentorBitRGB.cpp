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
    Esta libreria esta especificamente diseñada para ser utilizada junto con
    el modulo de led RGB de MentorBit
  Metodos principales:
    MentorBitRGB -> constructor de la clase
    begin -> inicializador, debe colocarse en el setup
    apagar -> este metodo apaga el led RGB
    cambiarColor -> este metodo cambia el color del led RGB 
    cambiarBrillo -> este metodo permite ajustar el brillo del led RGB

*/


#include <MentorBitRGB.h>

/*
    Constructor, se debe indicar el pin al cual se esta conectando el modulo de led RGB
*/
MentorBitRGB::MentorBitRGB(uint8_t dint_pin):_led_rgb(1, dint_pin, NEO_GRB + NEO_KHZ800){
    _dint_pin = dint_pin;
}

/*
    Inicializador, debe colocarse en el setup. Inicializa las funciones basicas del modulo
*/
void MentorBitRGB::begin(){
    _led_rgb.begin();
}

/*
    Esta funcion permite apagar por completo el led RGB
*/
void MentorBitRGB::apagar(){
    _led_rgb.clear();
}

/*
    Esta funcion permite cambiar el color del led RGB. Recibe tres parametros de entrada.

    rojo (uint8_t)
    verde (uint8_t)
    azul (uint8_t)
*/
void MentorBitRGB::cambiarColor(uint8_t rojo, uint8_t verde, uint8_t azul){
    _led_rgb.setPixelColor(0, _led_rgb.Color(rojo, verde, azul));
    _led_rgb.show();
}

/*
    Esta funcion permite ajustar el brillo del led RGb (recibe variable tipo uint8_t)
*/
void MentorBitRGB::cambiarBrillo(uint8_t brillo){
    _led_rgb.setBrightness(brillo);
}

