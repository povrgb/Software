void mousePressed(){
 if (mouseY>height-20 ) {
    nH = int(constrain(mouseX/anchoPixel, 0, columnas - 1));
    if(mouseButton == LEFT)
    actualizarColorColumna(nH,+1);
    else actualizarColorColumna(nH,-1);
  }
}
