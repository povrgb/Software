
void keyPressed() {
  //Codigo agregado, revisar : Carlos L. 
  if (key == CODED) {
    if (keyCode == LEFT) {
      columnas--;
      cambioCantidadColumnas();
    }

    if (keyCode == RIGHT) {
      columnas++;
      cambioCantidadColumnas();
    }
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
        //Guardo una copia de la imagen de la pantalla para tener de referencia
        saveFrame(nombre + ", " + charNombre + ".jpg");
        
        
        println("Dibujo nro " + charNombre + ": ");
        output.println("const boolean dibujo_" + charNombre + "[] PROGMEM = {" );
        
        
        //////////Desde acá arma el cuerpo del array en el txt.
        //antes leia la imagen, ahora el array de bits
        for (int j =0; j<filas; j ++) {
          for (int i = 0; i<columnas; i ++) {    
            char charBit = arrayBits[i][j]==1 ? '1':'0';

            print(charBit+ ", ");
            output.print(charBit+ ", ");
          }
          println(", ");

          output.println(" ");
        }
        //////////Hasta acá arma el cuerpo del array en el txt.
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

        }
        output.print("\";");
        output.println("");
        output.print("int dibujo_" + charNombre + "_columnas = "+ columnas + ";" );
        output.println("");
        output.println("");
        output.println("");
        output.flush(); 

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
