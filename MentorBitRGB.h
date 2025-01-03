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

#ifndef MentorBitRGB_h
#define MentorBitRGB_h

#include <arduino.h>
#include <Adafruit_NeoPixel.h>
#include <MentorPort.h>

class MentorBitRGB : public MentorPort
{

    public:

        MentorBitRGB(uint8_t dint_pin = 0);
        void begin();
        void apagar();
        void cambiarColor(uint8_t rojo, uint8_t verde, uint8_t azul);
        void cambiarBrillo(uint8_t brillo);
        void configPort(const Port& port) override;

    private:

        Port _port;
        Adafruit_NeoPixel _led_rgb;

        void _reiniciarRGB();

};

#endif