/* ===================================================================== *
 *                                                                       *
 * Menu Callback Function                                                *
 *                                                                       *
 * ===================================================================== */
 
// *********************************************************************
void mFunc_back(uint8_t linea)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // termina la funzione e torna indietro di un livello
    LCDML.FUNC_goBackToMenu(1);      // abbandona questa funzione e torna indietro di un livello
  }
}


// *********************************************************************
void mFunc_screensaver(uint8_t linea)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    // update LCD content
    lcd.setCursor(0, 0); // set cursor
    lcd.print("Screensaver"); // print 
    lcd.setCursor(0, 1); 
    lcd.print("premi un qualsiasi");
    lcd.setCursor(0, 2); 
    lcd.print("tasto per uscire");
    LCDML.FUNC_setLoopInterval(100);  // avvia un evento trigger per la funzione loop ogni 100 millisecondi
  }

  if(LCDML.FUNC_loop())
  {
    if (LCDML.BT_checkAny()) // controlla se un pulsante è premuto (invio, su, giù, sinistra, destra)
    {
      LCDML.FUNC_goBackToMenu();  // lascia questa funzione
    }
  }

  if(LCDML.FUNC_close())
  {
    // Lo screensaver va al menu principale
    //LCDML.MENU_goRoot();
  }
}


//****************************************************************************************************** <---- INIZIO:  Marcia e Arresto 
// *********************************************************************
void MarciaArresto_Avvia(uint8_t linea)
// *********************************************************************
{

  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    Stato_MA_1=0;
    LCDML.FUNC_setLoopInterval(10);
  }

  
  if(LCDML.FUNC_loop())
  {

    //Richiama funzione pannello
    Pannello_MarciaArresto(Pin_MarciaArresto_NO, Pin_MarciaArresto_NC, Pin_MarciaArresto_Out);

    //Quando premi ok esci dalla funzione
    if(LCDML.BT_checkEnter() == true)
    {
      //Resetta eventuali impostazioni residue dall'esecuzione del pannello
      Stato_MA_1=0;
      digitalWrite(Pin_MarciaArresto_Out,HIGH);

      //Esci dalla funzione
      LCDML.FUNC_goBackToMenu();
    }
  }

  if(LCDML.FUNC_close())
  {
    // Torna al menu principale
    LCDML.MENU_goRoot();
  }
}


//****************************************************************************************************** <---- FINE:  Marcia e Arresto 



//****************************************************************************************************** <---- INIZIO:  Inversione
// *********************************************************************
void Inversione_Avvia(uint8_t linea)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    Stato_Inv_1=0;
    Stato_Inv_2=0;
    LCDML.FUNC_setLoopInterval(10);
  }

  
  if(LCDML.FUNC_loop())
  {

    //Richiama funzione pannello
    Pannello_Inversione(Pin_Inversione_NO_1, Pin_Inversione_NC_1,Pin_Inversione_NO_2, Pin_Inversione_Out_1,Pin_Inversione_Out_2);

    //Quando premi ok esci dalla funzione
    if(LCDML.BT_checkEnter() == true)
    {
      //Resetta eventuali impostazioni residue dall'esecuzione del pannello
      Stato_Inv_1=0;
      Stato_Inv_2=0;
      digitalWrite(Pin_Inversione_Out_1,HIGH);
      digitalWrite(Pin_Inversione_Out_1,HIGH);

      //Esci dalla funzione
      LCDML.FUNC_goBackToMenu();
    }
  }

  if(LCDML.FUNC_close())
  {
    // Torna al menu principale
    LCDML.MENU_goRoot();
  }
}

//****************************************************************************************************** <---- FINE:  Inversione 



//****************************************************************************************************** <---- INIZIO:  InversioneFinecorsa
// *********************************************************************
void InversioneFinecorsa_Avvia(uint8_t linea)
// *********************************************************************
{

  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    Stato_InvF_3=0;
    Stato_InvF_2=0;
    Stato_InvF_1=0;
    LCDML.FUNC_setLoopInterval(10);
  }

  
  if(LCDML.FUNC_loop())
  {

    //Richiama funzione pannello
    Pannello_InversioneFinecorsa(Pin_InversioneFinecorsa_NO_1, Pin_InversioneFinecorsa_NC_1,Pin_InversioneFinecorsa_NO_2,Pin_InversioneFinecorsa_NC_2, Pin_InversioneFinecorsa_NC_3, Pin_InversioneFinecorsa_Out_1, Pin_InversioneFinecorsa_Out_2);

    //Quando premi ok esci dalla funzione
    if(LCDML.BT_checkEnter() == true)
    {
      //Resetta eventuali impostazioni residue dall'esecuzione del pannello
      Stato_InvF_3=0;
      Stato_InvF_2=0;
      Stato_InvF_1=0;
      digitalWrite(Pin_InversioneFinecorsa_Out_1,HIGH);
      digitalWrite(Pin_InversioneFinecorsa_Out_2,HIGH);

      //Esci dalla funzione
      LCDML.FUNC_goBackToMenu();
    }
  }

  if(LCDML.FUNC_close())
  {
    // Torna al menu principale
    LCDML.MENU_goRoot();
  }
}

//****************************************************************************************************** <---- FINE:  InversioneFinecorsa 



//****************************************************************************************************** <---- INIZIO:  InversioneFinecorsaRitardo
// *********************************************************************
void InversioneFinecorsaRitardo_Avvia(uint8_t linea)
// *********************************************************************
{
  
}

//****************************************************************************************************** <---- FINE:  InversioneFinecorsaRitardo



//****************************************************************************************************** <---- INIZIO:  DEBUG
// *********************************************************************
void Debug_Output(uint8_t linea)
// *********************************************************************
{
  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
     Tempo_SYS=millis();
     Tempo_AT_SYS=millis();
     Debug_Out_Contatore=1;
  }

  
  if(LCDML.FUNC_loop())
  {
     LCDML.FUNC_setLoopInterval(1);
    if(Tempo_SYS-Tempo_AT_SYS<Debug_Out_TempoScarto)
    {
      Output_Funzione(Debug_Out_Contatore,0);
    }
        
    if(Tempo_SYS-Tempo_AT_SYS>=Debug_Out_TempoScarto)
    {
      Output_Funzione(Debug_Out_Contatore,1);
      
      if(Tempo_SYS-Tempo_AT_SYS>=Debug_Out_TempoScarto*2)
      {
        Tempo_AT_SYS=0;
        Debug_Out_Contatore++;
        Tempo_AT_SYS=millis();
      }
    }

    //Quando premi ok esci dalla funzione
    if(Debug_Out_Contatore>=9)
    {
      Debug_Out_Contatore=1;
      //Resetta eventuali impostazioni residue dall'esecuzione del pannello
      
      //Esci dalla funzione
      LCDML.FUNC_goBackToMenu();
    }else{
      
    }

    //progressione
    lcd.setCursor(0,0);
    lcd.print("Avanzamento:");
    lcd.setCursor(13,0);
    lcd.print(((Debug_Out_Contatore*Debug_Out_TempoScarto*2)/(Debug_Out_TempoScarto*16))*100);
  }

  if(LCDML.FUNC_close())
  {
    // Torna al menu principale
    //LCDML.MENU_goRoot();
    Tempo_AT_SYS=0;
  }
}

// *********************************************************************
void Debug_Input(uint8_t linea)
// *********************************************************************
{

  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    
  }
  
  if(LCDML.FUNC_loop())
  {
    lcd.setCursor(0,0);            
    lcd.print("Guarda i led sopra  ");
    lcd.setCursor(0,1);            
    lcd.print("il verde e' monte il");
    lcd.setCursor(0,2);            
    lcd.print("rosso e' valle del  ");
    lcd.setCursor(0,3);            
    lcd.print("fotoccoppiatore     ");
    //Richiama funzione pannello
    
    //Quando premi ok esci dalla funzione
    if(LCDML.BT_checkAny() == true)
    {
      //Resetta eventuali impostazioni residue dall'esecuzione del pannello
      
      
      //Esci dalla funzione
      LCDML.FUNC_goBackToMenu();
    }
  }

  if(LCDML.FUNC_close())
  {
    // Torna al menu principale
    //LCDML.MENU_goRoot();
  }
}

        

// *********************************************************************
void Debug_Tastiera(uint8_t linea)
// *********************************************************************
{

  if(LCDML.FUNC_setup())          // ****** SETUP *********
  {
    Tempo_AT_SYS=millis();
  }
  
  if(LCDML.FUNC_loop())
  {
    LCDML.FUNC_setLoopInterval(1);
    lcd.setCursor(0,0);
    lcd.print("dx:");
    lcd.setCursor(7,0);
    lcd.print("sx:");
    lcd.setCursor(14,0);
    lcd.print("OK:");
    lcd.setCursor(0,1);
    lcd.print("su:");
    lcd.setCursor(7,1);
    lcd.print("giu:");
    lcd.setCursor(14,1);
    lcd.print("1:");
    lcd.setCursor(0,2);
    lcd.print("2:");
    //Richiama funzione pannello
    lcd.setCursor(0,3);
    lcd.print(20-(Tempo_SYS/1000-Tempo_AT_SYS/1000)); 
    
    //Quando premi ok esci dalla funzione
    if(LCDML.BT_checkAny() == true)
    {

      if(LCDML.BT_checkUp() == true)
      {
        lcd.setCursor(3,1);
        lcd.print("ok");
      }
      if(LCDML.BT_checkDown() == true)
      {
        lcd.setCursor(11,1);
        lcd.print("ok");
      }
      if(LCDML.BT_checkEnter() == true)
      {
        lcd.setCursor(17,0);
        lcd.print("ok");
      }
      if(LCDML.BT_checkLeft() == true)
      {
        lcd.setCursor(10,0);
        lcd.print("ok");
      }
      if(LCDML.BT_checkRight() == true)
      {
        lcd.setCursor(3,0);
        lcd.print("ok");
      }
      if(LCDML.BT_checkQuit() == true)
      {
        lcd.setCursor(16,1);
        lcd.print("ok");
      }
      if(Tastierino_2==1)
      {
        lcd.setCursor(2,2);
        lcd.print("ok");
      }
    }
    if(Tempo_SYS/1000-Tempo_AT_SYS/1000>=20)
    {
      LCDML.FUNC_goBackToMenu();
    }
  }

  if(LCDML.FUNC_close())
  {
    // Torna al menu principale
    //LCDML.MENU_goRoot();
  }
}


//****************************************************************************************************** <---- FINE:  DEBUG




//****************************************************************************************************** <---- INIZIO:  IMPOSTAZIONI

//****************************************************************************************************** <---- FINE:  IMPOSTAZIONI



