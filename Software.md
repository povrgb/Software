# Software

Varita de 8 LEDs RGB <3

Programas para controlar y generar secuencias de luces de la varita.
Aplicación para dibujar y crear diseños transferibles a las luces de la varita de 8 LEDs RGB. Se dibuja primero en processing donde se generan los datos que se importan en el código arduino para cargar y representar en la varita.

![alt text](https://github.com/povrgb/cosas/img/pasos_dibus.png)

Arduino
Aplicación que genera secuencias de encendido y apagado de luces con el objetivo de representar letras y diseños personalizados.
La aplicación trabaja mandando la data binaria en una configuración de enviar el byte de salida en un mismo instante utilizando el Port Register, utiliza el port D. Esto evita utilizar las funciones convencionales de Arduino para tener un manejo más preciso de los tiempos de encendido y apagado de las luces para poder generar bien los diseños cargados.
Data binaria se genera para el prender y apagar los LEds y a la vez se indica el color de la columna. Los colores son reducidos al RGB y combinaciones del mismo (rojo, verde, azul, cyan, magenta, amarillo, blanco).

Processing
Utiliza la librería Control P5.

V2 Las posibilidades de este software son para crear dibujos de dimensiones variables, el alto de los dibujos es de 8 pixeles condicionado por el hardware, pero con la posibilidad de ajustar el ancho de 7 a 36 columnas  (7 filas x X columnas).
Actualización realizada por la colaboración de Carlos Lescano.

V1 Las posibilidades de este software son para crear dibujos del tamaño de los caracteres (7 filas x 8 columnas). Se puede armar una nueva tipografía y reemplazar la que posee el código de arduino.

![alt text](https://github.com/povrgb/cosas/img/pasos_data.png)

Si necesitás ayuda para instalar estos programas podés ver el paso a paso en las presentaciones.
