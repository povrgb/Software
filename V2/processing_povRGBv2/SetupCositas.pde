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
  text("Click izq -> pintar", xTexto, yTextoCon + espaciado);
  text("Click der -> borrar", xTexto, yTextoCon + espaciado *2);
  text("Enter -> guardar img y array de datos", xTexto, yTextoCon + espaciado *3);
  text("Barra -> limpia la pantalla", xTexto, yTextoCon + espaciado *4);
  text("Flecha der. -> Agrega una columna", xTexto, yTextoCon + espaciado *5);
  text("Flecha izq. -> Quita una columna", xTexto, yTextoCon + espaciado *6);
  text("Los botones parpadeantes que aparecerán abajo en la", xTexto, yTextoCon + espaciado *7);
  text("pantalla te permitirán colorear las columnas.", xTexto, yTextoCon + espaciado *7.5);

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
