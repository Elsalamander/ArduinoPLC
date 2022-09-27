// =====================================================================
//
// CONTROL
//
// =====================================================================
// *********************************************************************
// *********************************************************************
// contenuto:
// (0) Controllo su interfaccia seriale con asdw_e_q
// (1) Controllo su un ingresso analogico
// (2) Controllo su 4 - 6 piedini di ingresso digitali (pullup interni abilitati)    ------------------> Rige 123 in poi (Set pin)
// (3) Controllo tramite encoder [lib di terze parti] (download: https://github.com/PaulStoffregen/Encoder)
// (4) Controllo con tastiera [lib di terze parti] (download: http://playground.arduino.cc/Main/KeypadTutorial)
// (5) Controllo con un telecomando IR [terze parti lib] (download: https://github.com/z3t0/Arduino-IRremote)
// (6) Controllo con un joystick
// (7) Controllo su I2C PCF8574
// *********************************************************************

#define _LCDML_CONTROL_cfg      5

// teoria:
// "#if" è una direttiva preprocessore e nessun errore, guarda qui:
// (inglese) https://en.wikipedia.org/wiki/C_preprocessor


// *********************************************************************
// *************** (0) CONTROLLO SULL'INTERFACCIA SERIALE **************
// *********************************************************************
#if(_LCDML_CONTROL_cfg == 0)
// settings
  # define _LCDML_CONTROL_serial_enter           'e'
  # define _LCDML_CONTROL_serial_up              'w'
  # define _LCDML_CONTROL_serial_down            's'
  # define _LCDML_CONTROL_serial_left            'a'
  # define _LCDML_CONTROL_serial_right           'd'
  # define _LCDML_CONTROL_serial_quit            'q'
// *********************************************************************
void lcdml_menu_control(void)
{
  // Se qualcosa deve iniziare, inserire la condizione di installazione
  if(LCDML.BT_setup()) {
    // viene eseguito solo una volta
  }

  // controlla se è disponibile un nuovo input seriale
  if (Serial.available()) {
    // legge un carattere dal buffer di input
    switch (Serial.read())
    {
      case _LCDML_CONTROL_serial_enter:  LCDML.BT_enter(); break;
      case _LCDML_CONTROL_serial_up:     LCDML.BT_up();    break;
      case _LCDML_CONTROL_serial_down:   LCDML.BT_down();  break;
      case _LCDML_CONTROL_serial_left:   LCDML.BT_left();  break;
      case _LCDML_CONTROL_serial_right:  LCDML.BT_right(); break;
      case _LCDML_CONTROL_serial_quit:   LCDML.BT_quit();  break;
      default: break;
    }
  }
}

// *********************************************************************
// ******************************* END *********************************
// *********************************************************************





// *********************************************************************
// *************** (1) CONTROLLO SU UN PIN ANALOG **********************
// *********************************************************************
#elif(_LCDML_CONTROL_cfg == 1)

  unsigned long g_LCDML_DISP_press_time = 0;
// settings
  #define _LCDML_CONTROL_analog_pin              0
  // quando non hai usato un pulsante, imposta il valore su zero
  #define _LCDML_CONTROL_analog_enter_min        850     // Button Enter
  #define _LCDML_CONTROL_analog_enter_max        920
  #define _LCDML_CONTROL_analog_up_min           520     // Button Up
  #define _LCDML_CONTROL_analog_up_max           590
  #define _LCDML_CONTROL_analog_down_min         700     // Button Down
  #define _LCDML_CONTROL_analog_down_max         770
  #define _LCDML_CONTROL_analog_back_min         950     // Button Back
  #define _LCDML_CONTROL_analog_back_max         1020
  #define _LCDML_CONTROL_analog_left_min         430     // Button Left
  #define _LCDML_CONTROL_analog_left_max         500
  #define _LCDML_CONTROL_analog_right_min        610     // Button Right
  #define _LCDML_CONTROL_analog_right_max        680
// *********************************************************************

void lcdml_menu_control(void)
{
  // Se qualcosa deve iniziare, inserire la condizione di installazione
  if(LCDML.BT_setup()) {
    // viene eseguito solo una volta
  }
  // controlla il timer di rimbalzo
  if((millis() - g_LCDML_DISP_press_time) >= 200) {
    g_LCDML_DISP_press_time = millis(); // resetta il timer di rimbalzo

    uint16_t value = analogRead(_LCDML_CONTROL_analog_pin);  // pin analogico per tastiera

    if (value >= _LCDML_CONTROL_analog_enter_min && value <= _LCDML_CONTROL_analog_enter_max) { LCDML.BT_enter(); }
    if (value >= _LCDML_CONTROL_analog_up_min    && value <= _LCDML_CONTROL_analog_up_max)    { LCDML.BT_up();    }
    if (value >= _LCDML_CONTROL_analog_down_min  && value <= _LCDML_CONTROL_analog_down_max)  { LCDML.BT_down();  }
    if (value >= _LCDML_CONTROL_analog_left_min  && value <= _LCDML_CONTROL_analog_left_max)  { LCDML.BT_left();  }
    if (value >= _LCDML_CONTROL_analog_right_min && value <= _LCDML_CONTROL_analog_right_max) { LCDML.BT_right(); }
    if (value >= _LCDML_CONTROL_analog_back_min  && value <= _LCDML_CONTROL_analog_back_max)  { LCDML.BT_quit();  }
  }
}
// *********************************************************************
// ******************************* END *********************************
// *********************************************************************






// *********************************************************************
// *************** (2) CONTROLLO SUI PIN DIGITALI **********************
// *********************************************************************
#elif(_LCDML_CONTROL_cfg == 2)
// settings
  unsigned long g_LCDML_DISP_press_time = 0;

  #define _LCDML_CONTROL_digital_low_active      0    // 0 = pulsante alto attivo (pulldown), 1 = basso attivo (pullup)
  
  #define _LCDML_CONTROL_digital_enable_quit     1    // abilita pin quit
  #define _LCDML_CONTROL_digital_enable_lr       1    // abilita dx e sx
  
  #define _LCDML_CONTROL_digital_enter           27
  #define _LCDML_CONTROL_digital_up              29
  #define _LCDML_CONTROL_digital_down            33
  #define _LCDML_CONTROL_digital_quit            31
  #define _LCDML_CONTROL_digital_left            23
  #define _LCDML_CONTROL_digital_right           34
// *********************************************************************
void lcdml_menu_control(void)
{
  // Se qualcosa deve iniziare, inserire la condizione di installazione
  if(LCDML.BT_setup()) {
    // viene eseguito solo una volta
    // init buttons
    pinMode(_LCDML_CONTROL_digital_enter      , INPUT);
    pinMode(_LCDML_CONTROL_digital_up         , INPUT);
    pinMode(_LCDML_CONTROL_digital_down       , INPUT);
    # if(_LCDML_CONTROL_digital_enable_quit == 1)
      pinMode(_LCDML_CONTROL_digital_quit     , INPUT);
    # endif
    # if(_LCDML_CONTROL_digital_enable_lr == 1)
      pinMode(_LCDML_CONTROL_digital_left     , INPUT);
      pinMode(_LCDML_CONTROL_digital_right    , INPUT);
    # endif
  }

  #if(_LCDML_CONTROL_digital_low_active == 1)
  #  define _LCDML_CONTROL_digital_a !
  #else
  #  define _LCDML_CONTROL_digital_a
  #endif

  uint8_t but_stat = 0x00;

  bitWrite(but_stat, 0, _LCDML_CONTROL_digital_a(digitalRead(_LCDML_CONTROL_digital_enter)));
  bitWrite(but_stat, 1, _LCDML_CONTROL_digital_a(digitalRead(_LCDML_CONTROL_digital_up)));
  bitWrite(but_stat, 2, _LCDML_CONTROL_digital_a(digitalRead(_LCDML_CONTROL_digital_down)));
  #if(_LCDML_CONTROL_digital_enable_quit == 1)
  bitWrite(but_stat, 3, _LCDML_CONTROL_digital_a(digitalRead(_LCDML_CONTROL_digital_quit)));
  #endif
  #if(_LCDML_CONTROL_digital_enable_lr == 1)
  bitWrite(but_stat, 4, _LCDML_CONTROL_digital_a(digitalRead(_LCDML_CONTROL_digital_left)));
  bitWrite(but_stat, 5, _LCDML_CONTROL_digital_a(digitalRead(_LCDML_CONTROL_digital_right)));
  #endif

  if (but_stat > 0) {
    if((millis() - g_LCDML_DISP_press_time) >= 200) {
      g_LCDML_DISP_press_time = millis(); // reset press time

      if (bitRead(but_stat, 0)) { LCDML.BT_enter(); }
      if (bitRead(but_stat, 1)) { LCDML.BT_up();    }
      if (bitRead(but_stat, 2)) { LCDML.BT_down();  }
      if (bitRead(but_stat, 3)) { LCDML.BT_quit();  }
      if (bitRead(but_stat, 4)) { LCDML.BT_left();  }
      if (bitRead(but_stat, 5)) { LCDML.BT_right(); }
    }
  }
}
// *********************************************************************
// ******************************* END *********************************
// *********************************************************************






// *********************************************************************
// *************** (3) CONTROLLO CON ENCODER ****************************
// *********************************************************************
#elif(_LCDML_CONTROL_cfg == 3)
  /*
    * Grazie a "MuchMore" (forum Arduino) per aggiungere questa funzionalità di codifica
    *
    * ruota a sinistra = Su
    * ruota a destra = Giù
    * push = Invio
    * spingere lungo = Esci
    * spingere + ruotare a sinistra = sinistra
    * spingere + ruotare a destra = destra
    * /

    * connessione encoder
    * pulsante * (non utilizzare un resistore esterno, viene utilizzata la resistenza di pull-up interna)
    * .------- o Pin Arduino
    * |
    * |
    * o  /
    *   /
    *  /
    * o
    * |
    * '------- o GND
    *
    * encoder * (non utilizzare un resistore esterno, vengono utilizzate le resistenze di pull-up interne)
    *
    * .--------------- o Pin Arduino A
    * |        .------ o Arduino Pin B
    * |        |
    * o  /     o  /
    *   /        /
    *  /        /
    * o         o
    * |         |
    * '-------- o ---- o GND (pin comune)
   */

  // globale definisce
  #define encoder_A_pin       20    // il pin fisico deve essere 2 o 3 per utilizzare gli interrupt (su mega per esempio 20 o 21), usare i pullup interni
  #define encoder_B_pin       21    // il pin fisico deve essere 2 o 3 per utilizzare gli interrupt (su mega per esempio 20 o 21), usare i pullup interni
  #define encoder_button_pin  49    // pin fisico, usa il pullup interno

  #define g_LCDML_CONTROL_button_long_press    800   // ms
  #define g_LCDML_CONTROL_button_short_press   120   // ms

  #define ENCODER_OPTIMIZE_INTERRUPTS // Solo quando si utilizza pin2 / 3 (o 20/21 su mega)
  #include <Encoder.h> //for Encoder    Download:  https://github.com/PaulStoffregen/Encoder

  Encoder ENCODER(encoder_A_pin, encoder_B_pin);

  long  g_LCDML_CONTROL_button_press_time = 0;
  bool  g_LCDML_CONTROL_button_prev       = HIGH;

// *********************************************************************
void lcdml_menu_control(void)
// *********************************************************************
{
  // Se qualcosa deve iniziare, inserire la condizione di installazione
  if(LCDML.BT_setup())
  {
    // viene eseguito solo una volta

    // init pins
    pinMode(encoder_A_pin      , INPUT_PULLUP);
    pinMode(encoder_B_pin      , INPUT_PULLUP);
    pinMode(encoder_button_pin  , INPUT_PULLUP);
  }

  //Volatile Variable
  long g_LCDML_CONTROL_Encoder_position = ENCODER.read();
  bool button                           = digitalRead(encoder_button_pin);

  if(g_LCDML_CONTROL_Encoder_position <= -3) {

    if(!button)
    {
      LCDML.BT_left();
      g_LCDML_CONTROL_button_prev = LOW;
      g_LCDML_CONTROL_button_press_time = -1;
    }
    else
    {
      LCDML.BT_down();
    }
    ENCODER.write(g_LCDML_CONTROL_Encoder_position+4);
  }
  else if(g_LCDML_CONTROL_Encoder_position >= 3)
  {

    if(!button)
    {
      LCDML.BT_right();
      g_LCDML_CONTROL_button_prev = LOW;
      g_LCDML_CONTROL_button_press_time = -1;
    }
    else
    {
      LCDML.BT_up();
    }
    ENCODER.write(g_LCDML_CONTROL_Encoder_position-4);
  }
  else
  {
    if(!button && g_LCDML_CONTROL_button_prev)  // fronte di discesa, pulsante premuto
    {
      g_LCDML_CONTROL_button_prev = LOW;
      g_LCDML_CONTROL_button_press_time = millis();
    }
    else if(button && !g_LCDML_CONTROL_button_prev) // fronte di salita, pulsante non attivo
    {
       g_LCDML_CONTROL_button_prev = HIGH;

       if(g_LCDML_CONTROL_button_press_time < 0)
       {
         g_LCDML_CONTROL_button_press_time = millis();
         //Reset for left right action
       }
       else if((millis() - g_LCDML_CONTROL_button_press_time) >= g_LCDML_CONTROL_button_long_press)
       {
         LCDML.BT_quit();
       }
       else if((millis() - g_LCDML_CONTROL_button_press_time) >= g_LCDML_CONTROL_button_short_press)
       {
         LCDML.BT_enter();
       }
    }
  }
}
// *********************************************************************
// ******************************* END *********************************
// *********************************************************************





// *********************************************************************
// *************** (4) CONTROLLO CON UNA TASTIERA **********************
// *********************************************************************
#elif(_LCDML_CONTROL_cfg == 4)
// include
  // maggiori informazioni sotto http://playground.arduino.cc/Main/KeypadTutorial
  #include <Keypad.h>
// settings
  #define _LCDML_CONTROL_keypad_rows 4 // Four rows
  #define _LCDML_CONTROL_keypad_cols 3 // Three columns
// global vars
  char keys[_LCDML_CONTROL_keypad_rows][_LCDML_CONTROL_keypad_cols] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'#','0','*'}
  };
  byte rowPins[_LCDML_CONTROL_keypad_rows] = { 9, 8, 7, 6 };  // Collegare la tastiera COL0, COL1 e COL2 a questi pin Arduino.
  byte colPins[_LCDML_CONTROL_keypad_cols] = { 12, 11, 10 };  // Crea la tastiera
// objects
  Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, _LCDML_CONTROL_keypad_rows, _LCDML_CONTROL_keypad_cols );
// *********************************************************************
void lcdml_menu_control(void)
{
  // Se qualcosa deve iniziare, inserire la condizione di installazione
  if(LCDML.BT_setup()) {
    // viene eseguito solo una volta
  }
  char key = kpd.getKey();
  if(key) // Controlla la presenza di una chiave valida.
  {
    switch (key)
    {
      case '#': LCDML.BT_enter(); break;
      case '2': LCDML.BT_up();    break;
      case '8': LCDML.BT_down();  break;
      case '4': LCDML.BT_left();  break;
      case '6': LCDML.BT_right(); break;
      case '*': LCDML.BT_quit();  break;
      default: break;
    }
  }
}
// *********************************************************************
// ******************************* END *********************************
// *********************************************************************


// *********************************************************************
// *************** (5) CONTROLLO CON TELECOMANDO IR ********************
// *********************************************************************
#elif(_LCDML_CONTROL_cfg == 5)
    // IR include (questa lib deve essere installata)
    #include <IRremote.h>
    // Vars globali IR
    int RECV_PIN = 11;
    // IR oggetti
    IRrecv irrecv(RECV_PIN);
    decode_results results;

// *********************************************************************
// cambia in questa funzione i valori IR ai tuoi valori
void lcdml_menu_control(void)
{
  // Se qualcosa deve iniziare, inserire la condizione di installazione
  if(LCDML.BT_setup()) {
    // viene eseguito solo una volta
    irrecv.enableIRIn(); // Avvia il ricevitore
  }

  if (irrecv.decode(&results))
  {
      // commenta questa riga, per verificare il codice corretto
      //Serial.println(results.value, HEX);

      // in questo caso devi cambiare il valore 0x ... 1 con il codice IR corretto
      switch (results.value)
      {
          case 16730295: LCDML.BT_enter(); break;
          case 16740495: LCDML.BT_up();    break;
          case 16722135: LCDML.BT_down();  break;
          case 16738455: LCDML.BT_left();  break;
          case 16742535: LCDML.BT_right(); break;
          case 16771095: LCDML.BT_quit();  break;
          default: break;
      }
      irrecv.resume(); // Ricevi il valore successivo
  }
}
// *********************************************************************
// ******************************* END *********************************
// *********************************************************************



// *********************************************************************
// *************** (6) CONTROLLO SU JOYSTICK ***************************
// *********************************************************************
#elif(_LCDML_CONTROL_cfg == 6)
  unsigned long g_LCDML_DISP_press_time = 0;
    // settings
    #define _LCDML_CONTROL_analog_pinx A0
    #define _LCDML_CONTROL_analog_piny A1
    #define _LCDML_CONTROL_digitalread 33 // non funziona con u8glib

    // quando non hai usato un pulsante, imposta il valore su zero
    #define _LCDML_CONTROL_analog_up_min 612 // Button Up
    #define _LCDML_CONTROL_analog_up_max 1023
    #define _LCDML_CONTROL_analog_down_min 0 // Button Down
    #define _LCDML_CONTROL_analog_down_max 412
    #define _LCDML_CONTROL_analog_left_min 612 // Button Left
    #define _LCDML_CONTROL_analog_left_max 1023
    #define _LCDML_CONTROL_analog_right_min 0 // Button Right
    #define _LCDML_CONTROL_analog_right_max 412
// *********************************************************************
void lcdml_menu_control(void)
{
  // Se qualcosa deve iniziare, inserire la condizione di installazione
  if(LCDML.BT_setup()) {
    // viene eseguito solo una volta
    pinMode (_LCDML_CONTROL_digitalread, INPUT);
  }
  // controlla il timer di rimbalzo
  if((millis() - g_LCDML_DISP_press_time) >= 200) {
    g_LCDML_DISP_press_time = millis(); // resetta il timer di rimbalzo

    uint16_t valuex = analogRead(_LCDML_CONTROL_analog_pinx);  // analogpinx
    uint16_t valuey = analogRead(_LCDML_CONTROL_analog_piny);  // analogpinx
    uint16_t valuee = digitalRead(_LCDML_CONTROL_digitalread);  //digitalpinenter


    if (valuey >= _LCDML_CONTROL_analog_up_min && valuey <= _LCDML_CONTROL_analog_up_max) { LCDML.BT_up(); }        // up
    if (valuey >= _LCDML_CONTROL_analog_down_min && valuey <= _LCDML_CONTROL_analog_down_max) { LCDML.BT_down(); }    // down
    if (valuex >= _LCDML_CONTROL_analog_left_min && valuex <= _LCDML_CONTROL_analog_left_max) { LCDML.BT_left(); }     // left
    if (valuex >= _LCDML_CONTROL_analog_right_min && valuex <= _LCDML_CONTROL_analog_right_max) { LCDML.BT_right(); }    // right

    if(valuee == true) {LCDML.BT_enter();}    // enter

    // i pulsanti back devono essere inclusi come voci di menu
    // blocca sull'esempio LCDML_back_button
  }
}
// *********************************************************************
// ******************************* END *********************************
// *********************************************************************

// *********************************************************************
// *************** (7) CONTROLLO SU PCF8574 ****************************
// *********************************************************************

#elif(_LCDML_CONTROL_cfg == 7)
  unsigned long g_LCDML_DISP_press_time = 0;
  #define PCF8574_1 0x26 // Indirizzo I2C per i pulsanti

  #define PCF8574_Pin0 254
  #define PCF8574_Pin1 253
  #define PCF8574_Pin2 251
  #define PCF8574_Pin3 247
  #define PCF8574_Pin4 239
  #define PCF8574_Pin5 223
  #define PCF8574_Pin6 191
  #define PCF8574_Pin7 127

  // Specify the PCF8574 pins here
  #define _LCDML_CONTROL_PCF8574_enable_quit    0
  #define _LCDML_CONTROL_PCF8574_enable_lr      0
  #define _LCDML_CONTROL_PCF8574_enter          PCF8574_Pin1
  #define _LCDML_CONTROL_PCF8574_up             PCF8574_Pin2
  #define _LCDML_CONTROL_PCF8574_down           PCF8574_Pin0
  #define _LCDML_CONTROL_PCF8574_left           PCF8574_Pin2
  #define _LCDML_CONTROL_PCF8574l_right         PCF8574_Pin2
  #define _LCDML_CONTROL_PCF8574_quit           PCF8574_Pin2
// **********************************************************
void lcdml_menu_control(void)
{
  // Se qualcosa deve iniziare, inserire le condizioni di installazione
  if(LCDML.BT_setup()) {
    // viene eseguito solo una volta
  }

  if((millis() - g_LCDML_DISP_press_time) >= 200) {
      g_LCDML_DISP_press_time = millis(); // ripristina il tempo di stampa

    Wire.write(0xff); // Tutti i pin come input?
    Wire.requestFrom(PCF8574_1, 1);
   if (Wire.available()) {
    switch (Wire.read())
    {
      case _LCDML_CONTROL_PCF8574_enter:  LCDML.BT_enter(); break;
      case _LCDML_CONTROL_PCF8574_up:     LCDML.BT_up();    break;
      case _LCDML_CONTROL_PCF8574_down:   LCDML.BT_down();  break;
       #if(_LCDML_CONTROL_PCF8574_enable_quit == 1)
      case _LCDML_CONTROL_PCF8574_left:   LCDML.BT_left();  break;
    #endif
       #if(_LCDML_CONTROL_PCF8574_enable_lr   == 1)
      case _LCDML_CONTROL_PCF8574l_right: LCDML.BT_right(); break;
      case _LCDML_CONTROL_PCF8574_quit:   LCDML.BT_quit();  break;
    #endif
      default: break;
    }
  }
 }
}
// *********************************************************************
// ******************************* END *********************************
// *********************************************************************


#else
  #error _LCDML_CONTROL_cfg is not defined or not in range
#endif
