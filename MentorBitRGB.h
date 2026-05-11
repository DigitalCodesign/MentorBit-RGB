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


    @author Digital Codesign
    @version 1.1.0
    @date Fecha de creación: Septiembre de 2024
    @date Fecha de versión: Mayo de 2026
    @see Repositorio: https://github.com/DigitalCodesign/MentorBit-RGB
    * @brief Descripción: 
        Esta librería está específicamente diseñada para ser utilizada junto con 
        el módulo MentorBit LED RGB (basado en el chip WS2812B/NeoPixel). 
        Ha sido completamente reescrita para eliminar dependencias externas pesadas 
        (Adafruit_NeoPixel), utilizando manipulación directa de puertos (bit-banging) 
        en lenguaje ensamblador para ATmega2560. Esto reduce drásticamente el peso 
        en memoria y elimina posibles fugas (memory leaks).
    * @details Métodos principales:
        - MentorBitRGB     -> Constructor de la clase.
        - begin            -> Inicializa los puertos de forma segura.
        - cambiarColor     -> Cambia el color del LED (mediante RGB o predefinidos).
        - cambiarBrillo    -> Ajusta la intensidad lumínica del LED.
        - apagar           -> Apaga completamente el LED.
    * Atributos (Enumeradores):
        - Color            -> Lista de colores básicos predefinidos (ROJO, VERDE, BLANCO, etc.)

*/

#ifndef MentorBitRGB_h
#define MentorBitRGB_h

#include <Arduino.h>
#include <MentorPort.h>

class MentorBitRGB : public MentorPort {

    public:

        enum Color { BLANCO, ROJO, VERDE, AZUL, AMARILLO, CIAN, MAGENTA, NEGRO };

        MentorBitRGB(uint8_t dint_pin = 0);

        void configPort(const Port& port) override;

        void begin();
        void cambiarColor(Color color);
        void cambiarColor(uint8_t rojo, uint8_t verde, uint8_t azul);
        void cambiarBrillo(uint8_t brillo);
        void apagar();

    private:

        Port _port;
        uint8_t _color_r, _color_g, _color_b;
        uint8_t _brillo;

        void _actualizarLED() const;

};

#endif