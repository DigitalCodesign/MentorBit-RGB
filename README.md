# MentorBitRGB

Librería para el control de un LED RGB mediante la librería Adafruit_NeoPixel en módulos compatibles con MentorBit.

## Descripción

La librería `MentorBitRGB` facilita el control de un LED RGB direccionable (compatible con la librería Adafruit_NeoPixel) en módulos compatibles con MentorBit. Permite cambiar el color del LED, ajustar su brillo y apagarlo por completo.

**Nota:** Esta librería depende de la librería `Adafruit_NeoPixel`. Asegúrate de que también esté instalada.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitRGB" e instálala.
    * **Nota:** Asegúrate de que la librería `Adafruit_NeoPixel` esté instalada.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitRGB.h>

    MentorBitRGB rgb(6); // LED RGB conectado al pin 6

    void setup() {
      rgb.begin(); // Inicializa el LED
    }

    void loop() {
      rgb.cambiarColor(255, 0, 0);   // Rojo
      delay(1000);
      rgb.cambiarColor(0, 255, 0);   // Verde
      delay(1000);
      rgb.cambiarColor(0, 0, 255);   // Azul
      delay(1000);
      rgb.cambiarBrillo(50);         // Brillo al 50%
      rgb.cambiarColor(255, 255, 0); // Amarillo (con brillo reducido)
      delay(1000);
      rgb.apagar();                  // Apaga el LED
      delay(1000);
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBitRGB(uint8_t dint_pin = 0)`: Crea un objeto `MentorBitRGB`.
    * `dint_pin`: Pin digital al que está conectado el LED RGB.

### Métodos

* `void begin()`: Inicializa el LED RGB.
* `void apagar()`: Apaga el LED RGB.
* `void cambiarColor(uint8_t rojo, uint8_t verde, uint8_t azul)`: Cambia el color del LED RGB.
    * `rojo`: Valor del componente rojo (0-255).
    * `verde`: Valor del componente verde (0-255).
    * `azul`: Valor del componente azul (0-255).
* `void cambiarBrillo(uint8_t brillo)`: Ajusta el brillo del LED RGB.
    * `brillo`: Valor del brillo (0-255).
