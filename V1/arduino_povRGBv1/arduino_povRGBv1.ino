/*
   POV RGB - Mayo 2022 - Flavia Laudado, Nicolas Restbergs
   APP PARA VISUALIZAR EN UNA VARITA POV RGB
   Ingresa tu texto y dibujos !!
*/

#include <avr/pgmspace.h> //Guarda las letras y numeros en otra memoria

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
// PATRÓN DE INICIO
//----------------------------------------------------------------------------------------------

//array de datos para el patron de inicio
const boolean patronInicio[] = {
  1, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0, 0,
  0, 0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0, 0, 0, 0, 1
};

//Se repite un patron de inicio por cada color
String colorInicio = "WRGBCMYW"; 
int tiempoInicio = 100; //velocidad del patron de inicio

//Para repetir patron de inicio infinitas veces poner: en true
//Para no repetir patron de inicio poner en: false
boolean patronLoop = true; //true or false

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
// TEXTO A MOSTRAR
//----------------------------------------------------------------------------------------------

//texto: EN MAYÚSCULAS
//dibus: en minúsculas

String povtext = " HOLA !!! ";
//String povtext = " a b c d e f g "; //dibus de corazones en colores

//setear color del texto (W R G B C M Y)
char povtext_color = 'Y'; //entre comilla simple

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
// FLASHADAS
//----------------------------------------------------------------------------------------------

//Usar los LEDs en negativo, invierte el prendido y apagado
boolean negativo = false; //true o false

//Para colorear por letra activar colorPorLetra
boolean colorPorLetra = false; //true o false
//tiene que tener mismo largo que el texto
String povtext_colorporLetra = " MMCC YYY ";//W R G B C M Y

//Para que no loopee, muestra el mensaje solo una vez
boolean noLoop = false; //true o false

//velocidad de ejecución, se puede cambiar !
byte refreshrate = 1; //tiempo en milisegundos

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
// REEMPLAZAR AQUI CON LOS DIBUJOS !!
//----------------------------------------------------------------------------------------------

//Cantidad de dibus, máximo 26, corresponden de la a-z
//Reemplazar los dibus nuevos y dejar vacios los que no se usen
int nDibus = 7;

const boolean dibujo_a[] PROGMEM = {
  0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 1, 0,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
};
String dibujo_a_color = { "WWWWWWW" };

const boolean dibujo_b[] PROGMEM = {
  0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 1, 0,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 0, 0, 0
};
String dibujo_b_color = { "RRRRRRR" };

const boolean dibujo_c[] PROGMEM = {
  0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 1, 0,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
};
String dibujo_c_color = { "GGGGGGG" };

const boolean dibujo_d[] PROGMEM = {
  0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 1, 0,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 0, 0, 0
};
String dibujo_d_color = { "BBBBBBB" };

const boolean dibujo_e[] PROGMEM = {
  0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 1, 0,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
};
String dibujo_e_color = { "CCCCCCC" };

const boolean dibujo_f[] PROGMEM = {
  0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 1, 0,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 0, 0, 0
};
String dibujo_f_color = { "MMMMMMM" };

const boolean dibujo_g[] PROGMEM = {
  0, 0, 0, 0, 0, 0, 0,
  0, 1, 0, 0, 0, 1, 0,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
};
String dibujo_g_color = { "YYYYYYY" };

const boolean dibujo_h[] PROGMEM = { };
String dibujo_h_color = "";

const boolean dibujo_i[] PROGMEM = { };
String dibujo_i_color = "";

const boolean dibujo_j[] PROGMEM = { };
String dibujo_j_color = "";

const boolean dibujo_k[] PROGMEM = { };
String dibujo_k_color = "";

const boolean dibujo_l[] PROGMEM = { };
String dibujo_l_color = "";

const boolean dibujo_m[] PROGMEM = { };
String dibujo_m_color = "";

const boolean dibujo_n[] PROGMEM = { };
String dibujo_n_color = "";

const boolean dibujo_o[] PROGMEM = { };
String dibujo_o_color = "";

const boolean dibujo_p[] PROGMEM = { };
String dibujo_p_color = "";

const boolean dibujo_q[] PROGMEM = { };
String dibujo_q_color = "";

const boolean dibujo_r[] PROGMEM = { };
String dibujo_r_color = "";

const boolean dibujo_s[] PROGMEM = { };
String dibujo_s_color = "";

const boolean dibujo_t[] PROGMEM = { };
String dibujo_t_color = "";

const boolean dibujo_u[] PROGMEM = { };
String dibujo_u_color = "";

const boolean dibujo_v[] PROGMEM = { };
String dibujo_v_color = "";

const boolean dibujo_w[] PROGMEM = { };
String dibujo_w_color = "";

const boolean dibujo_x[] PROGMEM = { };
String dibujo_x_color = "";

const boolean dibujo_y[] PROGMEM = { };
String dibujo_y_color = "";

const boolean dibujo_z[] PROGMEM = { };
String dibujo_z_color = "";

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
// LETRAS Y NUMEROS
//----------------------------------------------------------------------------------------------

//Se pueden modificar, y hacer tu propia tipografía
// de 7x8 px (ancho x alto)

const boolean letterA[] PROGMEM = {
  0, 0, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterB[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterC[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterD[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterE[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterF[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterG[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterH[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterI[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterJ[] PROGMEM = {
  0, 0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterK[] PROGMEM = {
  1, 1, 0, 0, 1, 1, 1,
  1, 1, 0, 1, 1, 1, 0,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 0, 0, 0,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 0, 1, 1, 1, 0,
  1, 1, 0, 0, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterL[] PROGMEM = {
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterM[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 1, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterN[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 0, 0, 1, 1,
  1, 1, 1, 1, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 1, 1, 1, 1,
  1, 1, 0, 0, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterO[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterP[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterQ[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 1, 0, 1, 1,
  1, 1, 0, 1, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterR[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 1, 1, 1,
  1, 1, 1, 1, 1, 0, 0,
  1, 1, 0, 1, 1, 1, 0,
  1, 1, 0, 0, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterS[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterT[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0
};


const boolean letterU[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterV[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 0, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterW[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 1, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 0, 1, 1, 1,
  1, 0, 0, 0, 0, 0, 1,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterX[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 1, 0, 1, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 1, 0, 1, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterY[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 1, 1,
  1, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letterZ[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1, 1,
  0, 0, 0, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter33[] PROGMEM = {//signo de exclamacion !
  0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter0[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter1[] PROGMEM = {
  0, 0, 1, 1, 1, 0, 0,
  0, 1, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 1, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter2[] PROGMEM = {
  0, 0, 1, 1, 1, 1, 0,
  0, 1, 1, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 1, 1,
  0, 0, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter3[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  0, 0, 0, 0, 0, 1, 1,
  0, 0, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter4[] PROGMEM = {
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1, 1,
  0, 0, 0, 0, 1, 1, 1,
  0, 0, 0, 0, 1, 1, 1,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter5[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter6[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter7[] PROGMEM = {
  1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 1, 1, 1,
  0, 0, 0, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 0, 0,
  0, 0, 1, 1, 0, 0, 0,
  0, 0, 1, 1, 0, 0, 0,
  0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter8[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

const boolean letter9[] PROGMEM = {
  0, 1, 1, 1, 1, 1, 0,
  1, 1, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 1, 1,
  1, 1, 0, 0, 0, 1, 1,
  0, 1, 1, 1, 1, 1, 0,
  0, 0, 0, 0, 0, 0, 0
};

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
// VARIABLES GENERALES
//----------------------------------------------------------------------------------------------

//byte con la data que prende y apaga los LEDs
byte data2 = 0;// portD

//pines para los transistores RGB
const byte pinR = 11;
const byte pinG = 10;
const byte pinB = 9;

//variables generales
byte n;
byte m;
byte t;
byte l;

int anchoLetra = 7;
int altoLetra = 8;
int ascii;
char letraActual;

//largo del texto
int dimtext = povtext.length();
//cantidad de repeticiones del patron de inicio
int repeticionInicio = colorInicio.length();

int contadorDibus = 0;

void setup() {
  setup_povRGB();
}

void loop() {
  if (noLoop == false) {
    loop_povRGB();
  }
}
