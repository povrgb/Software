
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

void actualizarColorColumna(int tecla, int cuanto) {
  //lo cambié para que aumente o disminuya segun el parametro
  colorColumna[tecla]= colorColumna[tecla]+ cuanto ;
  if (colorColumna[tecla] >= nColores || colorColumna[tecla]<1) {
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


void nDibujos() {//mostrar nombre del dibu
  if (p == true) {
    textSize(10);
    fill(127);
    noStroke();
    rect(0, height-40, 75, 20);
    fill(255);
    text("Dibujo: " + charNombre, 5, height-32);
  }
}
