void setup_povRGB() {

  DDRD = 0xFF;//portD- digital pins 0-7

  //Pines RGB
  pinMode (pinR, OUTPUT);
  pinMode (pinG, OUTPUT);
  pinMode (pinB, OUTPUT);

  //PATRON DE INICIO
  for (int i = 0; i < repeticionInicio; i++) {
    colorear(colorInicio.charAt(i));
    inicializarLEDs();
  }
  while (patronLoop) {
    for (int i = 0; i < repeticionInicio; i++) {
      colorear(colorInicio.charAt(i));
      inicializarLEDs();
    }
  }
  if (noLoop) {
    loop_povRGB();
  }
}

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//FUNCIONES-------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------

//funcion para mandar cada caracter de texto
void sendToWand(const boolean letterArray[]) {

  for (t = 0; t < anchoLetra; t++) { //t -> recorre cada columna (time step)

    for (l = 0; l < altoLetra; l++) { //l -> recorre las 8 fila
      data2 = data2 << 1;//desplazamiento bit a bit a la izquierda
      data2 |= pgm_read_byte_near(letterArray + (l * anchoLetra + t)); //agrega un nuevo valor al byte
    }

    //Setea los pines con cada columna del array
    PORTD = data2; //0-7

    if (negativo == true) { //invierte las letras a negativo
      PORTD = PORTD ^ B11111111;
    }
    delay(refreshrate);
    //Limpia el byte de data
    data2 = 0;
  }
}

//funcion para mandar cada dibujo
void sendDrawToWand(const boolean letterArray[], String colorDibujo) {

  for (t = 0; t < anchoLetra; t++) { //recorre cada columna (time step)

    //colorea segun el String asociado
    colorear(colorDibujo.charAt(t));

    for (l = 0; l < altoLetra; l++) { //recorre las 8 filas
      data2 = data2 << 1;//desplazamiento bit a bit a la izquierda
      data2 |= pgm_read_byte_near(letterArray + (l * anchoLetra + t)); //agrega un nuevo valor al byte
    }

    //Setea los pines con cada columna del array
    PORTD = data2; //0-7

    if (negativo == true) { //invierte lo dibus a negativo
      PORTD = PORTD ^ B11111111;
    }

    delay(refreshrate);
    //Limpia el byte de data
    data2 = 0;
  }
}

//funcion para pasarle los colores
// colores posibles: W,R,G,B,Y,C,M,
void colorear(char _color) {
  if  ( _color == 'W') {
    digitalWrite(pinB, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinR, HIGH);
  }
  else if ( _color == 'R') {
    digitalWrite(pinB, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinR, HIGH);
  }
  else if ( _color == 'G' ) {
    digitalWrite(pinB, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinR, LOW);
  }
  else if  ( _color == 'B' ) {
    digitalWrite(pinB, HIGH);
    digitalWrite(pinG, LOW);
    digitalWrite(pinR, LOW);
  }
  else if ( _color == 'Y') {
    digitalWrite(pinB, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinR, HIGH);
  }
  else if ( _color == 'C' ) {
    digitalWrite(pinB, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinR, LOW);
  }
  else if  ( _color == 'M' ) {
    digitalWrite(pinB, HIGH);
    digitalWrite(pinG, LOW);
    digitalWrite(pinR, HIGH);
  }
  else if  ( _color == 'K') {
    digitalWrite(pinB, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinR, LOW);
  }
  else if  ( _color == ' ') {
    digitalWrite(pinB, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinR, LOW);
  }
}

void inicializarLEDs() {
  //Inicialización de los LEDs con el patron de inicio
  for (byte j = 0; j < altoLetra; j++) {

    for (byte i = 0; i < altoLetra; i++) {
      data2 = data2 << 1;
      data2 |= patronInicio[(i * altoLetra + j)];
    }

    PORTD = data2;

    delay(tiempoInicio);
  }
  data2 = 0;
  PORTD = data2;

}
void apagarLEDs(int tiempo) {
  if (negativo == false) {
    PORTD = 0;
  }
  if (negativo == true) {
    PORTD = B11111111;
  }

  delay(refreshrate * tiempo);
}

void loop_povRGB() {

  //al comenzar apaga todo
  apagarLEDs(3);

  for (n = 0; n < dimtext; n++) { //recorre el texto para mostrarlo

    //obtiene la letra a mostrar, el caracter y el ascii
    ascii = int(povtext.charAt(n));
    letraActual = povtext.charAt(n);

    //aplica el color, para el texto
    if (colorPorLetra == false) {
      colorear(povtext_color); //colorea con un solo color
    } else {
      colorear(povtext_colorporLetra.charAt(n));//colorea por letra
    }

    //busca el array de cada caracter y lo muestra en la varita
    if (letraActual == 'A') {
      sendToWand(letterA);
    }
    else if (letraActual == 'B') {
      sendToWand(letterB);
    }
    else if (letraActual == 'C') {
      sendToWand(letterC);
    }
    else if (letraActual == 'D') {
      sendToWand(letterD);
    }
    else if (letraActual == 'E') {
      sendToWand(letterE);
    }
    else if (letraActual == 'F') {
      sendToWand(letterF);
    }
    else if (letraActual == 'G') {
      sendToWand(letterG);
    }
    else if (letraActual == 'H') {
      sendToWand(letterH);
    }
    else if (letraActual == 'I') {
      sendToWand(letterI);
    }
    else if (letraActual == 'J') {
      sendToWand(letterJ);
    }
    else if (letraActual == 'K') {
      sendToWand(letterK);
    }
    else if (letraActual == 'L') {
      sendToWand(letterL);
    }
    else if (letraActual == 'M') {
      sendToWand(letterM);
    }
    else if (letraActual == 'N') {
      sendToWand(letterN);
    }
    else if (letraActual == 'O') {
      sendToWand(letterO);
    }
    else if (letraActual == 'P') {
      sendToWand(letterP);
    }
    else if (letraActual == 'Q') {
      sendToWand(letterQ);
    }
    else if (letraActual == 'R') {
      sendToWand(letterR);
    }
    else if (letraActual == 'S') {
      sendToWand(letterS);
    }
    else if (letraActual == 'T') {
      sendToWand(letterT);
    }
    else if (letraActual == 'U') {
      sendToWand(letterU);
    }
    else if (letraActual == 'V') {
      sendToWand(letterV);
    }
    else if (letraActual == 'W') {
      sendToWand(letterW);
    }
    else if (letraActual == 'X') {
      sendToWand(letterX);
    }
    else if (letraActual == 'Y') {
      sendToWand(letterY);
    }
    else if (letraActual == 'Z') {
      sendToWand(letterZ);
    }
    else if (letraActual == '!') {
      sendToWand(letter33);
    }
    else if (letraActual == '0') {
      sendToWand(letter0);
    }
    else if (letraActual == '1') {
      sendToWand(letter1);
    }
    else if (letraActual == '2') {
      sendToWand(letter2);
    }
    else if (letraActual == '3') {
      sendToWand(letter3);
    }
    else if (letraActual == '4') {
      sendToWand(letter4);
    }
    else if (letraActual == '5') {
      sendToWand(letter5);
    }
    else if (letraActual == '6') {
      sendToWand(letter6);
    }
    else if (letraActual == '7') {
      sendToWand(letter7);
    }
    else if (letraActual == '8') {
      sendToWand(letter8);
    }
    else if (letraActual == '9') {
      sendToWand(letter9);
    }
    else if (letraActual == ' ') {
      //PORTD = 0;
      apagarLEDs(3); //off for 3 times
    }

    //busca los dibujos y los muestra
    else if ( 97 >= ascii <= 122) {//letras minusculas 97 - 122
      if (letraActual == 'a' && 1 <= nDibus ) {
        sendDrawToWand(dibujo_a, dibujo_a_color);
      }
      else if (letraActual == 'b' && 2 <= nDibus ) {
        sendDrawToWand(dibujo_b, dibujo_b_color);
      }
      else if (letraActual == 'c' && 3 <= nDibus ) {
        sendDrawToWand(dibujo_c, dibujo_c_color);
      }
      else if (letraActual == 'd' && 4 <= nDibus ) {
        sendDrawToWand(dibujo_d, dibujo_d_color);
      }
      else if (letraActual == 'e' && 5 <= nDibus ) {
        sendDrawToWand(dibujo_e, dibujo_e_color);
      }
      else if (letraActual == 'f' && 6 <= nDibus ) {
        sendDrawToWand(dibujo_f, dibujo_f_color);
      }
      else if (letraActual == 'g' && 7 <= nDibus ) {
        sendDrawToWand(dibujo_g, dibujo_g_color);
      }
      else if (letraActual == 'h' && 8 <= nDibus ) {
        sendDrawToWand(dibujo_h, dibujo_h_color);
      }
      else if (letraActual == 'i' && 9 <= nDibus ) {
        sendDrawToWand(dibujo_i, dibujo_i_color);
      }
      else if (letraActual == 'j' && 10 <= nDibus ) {
        sendDrawToWand(dibujo_j, dibujo_j_color);
      }
      else if (letraActual == 'k' && 11 <= nDibus ) {
        sendDrawToWand(dibujo_k, dibujo_k_color);
      }
      else if (letraActual == 'l' && 12 <= nDibus ) {
        sendDrawToWand(dibujo_l, dibujo_l_color);
      }
      else if (letraActual == 'm' && 13 <= nDibus ) {
        sendDrawToWand(dibujo_m, dibujo_m_color);
      }
      else if (letraActual == 'n' && 14 <= nDibus ) {
        sendDrawToWand(dibujo_n, dibujo_n_color);
      }
      else if (letraActual == 'o' && 15 <= nDibus ) {
        sendDrawToWand(dibujo_o, dibujo_o_color);
      }
      else if (letraActual == 'p' && 16 <= nDibus ) {
        sendDrawToWand(dibujo_p, dibujo_p_color);
      }
      else if (letraActual == 'q' && 17 <= nDibus ) {
        sendDrawToWand(dibujo_q, dibujo_q_color);
      }
      else if (letraActual == 'r' && 18 <= nDibus ) {
        sendDrawToWand(dibujo_r, dibujo_r_color);
      }
      else if (letraActual == 's' && 19 <= nDibus ) {
        sendDrawToWand(dibujo_s, dibujo_s_color);
      }
      else if (letraActual == 't' && 20 <= nDibus ) {
        sendDrawToWand(dibujo_t, dibujo_t_color);
      }
      else if (letraActual == 'u' && 21 <= nDibus ) {
        sendDrawToWand(dibujo_u, dibujo_u_color);
      }
      else if (letraActual == 'v' && 22 <= nDibus ) {
        sendDrawToWand(dibujo_v, dibujo_v_color);
      }
      else if (letraActual == 'w' && 23 <= nDibus ) {
        sendDrawToWand(dibujo_w, dibujo_w_color);
      }
      else if (letraActual == 'x' && 24 <= nDibus ) {
        sendDrawToWand(dibujo_x, dibujo_x_color);
      }
      else if (letraActual == 'y' && 25 <= nDibus ) {
        sendDrawToWand(dibujo_y, dibujo_y_color);
      }
      else if (letraActual == 'z' && 26 <= nDibus ) {
        sendDrawToWand(dibujo_z, dibujo_z_color);
      }
    }

    //espacio entre cada caracter
    apagarLEDs(1);
  }

  //espacio al final del texto
  apagarLEDs(3);

}
