/*
 POV RGB - Flavia Laudado Nicolas Restbergs 
 _ Mayo 2022
 
 Dibujar en una cuadrícula
 exportar los datos en un array 
 y guardar cada dibujo
 
 Dibujos presentados con una varita POV
 
 //CONTROLES//
 click izq -> pintar
 click der -> borrar
 1-7 -> colorear columnas
 enter -> guardar img y array de datos
 barra -> limpia la pantalla
 
 */

import controlP5.*;
ControlP5 cp5;

float xTexto = 100;
float yTexto = 100;
float espaciado = 40;
String consigna = "Nombre de archivo:"; 
boolean guardado = false;
String nombre, nombreArchivo;
char charNombre = 97;
PImage plaquita;

int columnas = 7; //división en horizontal
int filas = 8; //división en vertical, correspondiente a 8 LEDs
int anchoPixel, altoPixel;
int nH, nV;
color pixel;
int[][] arrayBits = new int[columnas][filas];
int[][] arrayBitsAnterior = new int[columnas][filas];
boolean huboCambios;

color colorRGB = color(255);
PImage imgOut;
int contadorColor = 0;
int nColores = 8; // del 1-7
color color1;
int colorColumna[] = { 0, 0, 0, 0, 0, 0, 0};
int colorColumnaAnterior[] = { 0, 0, 0, 0, 0, 0, 0};

PrintWriter output;
int contador = 0;
int tiempoRef = 0;
int intervalo = 7;
boolean flash = false;
boolean p = true;

void setup() {
  //tamaño del lienzo
  //acomodar a la pantalla, conservar la proporción
  size(525, 600);
  //size(700, 800);
  background(0);

  imgOut = createImage(width, height, ALPHA); 
  //inicializacion cuadricula
  anchoPixel = width/columnas;
  altoPixel = height/filas;
  inicializarArray();

  plaquita = loadImage("heart0.jpg");
  image(plaquita, 375, 200);

  inicializarTexto();
}

void draw() {
  if (flash == false) {
    if (guardado) {
      dibujar();
      cuadricula();
    }
  } else {
    flash();
  }
}

void inicializarTexto() {
  cp5 = new ControlP5(this);

  PFont font = createFont("calibri", 20);

  cp5.addTextfield("input")
    .setPosition(xTexto, yTexto + espaciado)
    .setSize(200, 40)
    .setFont(font)
    .setFocus(true)
    .setColor(color(255))
    .setAutoClear(false)
    .setLabel(" ")
    ;

  cp5.addBang("Guardar")
    .setPosition( xTexto, yTexto + espaciado * 3)
    .setSize(50, 40)
    .getCaptionLabel().align(ControlP5.CENTER, ControlP5.CENTER)
    ;

  textFont(font);

  fill(255);
  text("POV RGB para dibujar", xTexto - espaciado, yTexto - espaciado);
  text("Nombre de archivo:", xTexto, yTexto);

  int yTextoCon = 330;
  text("CONTROLES", xTexto - espaciado, yTextoCon);
  text("click izq -> pintar", xTexto, yTextoCon + espaciado);
  text("click der -> borrar", xTexto, yTextoCon + espaciado *2);
  text("1-7 -> colorear columnas", xTexto, yTextoCon + espaciado *3);
  text("enter -> guardar img y array de datos", xTexto, yTextoCon + espaciado *4);
  text("barra -> limpia la pantalla", xTexto, yTextoCon + espaciado *5);
}

void inicializarArray() {
  for (int i = 0; i < columnas; i++) {
    for (int j = 0; j < filas; j++) {
      arrayBits[i][j] = 0;
    }
  }
  arrayCopy(arrayBits, arrayBitsAnterior);
  huboCambios = true;
}

public void controlEvent(ControlEvent theEvent) {
  if (theEvent.getController().getName().equals("Guardar")) {
    enviarTexto();
  }
}

void enviarTexto() {
  nombre = cp5.get(Textfield.class, "input").getText();
  cp5.get(Textfield.class, "input").clear();
  nombreArchivo = nombre + ".txt";
  output = createWriter(nombreArchivo);
  guardado = true;
  cp5.remove("input");
  cp5.remove("Guardar");
  background(0);
  tiempoRef = frameCount;
  flash = true;
}

void cuadricula() {
  stroke(127);
  for (int i = 0; i <= columnas; i++) {
    int xcol = anchoPixel * i;
    line(xcol, 0, xcol, height);
  }

  for (int i = 0; i <= filas; i++) {
    int yFilas = altoPixel * i;
    line(0, yFilas, width, yFilas);
  }
  nDibujos();
}

void dibujar() { //dibuja en cada cuadrante que se hace click
  if (mousePressed == true) {
    huboCambios = true;
    nH = int(constrain(mouseX/anchoPixel, 0, columnas - 1));
    nV = int(constrain(mouseY/altoPixel, 0, filas - 1));
    if (mouseButton == LEFT) { 
      fill(1);
      arrayBits[int(nH)][int(nV)] = 1;
      if (colorColumna[nH] == 0) {
        colorColumna[nH] = 1;
      }
    } else if (mouseButton == RIGHT) {
      fill(0);
      arrayBits[nH][nV] = 0;
      rect(nH * anchoPixel, nV * altoPixel, anchoPixel, altoPixel);
      if (columnaActiva(nH) == false) {
        colorColumna[nH] = 0;
      }
    }
    colorear();
  }
}

void colorear() {
  for (int i = 0; i < columnas; i++) {
    color1 = elegirColor(colorColumna[i]);//tomo el color de la columna
    for (int j = 0; j < filas; j++) {//recorro todas las filas de esa columna
      if (arrayBits[i][j] != 0) {//si hay pixel activo
        fill(color1);//pinto de ese color
        rect(i * anchoPixel, j * altoPixel, anchoPixel, altoPixel);
      } else {
        fill(0);//pinto los cuadrados no activos de negro
        rect(i * anchoPixel, j * altoPixel, anchoPixel, altoPixel);
      }
    }
  }
}

color elegirColor(int codColor) {
  color _color1 = color(255);
  if (codColor == 0) {
    _color1 = color(0, 0, 0);
  } 
  if (codColor == 1) {
    _color1 = color(255, 255, 255);
  } 
  if (codColor == 2) {
    _color1 = color(255, 0, 0);
  }
  if (codColor == 3) {
    _color1 = color(0, 255, 0);
  }
  if (codColor == 4) {
    _color1 = color(0, 0, 255);
  }
  if (codColor == 5) {
    _color1 = color(0, 255, 255);
  }
  if (codColor == 6) {
    _color1 = color(255, 0, 255);
  }
  if (codColor == 7) {
    _color1 = color(255, 255, 0);
  }
  return _color1;
}

void actualizarColorColumna(int tecla) {
  colorColumna[tecla]++;
  if (colorColumna[tecla] >= nColores) {
    colorColumna[tecla] = 1;
  }
  colorear();
}

boolean huboCambios() {
  for (int i = 0; i < columnas; i++) {
    if (colorColumna[i] != colorColumnaAnterior[i]) {
      huboCambios = true;
    }
    for (int j = 0; j < filas; j++) {
      if (arrayBits[i][j] != arrayBitsAnterior[i][j]) {
        huboCambios = true;
      }
    }
  }
  return huboCambios;
}

void keyPressed() {
  //ELEGIR EL COLOR de cada columna con las teclas del 1-7
  if (key=='1' & columnaActiva(0)) {//columna 1
    actualizarColorColumna(0);
  }
  if (key=='2' & columnaActiva(1)) {
    actualizarColorColumna(1);
  }
  if (key=='3' & columnaActiva(2)) {
    actualizarColorColumna(2);
  }
  if (key=='4' & columnaActiva(3)) {
    actualizarColorColumna(3);
  }
  if (key=='5' & columnaActiva(4)) {
    actualizarColorColumna(4);
  }
  if (key=='6' & columnaActiva(5)) {
    actualizarColorColumna(5);
  }
  if (key=='7' & columnaActiva(6)) {
    actualizarColorColumna(6);
  }

  //GUARDADO DEL ARCHIVO
  if (key == ENTER) { 
    tiempoRef = frameCount;
    if ( guardado == false) {
      enviarTexto();
      flash = true;
    } else {
      if (huboCambios()) {
        tiempoRef = frameCount;
        imgOut = get();
        saveFrame(nombre + ", " + charNombre + ".jpg");
        int mitadAnchoPixel = anchoPixel/2;
        int mitadAltoPixel = altoPixel/2;

        //println("Dibujo nro " + contador + ": ");
        //output.println("const boolean dibujo_" + contador + "[] PROGMEM = {" );
        println("Dibujo nro " + charNombre + ": ");
        output.println("const boolean dibujo_" + charNombre + "[] PROGMEM = {" );

        //guardo analizando la imagen

        for (int j =mitadAltoPixel; j<imgOut.height; j += altoPixel) {
          for (int i = mitadAnchoPixel; i<imgOut.width; i += anchoPixel) {
            color c = imgOut.get(i, j);
            float colR = red(c);
            float colG = green(c);
            float colB = blue(c);

            char charBit = '0';

            if (colR == 0 && colG == 0 && colB == 0) {
              charBit = '0';
            } else {
              charBit = '1';
            }

            print(charBit+ ", ");
            output.print(charBit+ ", ");
          }
          println(", ");

          output.println(" ");
        }

        output.println("};");

        print("colors: ");
        output.print("String dibujo_" + charNombre + "_color = \"" );

        for (int n = 0; n < columnas; n++) {
          char charColor = ' ';
          if (colorColumna[n] == 0) {
            charColor = 'K';
          }
          if (colorColumna[n] == 1) {
            charColor = 'W';
          }
          if (colorColumna[n] == 2) {
            charColor = 'R';
          }
          if (colorColumna[n] == 3) {
            charColor = 'G';
          }
          if (colorColumna[n] == 4) {
            charColor = 'B';
          }
          if (colorColumna[n] == 5) {
            charColor = 'C';
          }
          if (colorColumna[n] == 6) {
            charColor = 'M';
          }
          if (colorColumna[n] == 7) {
            charColor = 'Y';
          }
          output.print(charColor);
          print( charColor);
          /*
        if (n != columnas - 1) { //para sacar la última coma, no anda
           output.print(", ");
           print( ", ");
           } */
        }
        output.print("\";");
        output.println("");
        output.println("");
        output.println("");

        output.flush(); 
        //output.close();

        println(" ");
        huboCambios = false;
        arrayCopy(arrayBits, arrayBitsAnterior);
        arrayCopy(colorColumna, colorColumnaAnterior);
        flash = true;

        charNombre++;
        contador++;
      }
    }
  }

  if (key==' ') {//limpia la pantalla
    fill(0);
    rect(0, 0, width, height);
    for (int i = 0; i < columnas; i++) {
      colorColumna[i] = 0;
      for (int j = 0; j < filas; j++) {
        arrayBits[i][j] = 0;
      }
    }
  }
  if (key=='d') { //PARA PRUEBAS
    if (p == true) {
      p = false;
    } else {
      p = true;
    }
  }
}

boolean columnaActiva(int _i) {
  boolean bitActivo = false; 
  for (int j = 0; j < filas; j++) {//recorro todas las filas de esa columna
    if (arrayBits[_i][j] != 0) {//si hay pixel activo
      bitActivo = true;
    }
  }
  if (bitActivo) {
    return true;
  } else {
    return false;
  }
}

void flash() {//cuando guarda hace un flash blanco
  fill(255);
  rect(0, 0, width, height);
  if (frameCount >= tiempoRef + intervalo) {
    cuadricula();
    colorear();
    flash = false;
  }
}

void nDibujos() {//mostrar nombre del dibu
  if (p == true) {
    textSize(10);
    fill(127);
    rect(0, 0, 75, 20);
    fill(255);
    text("Dibujo: " + charNombre, 5, 12);
  }
}
