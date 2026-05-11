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


#include <MentorBitRGB.h>

/**
 * @brief Constructor de la clase MentorBitRGB.
 * Prepara las variables internas y el pin de datos sin accionar el hardware todavía.
 * @param dint_pin Pin digital utilizado para enviar la señal de datos al LED (por defecto 0).
 */
MentorBitRGB::MentorBitRGB(uint8_t dint_pin)
    : _color_r(0), _color_g(0), _color_b(0), _brillo(255) {

    _port.gpios[1] = dint_pin;

}

/**
 * @brief Configura el puerto de hardware asociado al módulo.
 * Aplica los nuevos pines asignados y ejecuta una reinicialización segura 
 * llamando al método begin() internamente.
 * @param port Estructura constante por referencia con la configuración del puerto.
 */
void MentorBitRGB::configPort(const Port& port) {

    _port.type = port.type;
    _port.location = port.location;
    _port.gpios[0] = port.gpios[0];
    _port.gpios[1] = port.gpios[1];

    begin();

}

/**
 * @brief Inicializa el hardware del módulo.
 * Configura el pin digital como salida y emite una señal de apagado por seguridad 
 * para evitar destellos indeseados al arrancar el microcontrolador.
 * Debe llamarse dentro de la función setup() de Arduino.
 */
void MentorBitRGB::begin() {

    if (_port.gpios[1] > 0) {
        pinMode(_port.gpios[1], OUTPUT);
        digitalWrite(_port.gpios[1], LOW);
        apagar();
    }

}

/**
 * @brief Cambia el color del LED utilizando un color predefinido.
 * Método de conveniencia que traduce semánticamente un color a sus valores RGB.
 * @param color Etiqueta del enumerador Color (ej. ROJO, VERDE, AMARILLO).
 */
void MentorBitRGB::cambiarColor(Color color) {

    switch (color) {
        case BLANCO:   cambiarColor(255, 255, 255); break;
        case ROJO:     cambiarColor(255, 0, 0); break;
        case VERDE:    cambiarColor(0, 255, 0); break;
        case AZUL:     cambiarColor(0, 0, 255); break;
        case AMARILLO: cambiarColor(255, 255, 0); break;
        case CIAN:     cambiarColor(0, 255, 255); break;
        case MAGENTA:  cambiarColor(255, 0, 255); break;
        case NEGRO:    apagar(); break;
    }

}

/**
 * @brief Cambia el color del LED utilizando valores RGB personalizados.
 * Los valores se guardan en la memoria interna y se combinan con el brillo actual 
 * antes de ser enviados al hardware.
 * @param rojo Nivel de intensidad para el color rojo (0 - 255).
 * @param verde Nivel de intensidad para el color verde (0 - 255).
 * @param azul Nivel de intensidad para el color azul (0 - 255).
 */
void MentorBitRGB::cambiarColor(uint8_t rojo, uint8_t verde, uint8_t azul) {

    _color_r = rojo;
    _color_g = verde;
    _color_b = azul;
    _actualizarLED();

}

/**
 * @brief Ajusta la intensidad lumínica (brillo) general del LED.
 * Aplica una atenuación matemática a los colores actuales y refresca el LED 
 * inmediatamente sin necesidad de volver a enviar el comando de color.
 * @param brillo Nivel de brillo global deseado (0 - 255).
 */
void MentorBitRGB::cambiarBrillo(uint8_t brillo) {

    _brillo = brillo;
    _actualizarLED();

}

/**
 * @brief Apaga por completo el LED RGB.
 * Es un método de conveniencia equivalente a llamar a cambiarColor(0, 0, 0) o cambiarColor(NEGRO).
 */
void MentorBitRGB::apagar() {

    cambiarColor(0, 0, 0);

}

void MentorBitRGB::_actualizarLED() const {

    if (_port.gpios[1] == 0) return;

    uint8_t r = (_color_r * _brillo) / 255;
    uint8_t g = (_color_g * _brillo) / 255;
    uint8_t b = (_color_b * _brillo) / 255;

    uint8_t data [3] = { g, r, b };
    uint8_t bit_mask = digitalPinToBitMask(_port.gpios[1]);
    volatile uint8_t *port = portOutputRegister(digitalPinToPort(_port.gpios[1]));

    cli();

    for (uint8_t i = 0 ; i < 3 ; i ++) {

        uint8_t actual_byte = data[i];
        for (uint8_t bit = 0 ; bit < 8 ; bit++) {

            if (actual_byte & 0x80) {

                *port |= bit_mask;
                asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\n");
                *port &= ~bit_mask;
                asm volatile("nop\n");

            } else {

                *port |= bit_mask;
                asm volatile("nop\n");
                *port &= ~bit_mask;
                asm volatile("nop\nnop\nnop\nnop\nnop\nnop\nnop\n");

            }

            actual_byte <<= 1;

        }

    }

    sei();
    delayMicroseconds(50);

}
