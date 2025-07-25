# MentorBitRGB
Esta librería está diseñada para que puedas controlar un LED de colores (RGB) de una forma muy sencilla usando tu placa MentorBit y el módulo de LED RGB.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del Módulo MentorBit de Luxómetro.](https://github.com/DigitalCodesign/MentorBit-RGB/blob/main/assets/RGB_Module.png)

Con esta librería, podrás iluminar tus proyectos con cualquier color que imagines, crear animaciones y dar un feedback visual muy llamativo.

## Descripción
### ¿Qué es un LED RGB?
Imagina un pequeño punto de luz que, en lugar de tener un solo color, contiene tres LEDs en uno: uno Rojo, uno Verde (Green) y uno Azul (Blue). Al mezclar la intensidad de estos tres colores primarios, puedes generar millones de colores diferentes. ¡Es como tener un pincel de luz mágico!

Este tipo de LED se conoce como "direccionable" o "NeoPixel", lo que significa que puedes controlarlo de forma precisa con muy pocos cables.

### ¿Qué hace esta librería?
La librería MentorBitRGB te da el control total sobre el LED de una manera muy intuitiva. Te permite "pintar" el LED del color que quieras, ajustar su intensidad y apagarlo, todo con comandos muy simples. Se encarga de la comunicación necesaria para que no tengas que preocuparte por la complejidad interna del LED.

### ¿Qué puedes construir con este LED?
- Una lámpara de ambiente que cambie de color según tu humor.
- Un indicador de estado: verde si todo va bien, rojo si hay un error, azul si está procesando.
- Un sistema de notificaciones personalizadas (por ejemplo, que parpadee en azul si recibes un mensaje).
- Efectos de luz decorativos para maquetas o para tu habitación.

Esta librería es el primer paso para integrar el control de iluminación inteligente en tus proyectos con MentorBit de una manera sencilla y profesional.

## Cómo empezar
Usar la librería es muy sencillo. Solo sigue estos pasos para tener tu LED brillando en pocos minutos.

1. **Conexión del Módulo**

Antes que nada, conecta tu módulo de sensor DHT11 a uno de los puertos ***Digitales de Entrada/Salida*** dentro de la zona de ***Puertos para Módulos*** en tu placa MentorBit. ¡Y listo! No necesitas más cables.

2. **Instalación de las Librerías**

Para que tu placa MentorBit pueda comunicarse con el LED, solo necesitas instalar una librería. El gestor del IDE de Arduino se encargará del resto.

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBitRGB*** y haz clic en "Instalar".
- El IDE detectará que esta librería necesita otra para funcionar y te preguntará si quieres instalarla también. Haz clic en "Install all" o "Instalar todo".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-RGB/blob/main/assets/library_instalation_example.png)

¡Y ya está! Con eso tienes todo lo necesario para empezar a programar.

## Ejemplo Básico: Ciclo de Colores

El siguiente código inicializa el LED y lo hace cambiar entre rojo, verde y azul, demostrando su funcionamiento básico.

### Copia y pega este código en tu IDE:

```c++
// 1. Incluimos la librería que acabamos de instalar.
#include <MentorBitRGB.h>

// Definimos el pin digital al que hemos conectado el módulo.
#define RGB_PIN 2

// 2. Creamos un objeto 'miLed' y le indicamos el pin que vamos a usar.
MentorBitRGB miLed(RGB_PIN);

void setup() {
    // 3. Inicializamos el LED. ¡Este paso es muy importante!
    miLed.begin();
    
    // Opcional: ajustamos el brillo para que no sea tan intenso (0-255).
    miLed.cambiarBrillo(50);
}

void loop() {
    // 4. Cambiamos el color a ROJO.
    // El formato es (Rojo, Verde, Azul), con valores de 0 a 255.
    miLed.cambiarColor(255, 0, 0);
    delay(1000); // Esperamos un segundo

    // Cambiamos el color a VERDE.
    miLed.cambiarColor(0, 255, 0);
    delay(1000); // Esperamos un segundo

    // Cambiamos el color a AZUL.
    miLed.cambiarColor(0, 0, 255);
    delay(1000); // Esperamos un segundo

    // Apagamos el LED antes de repetir el ciclo.
    miLed.apagar();
    delay(1000);
}
```

### Para ver el resultado:

1. Carga el código en tu placa MentorBit.
2. ¡Verás cómo tu LED RGB comienza a cambiar de color!

## Funciones Principales

Solo necesitas conocer estas sencillas funciones para controlar el sensor.

- <code>MentorBitRGB(uint8_t dint_pin)</code>
   - **¿Qué hace?** Es el constructor. Crea el objeto que te permitirá controlar el LED. Debes indicarle a qué pin digital de tu MentorBit has conectado el módulo.
   - **¿Cuándo se usa?** Al principio de tu código, antes del <code>setup()</code>, para declarar tu LED.

- <code>void begin()</code>
   - **¿Qué hace?** Inicializa la comunicación con el LED y lo prepara para recibir comandos.
   - **¿Cuándo se usa?** Debes llamarla siempre una única vez, dentro de la función <code>setup()</code>.

- <code>void cambiarColor(uint8_t rojo, uint8_t verde, uint8_t azul)</code>
   - **¿Qué hace?** Cambia el LED al color que especifiques. Cada componente de color (rojo, verde, azul) puede tener un valor entre 0 (apagado) y 255 (máxima intensidad).
   - **¿Cuándo se usa?** Cada vez que quieras establecer un color, normalmente dentro del <code>loop()</code>.

- <code>void cambiarBrillo(uint8_t brillo)</code>
   - **¿Qué hace?** Ajusta la intensidad o brillo general del LED, sin cambiar el color. Un valor de 0 es apagado y 255 es el brillo máximo.
   - **¿Cuándo se usa?** Normalmente una vez en el <code>setup()</code> para fijar un brillo general, o en cualquier momento que quieras atenuar o intensificar la luz.

- <code>void apagar()</code>
   - **¿Qué hace?** Apaga el LED por completo. Es un atajo para <code>cambiarColor(0, 0, 0)</code>.
   - **¿Cuándo se usa?** Cuando quieras apagar el LED.

## Recursos Adicionales

¿Quieres saber más sobre el módulo o necesitas comprar uno? Aquí tienes algunos enlaces que te serán de utilidad:

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial de MentorBit módulo de luz ambiental (BH1750)](https://canarias.digitalcodesign.com/shop/00040019-mentorbit-modulo-de-luz-ambiental-bh1750-8723)
- [Manual de usuario del MentorBit módulo de luz ambiental (BH1750)](https://drive.google.com/file/d/1Fyj9xgbW73O7kZXQNKaLQ3aaK3cpGDZH/view?usp=drive_link)
- [Modelo 3D de MentorBit módulo de luz ambiental (BH1750) en formato .STEP](https://drive.google.com/file/d/1ls4nBeFIT4mTYakK8VwrOEo9ZjGpJ4pV/view?usp=drive_link)
