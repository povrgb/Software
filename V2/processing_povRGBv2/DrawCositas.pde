
void dibujar() { //dibuja en cada cuadrante que se hace click
  if (mousePressed == true) {
    huboCambios = true;
    nH = int(mouseX/anchoPixel);
    nV = int(mouseY/altoPixel);
    if (!(nH>columnas-1 || nH<0 || nV<0 || nV>filas-1)) {//solo para las columnas y filas que me interesa
      if (mouseButton == LEFT) { 
        fill(1);
        arrayBits[int(nH)][int(nV)] = 1;
        if (colorColumna[nH] == 0) {
          colorColumna[nH] = 1;
        }
      } else if (mouseButton == RIGHT) {
        fill(0);
        arrayBits[nH][nV] = 0;
        // rect(nH * anchoPixel, nV * altoPixel, anchoPixel, altoPixel);
        if (columnaActiva(nH) == false) {
          colorColumna[nH] = 0;
        }
      }
    }
    colorear();
  }
}


void flash() {//cuando guarda hace un flash blanco
  fill(255);
  rect(0, 0, width, height);
  if (frameCount >= tiempoRef + intervalo) {
    //   cuadricula();
    colorear();
    flash = false;
  }
}



void colorear() {
  stroke(165);
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

void selectorDeColores() {//Imprime el selector de colores 
  stroke(elegirColor(int(random(7))));

  for (int i = 0; i < columnas; i++) {
    float x=i*anchoPixel;
    fill(elegirColor(colorColumna[i]));
    rect(x, height-20, anchoPixel, 20);
  }
}
