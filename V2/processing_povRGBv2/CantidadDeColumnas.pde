void cambioCantidadColumnas() {
  //Cuando cambio el numero de columnas tienen que cambiar muchas cosas.
  //Se vuelven a inicializar arrays y variables
  columnas=constrain(columnas, 1, 32);
  println("Cantidad de columnas: ", columnas);

  //Intento no perder el dibujo al redimencionar el array.. Podrán? ahre. 
  int tempBits[][] = arrayBits;
  arrayBits = new int[columnas][filas];
  arrayBitsAnterior = new int[columnas][filas];

  //Recorro mientras el indice no supere ni al nuevo ni al viejo array
  for (int i = 0; i<tempBits.length && i<arrayBits.length; i++) {
    for (int j = 0; j<tempBits[i].length && j<arrayBits[i].length; j++) {
      arrayBits[i][j] = tempBits[i][j];
    }
  }

  //tengo que mantener el array de color tambien!
  int tempColorColumna[] = colorColumna;
  colorColumna = new int[columnas];
  colorColumnaAnterior = new int[columnas];
  //Recorro mientras el indice no supere ni al nuevo ni al viejo array
  for (int i =0; i<tempColorColumna.length && i<colorColumna.length; i++) {//
    colorColumna[i] = tempColorColumna[i];
  }

  anchoPixel = width/columnas;
  //Para que sean cuadrados los pixeles se copia el ancho al alto. Se desaprovecha parte de la pantalla pero me gusta 
  if (columnas>7)
    altoPixel = anchoPixel;
  else altoPixel = height/filas;


  //Ejecuto el Flash como forma de mostrar que cambiaron cosas y para borrar toda la pantalla
  flash();
}
