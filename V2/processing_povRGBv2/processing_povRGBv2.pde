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
  //size(525, 600);
  size(700, 800);
  background(0);

  //inicializacion cuadricula
  anchoPixel = width/columnas;
  altoPixel = (height-20)/filas;
  inicializarArray();

  plaquita = loadImage("heart0.jpg");
  image(plaquita, 375, 200);

  inicializarTexto();
}

void draw() {

  if (flash == false) {
    if (guardado) {
      dibujar();
      selectorDeColores();
      nDibujos();
    }
  } else {
    flash();
  }
}


public void controlEvent(ControlEvent theEvent) {
  if (theEvent.getController().getName().equals("Guardar")) {
    enviarTexto();
  }
}
