/* ===================================================================== *
 *                                                                       *
 * Dynamic content                                                       *
 *                                                                       *
 * ===================================================================== */

 // *******************************************************************************************************************************************************
 // MARCIA ARRESTO
 // *******************************************************************************************************************************************************

 //INPUT
void Dyn_MarciaArresto_Visualizza_pin(uint8_t line)
{
  char Val_MarciaArresto_Visualizza[20];
  sprintf (Val_MarciaArresto_Visualizza, "Input:%d NO,%d NC", Pin_MarciaArresto_NO,Pin_MarciaArresto_NC);

  lcd.setCursor(1, line);
  lcd.print(Val_MarciaArresto_Visualizza);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

  // ************************************************************************************
  //OUTPUT
void Dyn_MarciaArresto_Visualizza_Out(uint8_t line)
{
  char Val_MarciaArresto_Visualizza_Out[20];
  sprintf (Val_MarciaArresto_Visualizza_Out, "Output:%d NO", Pin_MarciaArresto_Out);

  lcd.setCursor(1, line);
  lcd.print(Val_MarciaArresto_Visualizza_Out);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

  // ************************************************************************************
  //Set input_1 NO
void Dyn_MarciaArresto_Set_Input_NO(uint8_t line)
{

  lcd.setCursor(1, line);
  lcd.print("NO: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {

    if(LCDML.BT_checkRight() == true)
    {
      Pin_MarciaArresto_NO++;
      if(Pin_MarciaArresto_NO==Pin_MarciaArresto_NC)
      {
        Pin_MarciaArresto_NO++;
      }

      if(Pin_MarciaArresto_NO>12)
      {
        Pin_MarciaArresto_NO=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_MarciaArresto_NO--;
      if(Pin_MarciaArresto_NO==Pin_MarciaArresto_NC)
      {
        Pin_MarciaArresto_NO--;
      }

      if(Pin_MarciaArresto_NO<=0)
      {
        Pin_MarciaArresto_NO=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);
  }else{
      lcd.setCursor(5, line);
      lcd.print(" ");
      lcd.setCursor(9, line);
      lcd.print(" "); 
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_MarciaArresto_NO);
}

  // ************************************************************************************
  //Set input_2 NC
void Dyn_MarciaArresto_Set_Input_NC(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NC: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_MarciaArresto_NC++;
      if(Pin_MarciaArresto_NO==Pin_MarciaArresto_NC)
      {
        Pin_MarciaArresto_NC++;
      }

      if(Pin_MarciaArresto_NC>12)
      {
        Pin_MarciaArresto_NC=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_MarciaArresto_NC--;
      if(Pin_MarciaArresto_NO==Pin_MarciaArresto_NC)
      {
        Pin_MarciaArresto_NC--;
      }

      if(Pin_MarciaArresto_NC<=0)
      {
        Pin_MarciaArresto_NC=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
     
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
  }

  lcd.setCursor(7, line);
  lcd.print(Pin_MarciaArresto_NC);
}


  // ************************************************************************************
  //Set Out
void Dyn_MarciaArresto_Set_Out(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("Out: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_MarciaArresto_Out++;

      if(Pin_MarciaArresto_Out>8)
      {
        Pin_MarciaArresto_Out=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_MarciaArresto_Out--;

      if(Pin_MarciaArresto_Out<=0)
      {
        Pin_MarciaArresto_Out=8;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
     
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_MarciaArresto_Out);
}


 // *******************************************************************************************************************************************************
 // INVERSIONE
 // *******************************************************************************************************************************************************
 //INPUT
void Dyn_Inversione_Visualizza_pin(uint8_t line)
{
  char Val_Inversione_Visualizza[20];
  sprintf (Val_Inversione_Visualizza, "Input:%dNO,%dNC,%dNO", Pin_Inversione_NO_1,Pin_Inversione_NC_1,Pin_Inversione_NO_2);

  lcd.setCursor(1, line);
  lcd.print(Val_Inversione_Visualizza);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}
 // ************************************************************************************
 //OUTPUT
void Dyn_Inversione_Visualizza_Out(uint8_t line)
{
  char Val_Inversione_Visualizza_Out[20];
  sprintf (Val_Inversione_Visualizza_Out, "Output:%d NO,%d NO", Pin_Inversione_Out_1,Pin_Inversione_Out_2);

  lcd.setCursor(1, line);
  lcd.print(Val_Inversione_Visualizza_Out);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

// ************************************************************************************
//Set input_1 NO
void Dyn_Inversione_Set_Input_NO_1(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NO: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_Inversione_NO_1++;
      if(Pin_Inversione_NO_1==Pin_Inversione_NC_1)
      {
        Pin_Inversione_NO_1++;
      }
      if(Pin_Inversione_NO_1==Pin_Inversione_NO_2)
      {
        Pin_Inversione_NO_1++;
      }

      if(Pin_Inversione_NO_1>12)
      {
        Pin_Inversione_NO_1=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_Inversione_NO_1--;
      if(Pin_Inversione_NO_1==Pin_Inversione_NC_1)
      {
        Pin_Inversione_NO_1--;
      }
      if(Pin_Inversione_NO_1==Pin_Inversione_NO_2)
      {
        Pin_Inversione_NO_1--;
      }

      if(Pin_Inversione_NO_1<=0)
      {
        Pin_Inversione_NO_1=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_Inversione_NO_1);
}

  // ************************************************************************************
 //Set pin NC_1
void Dyn_Inversione_Set_Input_NC_1(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NC: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_Inversione_NC_1++;
      if(Pin_Inversione_NC_1==Pin_Inversione_NO_1)
      {
        Pin_Inversione_NC_1++;
      }
      if(Pin_Inversione_NC_1==Pin_Inversione_NO_2)
      {
        Pin_Inversione_NC_1++;
      }

      if(Pin_Inversione_NC_1>12)
      {
        Pin_Inversione_NC_1=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_Inversione_NC_1--;
      if(Pin_Inversione_NC_1==Pin_Inversione_NO_1)
      {
        Pin_Inversione_NC_1--;
      }
      if(Pin_Inversione_NC_1==Pin_Inversione_NO_2)
      {
        Pin_Inversione_NC_1--;
      }

      if(Pin_Inversione_NC_1<=0)
      {
        Pin_Inversione_NC_1=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_Inversione_NC_1);
}

 // ************************************************************************************
 //Set pin NO_2
void Dyn_Inversione_Set_Input_NO_2(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NO: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_Inversione_NO_2++;
      if(Pin_Inversione_NO_2==Pin_Inversione_NC_1)
      {
        Pin_Inversione_NO_2++;
      }
      if(Pin_Inversione_NO_2==Pin_Inversione_NO_1)
      {
        Pin_Inversione_NO_2++;
      }

      if(Pin_Inversione_NO_2>12)
      {
        Pin_Inversione_NO_2=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_Inversione_NO_2--;
      if(Pin_Inversione_NO_2==Pin_Inversione_NO_1)
      {
        Pin_Inversione_NO_2--;
      }
      if(Pin_Inversione_NO_2==Pin_Inversione_NC_1)
      {
        Pin_Inversione_NO_2--;
      }

      if(Pin_Inversione_NO_2<=0)
      {
        Pin_Inversione_NO_2=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_Inversione_NO_2);
}

 // ************************************************************************************
 //Set pin out
void Dyn_Inversione_Set_Out_1(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("Out: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_Inversione_Out_1++;
      if(Pin_Inversione_Out_1==Pin_Inversione_Out_2)
      {
        Pin_Inversione_Out_1++;
      }

      if(Pin_Inversione_Out_1>8)
      {
        Pin_Inversione_Out_1=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_Inversione_Out_1--;
      if(Pin_Inversione_Out_1==Pin_Inversione_Out_2)
      {
        Pin_Inversione_Out_1--;
      }

      if(Pin_Inversione_Out_1<=0)
      {
        Pin_Inversione_Out_1=8;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_Inversione_Out_1);
}

 // ************************************************************************************
 //Set pin out

void Dyn_Inversione_Set_Out_2(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("Out: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_Inversione_Out_2++;
      if(Pin_Inversione_Out_2==Pin_Inversione_Out_1)
      {
        Pin_Inversione_Out_2++;
      }

      if(Pin_Inversione_Out_2>8)
      {
        Pin_Inversione_Out_2=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_Inversione_Out_2--;
      if(Pin_Inversione_Out_2==Pin_Inversione_Out_1)
      {
        Pin_Inversione_Out_2--;
      }

      if(Pin_Inversione_Out_2<=0)
      {
        Pin_Inversione_Out_2=8;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_Inversione_Out_2);
}


 // *******************************************************************************************************************************************************
 // INVERSIONE CON FINECORSA
 // *******************************************************************************************************************************************************
//INPUT
//PARTE 1  
void Dyn_InversioneFinecorsa_Visualizza_pin_1(uint8_t line)
{
  char Val_InversioneFinecorsa_Visualizza_1[20];
  sprintf (Val_InversioneFinecorsa_Visualizza_1, "%d NO:ciclo auto", Pin_InversioneFinecorsa_NO_1);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsa_Visualizza_1);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

// ***********************************************************************
//PARTE 2
void Dyn_InversioneFinecorsa_Visualizza_pin_2(uint8_t line)
{
  char Val_InversioneFinecorsa_Visualizza_2[20];
  sprintf (Val_InversioneFinecorsa_Visualizza_2, "%d NC:fine ciclo", Pin_InversioneFinecorsa_NC_1);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsa_Visualizza_2);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

// ************************************************************************************
//Set input_1 NO
void Dyn_InversioneFinecorsa_Set_Input_NO_1(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NO: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsa_NO_1++;
      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_1)
      {Pin_InversioneFinecorsaRitardo_NO_1++;}
      
      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NO_1++;}

      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NO_1++;}

      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NO_1++;}

      if(Pin_InversioneFinecorsa_NO_1>12)
      {
        Pin_InversioneFinecorsa_NO_1=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsa_NO_1--;
      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_1)
      {Pin_InversioneFinecorsaRitardo_NO_1--;}
      
      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NO_1--;}

      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NO_1--;}

      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NO_1--;}

      if(Pin_InversioneFinecorsa_NO_1<=0)
      {
        Pin_InversioneFinecorsa_NO_1=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsa_NO_1);
}

  // ************************************************************************************
 //Set pin NC_1
void Dyn_InversioneFinecorsa_Set_Input_NC_1(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NC: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsa_NC_1++;
      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NO_1)
      {Pin_InversioneFinecorsaRitardo_NC_1++;}
      
      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NC_1++;}

      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NC_1++;}

      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NC_1++;}

      if(Pin_InversioneFinecorsa_NC_1>12)
      {
        Pin_InversioneFinecorsa_NC_1=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsa_NC_1--;
      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NO_1)
      {Pin_InversioneFinecorsaRitardo_NC_1--;}
      
      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NC_1--;}

      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NC_1--;}

      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NC_1--;}

      if(Pin_InversioneFinecorsa_NC_1<=0)
      {
        Pin_InversioneFinecorsa_NC_1=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsa_NC_1);
}

 // ************************************************************************************
 //Set pin NO_2
void Dyn_InversioneFinecorsa_Set_Input_NO_2(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NO: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsa_NO_2++;
      
      if(Pin_InversioneFinecorsa_NO_2==Pin_InversioneFinecorsa_NO_1)
      {Pin_InversioneFinecorsa_NO_2++;}
      
      if(Pin_InversioneFinecorsa_NO_2==Pin_InversioneFinecorsa_NC_1)
      {Pin_InversioneFinecorsa_NC_2++;}

      if(Pin_InversioneFinecorsa_NO_2==Pin_InversioneFinecorsa_NC_2)
      {Pin_InversioneFinecorsa_NO_2++;}

      if(Pin_InversioneFinecorsa_NO_2==Pin_InversioneFinecorsa_NC_3)
      {Pin_InversioneFinecorsa_NO_2++;}

      if(Pin_InversioneFinecorsa_NO_2>12)
      {
        Pin_InversioneFinecorsa_NO_2=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsa_NO_2--;
      if(Pin_InversioneFinecorsa_NO_2==Pin_InversioneFinecorsa_NO_1)
      {Pin_InversioneFinecorsa_NO_2--;}
      
      if(Pin_InversioneFinecorsa_NO_2==Pin_InversioneFinecorsa_NC_1)
      {Pin_InversioneFinecorsa_NC_2--;}

      if(Pin_InversioneFinecorsa_NO_2==Pin_InversioneFinecorsa_NC_2)
      {Pin_InversioneFinecorsa_NO_2--;}

      if(Pin_InversioneFinecorsa_NO_2==Pin_InversioneFinecorsa_NC_3)
      {Pin_InversioneFinecorsa_NO_2--;}

      if(Pin_InversioneFinecorsa_NO_2<=0)
      {
        Pin_InversioneFinecorsa_NO_2=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsa_NO_2);
}


void Dyn_InversioneFinecorsa_Set_Input_NC_3(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NC: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsa_NC_3++;
      if(Pin_InversioneFinecorsa_NC_3==Pin_InversioneFinecorsa_NO_1)
      {Pin_InversioneFinecorsa_NC_3++;}
      
      if(Pin_InversioneFinecorsa_NC_3==Pin_InversioneFinecorsa_NO_2)
      {Pin_InversioneFinecorsa_NC_3++;}

      if(Pin_InversioneFinecorsa_NC_3==Pin_InversioneFinecorsa_NC_1)
      {Pin_InversioneFinecorsa_NC_3++;}

      if(Pin_InversioneFinecorsa_NC_3==Pin_InversioneFinecorsa_NC_2)
      {Pin_InversioneFinecorsa_NC_3++;}

      if(Pin_InversioneFinecorsa_NC_3>12)
      {
        Pin_InversioneFinecorsa_NC_3=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsa_NC_3--;
      if(Pin_InversioneFinecorsa_NC_3==Pin_InversioneFinecorsa_NO_1)
      {Pin_InversioneFinecorsa_NC_3--;}
      
      if(Pin_InversioneFinecorsa_NC_3==Pin_InversioneFinecorsa_NO_2)
      {Pin_InversioneFinecorsa_NC_3--;}

      if(Pin_InversioneFinecorsa_NC_3==Pin_InversioneFinecorsa_NC_1)
      {Pin_InversioneFinecorsa_NC_3--;}

      if(Pin_InversioneFinecorsa_NC_3==Pin_InversioneFinecorsa_NC_2)
      {Pin_InversioneFinecorsa_NC_3--;}

      if(Pin_InversioneFinecorsa_NC_3<=0)
      {
        Pin_InversioneFinecorsa_NC_3=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsa_NC_3);
}



void Dyn_InversioneFinecorsa_Set_Input_NC_2(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NC: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsa_NC_2++;
      if(Pin_InversioneFinecorsa_NC_2==Pin_InversioneFinecorsa_NO_1)
      {Pin_InversioneFinecorsa_NC_2++;}
      
      if(Pin_InversioneFinecorsa_NC_2==Pin_InversioneFinecorsa_NC_1)
      {Pin_InversioneFinecorsa_NC_2++;}

      if(Pin_InversioneFinecorsa_NC_2==Pin_InversioneFinecorsa_NO_2)
      {Pin_InversioneFinecorsa_NC_2++;}

      if(Pin_InversioneFinecorsa_NC_2==Pin_InversioneFinecorsa_NC_3)
      {Pin_InversioneFinecorsa_NC_2++;}

      if(Pin_InversioneFinecorsa_NC_2>12)
      {
        Pin_InversioneFinecorsa_NC_2=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsa_NC_2--;
      if(Pin_InversioneFinecorsa_NC_2==Pin_InversioneFinecorsa_NO_1)
      {Pin_InversioneFinecorsa_NC_2--;}
      
      if(Pin_InversioneFinecorsa_NC_2==Pin_InversioneFinecorsa_NC_1)
      {Pin_InversioneFinecorsa_NC_2--;}

      if(Pin_InversioneFinecorsa_NC_2==Pin_InversioneFinecorsa_NC_3)
      {Pin_InversioneFinecorsa_NC_2--;}

      if(Pin_InversioneFinecorsa_NC_2==Pin_InversioneFinecorsa_NO_2)
      {Pin_InversioneFinecorsa_NC_2--;}

      if(Pin_InversioneFinecorsa_NC_2<=0)
      {
        Pin_InversioneFinecorsa_NC_2=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsa_NC_2);
}

 // ************************************************************************************
 //Set pin out
void Dyn_InversioneFinecorsa_Set_Out_1(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("Out: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsa_Out_1++;
      if(Pin_InversioneFinecorsa_Out_1==Pin_InversioneFinecorsa_Out_2)
      {
        Pin_InversioneFinecorsa_Out_1++;
      }

      if(Pin_InversioneFinecorsa_Out_1>8)
      {
        Pin_InversioneFinecorsa_Out_1=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsa_Out_1--;
      if(Pin_InversioneFinecorsa_Out_1==Pin_InversioneFinecorsa_Out_2)
      {
        Pin_InversioneFinecorsa_Out_1--;
      }

      if(Pin_InversioneFinecorsa_Out_1<=0)
      {
        Pin_InversioneFinecorsa_Out_1=8;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsa_Out_1);
}

 // ************************************************************************************
 //Set pin out

void Dyn_InversioneFinecorsa_Set_Out_2(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("Out: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsa_Out_2++;
      if(Pin_InversioneFinecorsa_Out_2==Pin_InversioneFinecorsa_Out_1)
      {
        Pin_InversioneFinecorsa_Out_2++;
      }

      if(Pin_InversioneFinecorsa_Out_2>8)
      {
        Pin_InversioneFinecorsa_Out_2=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsa_Out_2--;
      if(Pin_InversioneFinecorsa_Out_2==Pin_InversioneFinecorsa_Out_1)
      {
        Pin_InversioneFinecorsa_Out_2--;
      }

      if(Pin_InversioneFinecorsa_Out_2<=0)
      {
        Pin_InversioneFinecorsa_Out_2=8;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsa_Out_2);
}

// ***********************************************************************
//PARTE 3
void Dyn_InversioneFinecorsa_Visualizza_pin_3(uint8_t line)
{
  char Val_InversioneFinecorsa_Visualizza_3[20];
  sprintf (Val_InversioneFinecorsa_Visualizza_3, "%d NO:ciclo singolo", Pin_InversioneFinecorsa_NO_2);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsa_Visualizza_3);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

// ***********************************************************************
//PARTE 4
void Dyn_InversioneFinecorsa_Visualizza_pin_4(uint8_t line)
{
  char Val_InversioneFinecorsa_Visualizza_4[20];
  sprintf (Val_InversioneFinecorsa_Visualizza_4, "%d NC:finecorsa A1", Pin_InversioneFinecorsa_NC_2);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsa_Visualizza_4);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

// ***********************************************************************
//PARTE 5
void Dyn_InversioneFinecorsa_Visualizza_pin_5(uint8_t line)
{
  char Val_InversioneFinecorsa_Visualizza_5[20];
  sprintf (Val_InversioneFinecorsa_Visualizza_5, "%d NC:finecorsa A2", Pin_InversioneFinecorsa_NC_3);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsa_Visualizza_5);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}





// ***********************************************************************
//OUTPUT
void Dyn_InversioneFinecorsa_Visualizza_Out(uint8_t line)
{
  char Val_InversioneFinecorsa_Visualizza_Out[20];
  sprintf (Val_InversioneFinecorsa_Visualizza_Out, "Output:%d NO,%d NO", Pin_InversioneFinecorsa_Out_1,Pin_InversioneFinecorsa_Out_2);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsa_Visualizza_Out);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

 // *******************************************************************************************************************************************************
 // INVERSIONE CON FINECORSA TEMPORIZZATO
 // *******************************************************************************************************************************************************
//INPUT
//PARTE 1  
void Dyn_InversioneFinecorsaRitardo_Visualizza_pin_1(uint8_t line)
{
  char Val_InversioneFinecorsaRitardo_Visualizza_1[20];
  sprintf (Val_InversioneFinecorsaRitardo_Visualizza_1, "%d NO:ciclo auto", Pin_InversioneFinecorsaRitardo_NO_1);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsaRitardo_Visualizza_1);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

// ***********************************************************************
//PARTE 2
void Dyn_InversioneFinecorsaRitardo_Visualizza_pin_2(uint8_t line)
{
  char Val_InversioneFinecorsaRitardo_Visualizza_2[20];
  sprintf (Val_InversioneFinecorsaRitardo_Visualizza_2, "%d NC:fine ciclo", Pin_InversioneFinecorsaRitardo_NC_1);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsaRitardo_Visualizza_2);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

// ***********************************************************************
//PARTE 3
void Dyn_InversioneFinecorsaRitardo_Visualizza_pin_3(uint8_t line)
{
  char Val_InversioneFinecorsaRitardo_Visualizza_3[20];
  sprintf (Val_InversioneFinecorsaRitardo_Visualizza_3, "%d NO:ciclo singolo", Pin_InversioneFinecorsaRitardo_NO_2);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsaRitardo_Visualizza_3);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

// ***********************************************************************
//PARTE 4
void Dyn_InversioneFinecorsaRitardo_Visualizza_pin_4(uint8_t line)
{
  char Val_InversioneFinecorsaRitardo_Visualizza_4[20];
  sprintf (Val_InversioneFinecorsaRitardo_Visualizza_4, "%d NC:finecorsa A1", Pin_InversioneFinecorsaRitardo_NC_2);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsaRitardo_Visualizza_4);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}

// ***********************************************************************
//PARTE 5
void Dyn_InversioneFinecorsaRitardo_Visualizza_pin_5(uint8_t line)
{
  char Val_InversioneFinecorsaRitardo_Visualizza_5[20];
  sprintf (Val_InversioneFinecorsaRitardo_Visualizza_5, "%d NC:finecorsa A2", Pin_InversioneFinecorsaRitardo_NC_3);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsaRitardo_Visualizza_5);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}



// ***********************************************************************
//OUTPUT
void Dyn_InversioneFinecorsaRitardo_Visualizza_Out(uint8_t line)
{
  char Val_InversioneFinecorsaRitardo_Visualizza_Out[20];
  sprintf (Val_InversioneFinecorsaRitardo_Visualizza_Out, "Output:%d NO,%d NO", Pin_InversioneFinecorsaRitardo_Out_1,Pin_InversioneFinecorsaRitardo_Out_2);

  lcd.setCursor(1, line);
  lcd.print(Val_InversioneFinecorsaRitardo_Visualizza_Out);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    // ...

  }
}


// ************************************************************************************
//Set input_1 NO
void Dyn_InversioneFinecorsaRitardo_Set_Input_NO_1(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NO: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsaRitardo_NO_1++;
      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NO_1++;}
      
      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NO_1++;}

      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_1)
      {Pin_InversioneFinecorsaRitardo_NO_1++;}

      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NO_1++;}

      if(Pin_InversioneFinecorsaRitardo_NO_1>12)
      {
        Pin_InversioneFinecorsaRitardo_NO_1=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsaRitardo_NO_1--;
      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NO_1--;}
      
      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NO_1--;}

      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_1)
      {Pin_InversioneFinecorsaRitardo_NO_1--;}

      if(Pin_InversioneFinecorsaRitardo_NO_1==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NO_1--;}

      if(Pin_InversioneFinecorsaRitardo_NO_1<=0)
      {
        Pin_InversioneFinecorsaRitardo_NO_1=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsaRitardo_NO_1);

}

  // ************************************************************************************
 //Set pin NC_1
void Dyn_InversioneFinecorsaRitardo_Set_Input_NC_1(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NC: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsaRitardo_NC_1++;
      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NO_1)
      {Pin_InversioneFinecorsaRitardo_NC_1++;}
      
      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NC_1++;}

      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NC_1++;}

      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NC_1++;}

      if(Pin_InversioneFinecorsaRitardo_NC_1>12)
      {
        Pin_InversioneFinecorsaRitardo_NC_1=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsaRitardo_NC_1--;
      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NO_1)
      {Pin_InversioneFinecorsaRitardo_NC_1--;}
      
      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NC_1--;}

      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NC_1--;}

      if(Pin_InversioneFinecorsaRitardo_NC_1==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NC_1--;}

      if(Pin_InversioneFinecorsaRitardo_NC_1<=0)
      {
        Pin_InversioneFinecorsaRitardo_NC_1=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsaRitardo_NC_1);
}

 // ************************************************************************************
 //Set pin NO_2
void Dyn_InversioneFinecorsaRitardo_Set_Input_NO_2(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NO: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsaRitardo_NO_2++;
      
      if(Pin_InversioneFinecorsaRitardo_NO_2==Pin_InversioneFinecorsaRitardo_NO_1)
      {Pin_InversioneFinecorsaRitardo_NO_2++;}
      
      if(Pin_InversioneFinecorsaRitardo_NO_2==Pin_InversioneFinecorsaRitardo_NC_1)
      {Pin_InversioneFinecorsaRitardo_NC_2++;}

      if(Pin_InversioneFinecorsaRitardo_NO_2==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NO_2++;}

      if(Pin_InversioneFinecorsaRitardo_NO_2==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NO_2++;}

      if(Pin_InversioneFinecorsaRitardo_NO_2>12)
      {
        Pin_InversioneFinecorsaRitardo_NO_2=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsaRitardo_NO_2--;
      if(Pin_InversioneFinecorsaRitardo_NO_2==Pin_InversioneFinecorsaRitardo_NO_1)
      {Pin_InversioneFinecorsaRitardo_NO_2--;}
      
      if(Pin_InversioneFinecorsaRitardo_NO_2==Pin_InversioneFinecorsaRitardo_NC_1)
      {Pin_InversioneFinecorsaRitardo_NC_2--;}

      if(Pin_InversioneFinecorsaRitardo_NO_2==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NO_2--;}

      if(Pin_InversioneFinecorsaRitardo_NO_2==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NO_2--;}

      if(Pin_InversioneFinecorsaRitardo_NO_2<=0)
      {
        Pin_InversioneFinecorsaRitardo_NO_2=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsaRitardo_NO_2);
}


void Dyn_InversioneFinecorsaRitardo_Set_Input_NC_3(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NC: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsaRitardo_NC_3++;
      if(Pin_InversioneFinecorsaRitardo_NC_3==Pin_InversioneFinecorsaRitardo_NO_1)
      {Pin_InversioneFinecorsaRitardo_NC_3++;}
      
      if(Pin_InversioneFinecorsaRitardo_NC_3==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NC_3++;}

      if(Pin_InversioneFinecorsaRitardo_NC_3==Pin_InversioneFinecorsaRitardo_NC_1)
      {Pin_InversioneFinecorsaRitardo_NC_3++;}

      if(Pin_InversioneFinecorsaRitardo_NC_3==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NC_3++;}

      if(Pin_InversioneFinecorsaRitardo_NC_3>12)
      {
        Pin_InversioneFinecorsaRitardo_NC_3=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsaRitardo_NC_3--;
      if(Pin_InversioneFinecorsaRitardo_NC_3==Pin_InversioneFinecorsaRitardo_NO_1)
      {Pin_InversioneFinecorsaRitardo_NC_3--;}
      
      if(Pin_InversioneFinecorsaRitardo_NC_3==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NC_3--;}

      if(Pin_InversioneFinecorsaRitardo_NC_3==Pin_InversioneFinecorsaRitardo_NC_1)
      {Pin_InversioneFinecorsaRitardo_NC_3--;}

      if(Pin_InversioneFinecorsaRitardo_NC_3==Pin_InversioneFinecorsaRitardo_NC_2)
      {Pin_InversioneFinecorsaRitardo_NC_3--;}

      if(Pin_InversioneFinecorsaRitardo_NC_3<=0)
      {
        Pin_InversioneFinecorsaRitardo_NC_3=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsaRitardo_NC_3);
}



void Dyn_InversioneFinecorsaRitardo_Set_Input_NC_2(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("NC: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsaRitardo_NC_2++;
      if(Pin_InversioneFinecorsaRitardo_NC_2==Pin_InversioneFinecorsaRitardo_NO_1)
      {Pin_InversioneFinecorsaRitardo_NC_2++;}
      
      if(Pin_InversioneFinecorsaRitardo_NC_2==Pin_InversioneFinecorsaRitardo_NC_1)
      {Pin_InversioneFinecorsaRitardo_NC_2++;}

      if(Pin_InversioneFinecorsaRitardo_NC_2==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NC_2++;}

      if(Pin_InversioneFinecorsaRitardo_NC_2==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NC_2++;}

      if(Pin_InversioneFinecorsaRitardo_NC_2>12)
      {
        Pin_InversioneFinecorsaRitardo_NC_2=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsaRitardo_NC_2--;
      if(Pin_InversioneFinecorsaRitardo_NC_2==Pin_InversioneFinecorsaRitardo_NO_1)
      {Pin_InversioneFinecorsaRitardo_NC_2--;}
      
      if(Pin_InversioneFinecorsaRitardo_NC_2==Pin_InversioneFinecorsaRitardo_NC_1)
      {Pin_InversioneFinecorsaRitardo_NC_2--;}

      if(Pin_InversioneFinecorsaRitardo_NC_2==Pin_InversioneFinecorsaRitardo_NC_3)
      {Pin_InversioneFinecorsaRitardo_NC_2--;}

      if(Pin_InversioneFinecorsaRitardo_NC_2==Pin_InversioneFinecorsaRitardo_NO_2)
      {Pin_InversioneFinecorsaRitardo_NC_2--;}

      if(Pin_InversioneFinecorsaRitardo_NC_2<=0)
      {
        Pin_InversioneFinecorsaRitardo_NC_2=12;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsaRitardo_NC_2);
}

 // ************************************************************************************
 //Set pin out
void Dyn_InversioneFinecorsaRitardo_Set_Out_1(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("Out: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsaRitardo_Out_1++;
      if(Pin_InversioneFinecorsaRitardo_Out_1==Pin_InversioneFinecorsaRitardo_Out_2)
      {
        Pin_InversioneFinecorsaRitardo_Out_1++;
      }

      if(Pin_InversioneFinecorsaRitardo_Out_1>8)
      {
        Pin_InversioneFinecorsaRitardo_Out_1=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsaRitardo_Out_1--;
      if(Pin_InversioneFinecorsaRitardo_Out_1==Pin_InversioneFinecorsaRitardo_Out_2)
      {
        Pin_InversioneFinecorsaRitardo_Out_1--;
      }

      if(Pin_InversioneFinecorsaRitardo_Out_1<=0)
      {
        Pin_InversioneFinecorsaRitardo_Out_1=8;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsaRitardo_Out_1);
}

 // ************************************************************************************
 //Set pin out

void Dyn_InversioneFinecorsaRitardo_Set_Out_2(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("Out: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      Pin_InversioneFinecorsaRitardo_Out_2++;
      if(Pin_InversioneFinecorsaRitardo_Out_2==Pin_InversioneFinecorsaRitardo_Out_1)
      {
        Pin_InversioneFinecorsaRitardo_Out_2++;
      }

      if(Pin_InversioneFinecorsaRitardo_Out_2>8)
      {
        Pin_InversioneFinecorsaRitardo_Out_2=1;
      }
    }

    if(LCDML.BT_checkLeft() == true)
    {
      Pin_InversioneFinecorsaRitardo_Out_2--;
      if(Pin_InversioneFinecorsaRitardo_Out_2==Pin_InversioneFinecorsaRitardo_Out_1)
      {
        Pin_InversioneFinecorsaRitardo_Out_2--;
      }

      if(Pin_InversioneFinecorsaRitardo_Out_2<=0)
      {
        Pin_InversioneFinecorsaRitardo_Out_2=8;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(9, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(9, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(Pin_InversioneFinecorsaRitardo_Out_2);
}
 



void Dyn_InversioneFinecorsaRitardo_Set_Tempo_A1(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("A1: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      InversioneFinecorsaRitardo_Tempo_A1++;
    }

    if(LCDML.BT_checkLeft() == true)
    {
      InversioneFinecorsaRitardo_Tempo_A1--;

      if(InversioneFinecorsaRitardo_Tempo_A1<0)
      {
        InversioneFinecorsaRitardo_Tempo_A1=0;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(12, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(12, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(InversioneFinecorsaRitardo_Tempo_A1);
}



void Dyn_InversioneFinecorsaRitardo_Set_Tempo_A2(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print("A2: ");

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
     
      

    if(LCDML.BT_checkRight() == true)
    {
      InversioneFinecorsaRitardo_Tempo_A2++;
    }

    if(LCDML.BT_checkLeft() == true)
    {
      InversioneFinecorsaRitardo_Tempo_A2--;

      if(InversioneFinecorsaRitardo_Tempo_A2<0)
      {
        InversioneFinecorsaRitardo_Tempo_A2=0;
      }
    }
    lcd.setCursor(5, line);
    lcd.write(5);
    lcd.setCursor(12, line);
    lcd.write(6);

  }else{
    lcd.setCursor(5, line);
    lcd.print(" ");
    lcd.setCursor(12, line);
    lcd.print(" ");
     
  }
  lcd.setCursor(7, line);
  lcd.print(InversioneFinecorsaRitardo_Tempo_A2);
}



 
 // *******************************************************************************************************************************************************
 // IMPOSTAZIONI
 // *******************************************************************************************************************************************************
//ORA 
void Impostazioni_Ora (uint8_t line)
{
  char Val_Impostazioni_Ora [20];
  sprintf (Val_Impostazioni_Ora , "%02d:%02d:%02d",  dyn_hour, dyn_min, dyn_sec);

  lcd.setCursor(1, line);
  lcd.print(Val_Impostazioni_Ora);

  // resetta il timer in-screen quando viene visualizzata questa funzione
  LCDML.SCREEN_resetTimer();
  
  // controlla se questa funzione è attiva (il cursore si trova su questa linea)
  if (line == LCDML.MENU_getCursorPos())
  {
    if(LCDML.BT_checkEnter() == true)
    {
      //...
    }

  }
}


void Prova_SelezioneCarattere(uint8_t line)
{
  char Vettore_Simboli[76]={' ','A','B','C','D','E','F','G','H','I','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','J','K','Z','a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','w','y','j','k','z','1','2','3','4','5','6','7','8','9','0','+','!','?','|','/','&','_','^','<','>','(',')','='};
  
  lcd.setCursor(1, line);
  lcd.print("Lettera:");
  lcd.setCursor(10, line);
  lcd.write(5);

  lcd.setCursor(12, line);
  lcd.print(Vettore_Simboli[Val_Prova_SelezioneCarattere]);
  
  
  if (line == LCDML.MENU_getCursorPos())
  {
    lcd.setCursor(10, line);
    lcd.write(5);
    lcd.setCursor(14, line);
    lcd.write(6);
    
    if(LCDML.BT_checkRight() == true)
    {
      Val_Prova_SelezioneCarattere++;
      if(Val_Prova_SelezioneCarattere>75)
      {
        Val_Prova_SelezioneCarattere=0;
      }
    }

    if(LCDML.BT_checkLeft()== true)
    {
      Val_Prova_SelezioneCarattere--;
      if(Val_Prova_SelezioneCarattere<0)
      {
        Val_Prova_SelezioneCarattere=75;
      }
    }

    if(LCDML.BT_checkEnter()== true)
    {
      Prova_Stringa[Prova_SelezioneCarattere_posizioneStringa]=Vettore_Simboli[Val_Prova_SelezioneCarattere];
      Prova_SelezioneCarattere_posizioneStringa++;
      Val_Prova_SelezioneCarattere=0;
    }
      

  }else{
    lcd.setCursor(10, line);
    lcd.print(" ");
    lcd.setCursor(14, line);
    lcd.print(" ");
  }
}

void Prova_Stringa_SelezioneCarattere(uint8_t line)
{
  lcd.setCursor(1, line);
  lcd.print(Prova_Stringa);
}


void  Prova_Stringa_SelezioneCarattere_Cancella(uint8_t line)
{
  Prova_SelezioneCarattere_posizioneStringa--;
  if(Prova_SelezioneCarattere_posizioneStringa<0)
  {
    Prova_SelezioneCarattere_posizioneStringa=0;
  }
  
  Prova_Stringa[Prova_SelezioneCarattere_posizioneStringa]=' ';
  
  
  Val_Prova_SelezioneCarattere--;
  if(Val_Prova_SelezioneCarattere<0)
  {
    Val_Prova_SelezioneCarattere=0;
  }
  if(LCDML.FUNC_loop())
  {
      LCDML.FUNC_goBackToMenu();  // lascia questa funzione
  }

  if(LCDML.FUNC_close())
  {
    
  }
}




