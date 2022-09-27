/* ===================================================================== *
 *                                                                       *
 * Pannelli                                                              *
 *                                                                       *
 * ===================================================================== */

 /*
  * Lettura tastiera
  * Esegui pannello in base ai settaggi fatti
  */

uint16_t Input_Digitale24v_1_12()
{
  int Vettore_Input_24v[12]={Pin_1, Pin_2, Pin_3, Pin_4, Pin_5, Pin_6, Pin_7, Pin_8, Pin_9, Pin_10, Pin_11, Pin_12};
  uint16_t Val_Input;

  for(int i=0;i<12;i++)
  {
    if(digitalRead(Vettore_Input_24v[i])==HIGH)
    {
      bitWrite(Val_Input,i,1);
    }else{
      bitWrite(Val_Input,i,0);
    }
  }

    return Val_Input;
}

void Output_Funzione(uint8_t pin,uint8_t alto_basso)
{
  int Vettore_Output_pin[8]={Pin_Out_1, Pin_Out_2, Pin_Out_3, Pin_Out_4, Pin_Out_5, Pin_Out_6, Pin_Out_7, Pin_Out_8};


  if(alto_basso==1 && pin!=0)
  {
  digitalWrite(Vettore_Output_pin[pin-1],HIGH);
  }
  
  if(alto_basso==0 && pin!=0)
  {
  digitalWrite(Vettore_Output_pin[pin-1],LOW);
  }
  
}

//**********************************************************************************************************
//Marcia Arresto
void Pannello_MarciaArresto(int Pin_MA_NO, int Pin_MA_NC, int Pin_MA_Out)
{
  lcd.setCursor(0,2);
  lcd.print("Premi un tasto per");
  lcd.setCursor(0,3);
  lcd.print("tornare indietro");
  
  uint16_t Lettura_pin=Input_Digitale24v_1_12();
  
  int MA_NO_1=bitRead(Lettura_pin, Pin_MA_NO);
  int MA_NC_1=bitRead(Lettura_pin, Pin_MA_NC);

  if((MA_NO_1==1 || Stato_MA_1==1)&&MA_NC_1)
  {
    Output_Funzione(Pin_MA_Out,0);
    lcd.setCursor(0,0);
    lcd.print("Marcia              ");
  }else{
    Stato_MA_1=0;
     Output_Funzione(Pin_MA_Out,1);
     lcd.setCursor(0,0);
     lcd.print("Fermo              ");
  }
}



//**********************************************************************************************************
//Inversione
void Pannello_Inversione(int Pin_Inv_NO_1, int Pin_Inv_NC_1, int Pin_Inv_NO_2, int Pin_Inv_Out_1, int Pin_Inv_Out_2)
{
  lcd.setCursor(0,2);
  lcd.print("Premi un tasto per");
  lcd.setCursor(0,3);
  lcd.print("tornare indietro");
  uint16_t Lettura_pin=Input_Digitale24v_1_12();
  
  int Inv_NO_1=bitRead(Lettura_pin, Pin_Inv_NO_1);
  int Inv_NC_1=bitRead(Lettura_pin, Pin_Inv_NC_1);
  int Inv_NO_2=bitRead(Lettura_pin, Pin_Inv_NO_2);

  if((Inv_NO_1==1||Stato_Inv_1==1)&&Inv_NC_1&&Stato_Inv_2==0)
  {
     Output_Funzione(Pin_Inv_Out_1,0);
     lcd.setCursor(0,0);
     lcd.print("Marcia senso: 1    ");
  }else{
     Output_Funzione(Pin_Inv_Out_1,1);
     Stato_Inv_1=0;
     lcd.setCursor(0,0);
     lcd.print("Fermo    ");
  }

  if((Inv_NO_2==1||Stato_Inv_2==1)&&Inv_NC_1&&Stato_Inv_1==0)
  {
     Output_Funzione(Pin_Inv_Out_1,0);
     lcd.setCursor(0,0);
     lcd.print("Marcia senso: 2    ");
  }else{
     Output_Funzione(Pin_Inv_Out_2,1);
     Stato_Inv_2=0;
  }
  
}



//**********************************************************************************************************
//Inversone finecorsa
void Pannello_InversioneFinecorsa(int Pin_InvF_NO_1, int Pin_InvF_NC_1, int Pin_InvF_NO_2, int Pin_InvF_NC_2 , int Pin_InvF_NC_3, int Pin_InvF_Out_1, int Pin_InvF_Out_2)
{
  lcd.setCursor(0,2);
  lcd.print("Premi un tasto per");
  lcd.setCursor(0,3);
  lcd.print("tornare indietro");
  uint16_t Lettura_pin=Input_Digitale24v_1_12();
  
  int InvF_NO_1=bitRead(Lettura_pin, Pin_InvF_NO_1);
  int InvF_NC_1=bitRead(Lettura_pin, Pin_InvF_NC_2);
  int InvF_NO_2=bitRead(Lettura_pin, Pin_InvF_NO_1);
  int InvF_NC_2=bitRead(Lettura_pin, Pin_InvF_NC_2);
  int InvF_NC_3=bitRead(Lettura_pin, Pin_InvF_NC_3);

  if((InvF_NO_1==1 || Stato_InvF_1==1) && InvF_NC_1==1)
  {
    Stato_InvF_1=1;
    lcd.setCursor(0,1);
    lcd.print("Ciclo automatico");
  }else{
    Stato_InvF_1=0;
  }

  if(Stato_InvF_3==0 && Stato_InvF_2==0)
  {
    lcd.setCursor(0,1);
    lcd.print("              ");
  }

  if((InvF_NO_2==1 || Stato_InvF_1==1) && InvF_NC_2==0 && InvF_NC_3==1 && InvF_NC_1==1)
  {
    Stato_InvF_2=1;

    if(InvF_NO_2==1 && Stato_InvF_1==0)
    {
      lcd.setCursor(0,1);
      lcd.print("Ciclo singolo   ");
    }
  }

  if(Stato_InvF_2==1)
  {
    Output_Funzione(Pin_InvF_Out_1,1);
    
    lcd.setCursor(0,0);
    lcd.print("-->              ");
    
    if(InvF_NC_3==0)
    {
      Stato_InvF_2=0;
      Output_Funzione(Pin_InvF_Out_1,0);    
      Stato_InvF_3=1;
    }
  }

  if(Stato_InvF_3==1)
  {
    Output_Funzione(Pin_InvF_Out_2,1);

    lcd.setCursor(0,0);
    lcd.print("<--                  ");
    
    if(InvF_NC_2==0)
    {
      Stato_InvF_3=0;
      Output_Funzione(Pin_InvF_Out_2,0);    
    }
  }

  if(Stato_InvF_3==0 && Stato_InvF_2==0)
  {
    lcd.setCursor(0,0);
    lcd.print("Fermo       ");
  }
  

}






