# MentorBit-RGB
Esta librería está construida por Digital Codesign para utilizar el módulo de Led RGB, principalmente diseñado para el kit educacional "MentorBit".

Puedes encontrar nuestro MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

# Modo de empleo

Una vez tengamos la librería instalada desde el Arduino IDE, tenemos que incluir la librería con la siguiente línea:

``#include <MentorBitRGB.h>``


### Constructor

Una vez incluida la librería y definido el pin del zumbador, usamos el constructor para crear el objeto del zumbador, y empleamos el pin del zumbador que definimos anteriormente:

``MentorBitRGB led_rgb(PIN_RGB);``

Siendo PIN_RGB el pin de señal del módulo RGB.

### Uso

Con nuestro módulo led ya definido, tenemos que inicializar en el "void setup()" el módulo para que empiece a recibir información:

``led_rgb.begin();``

Una vez inicializado, podemos variar los valores de las variables rojo, verde y azul para que el led cambie de color con la siguiente función:

``led_rgb.cambiarColor(rojo, verde, azul);

Siendo rojo, verde y azul los valores digitales que se le envían al led RGB para que cambie de color.

A partir de aquí, podemos usar el código de ejemplo para crear alguna melodía, o el uso que se le quiera dar. 

