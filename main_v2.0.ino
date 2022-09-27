// **********************************************************************
// include
// **********************************************************************
#include <LiquidCrystal.h>
#include <LCDMenuLib2.h>



// **********************************************************************
// Impostazioni display LCDML
// **********************************************************************
#define _LCDML_DISP_cols  20
#define _LCDML_DISP_rows  4

#define _LCDML_DISP_cfg_cursor       0x7E //Simbolo del cursore
#define _LCDML_DISP_cfg_scrollbar    1  //Attiva scrollbar Enable=1 Disable=0

const int rs_ = 22, en_ =24, d4_ = 26, d5_ = 28, d6_ = 30, d7_ = 32;
LiquidCrystal lcd(rs_, en_, d4_, d5_, d6_, d7_);

const uint8_t scroll_bar[5][8] = {    //scrollbar layout
    {B10001, B10001, B10001, B10001, B10001, B10001, B10001, B10001}, // scrollbar top
    {B11111, B11111, B10001, B10001, B10001, B10001, B10001, B10001}, // scroll  1
    {B10001, B10001, B11111, B11111, B10001, B10001, B10001, B10001}, // scroll  2
    {B10001, B10001, B10001, B10001, B11111, B11111, B10001, B10001}, // scroll  3
    {B10001, B10001, B10001, B10001, B10001, B10001, B11111, B11111}  // scrollbar bot
  };

byte display_carattere_1[8] = {
  0b00000,
  0b00011,
  0b00111,
  0b01111,
  0b11111,
  0b01111,
  0b00111,
  0b00011
};

byte display_carattere_2[8] = {
  0b00000,
  0b11000,
  0b11100,
  0b11110,
  0b11111,
  0b11110,
  0b11100,
  0b11000
};

//***********************************************************************
//Input di comando
//***********************************************************************
String Prova_Stringa="                  ";
int Prova_SelezioneCarattere_posizioneStringa=0;
int Val_Prova_SelezioneCarattere=0;



//***********************************************************************
//Input di comando
//***********************************************************************
//pin di comando
int Pin_1=57 ;
int Pin_2=55 ;
int Pin_3=53 ;
int Pin_4=51 ;
int Pin_5=49 ;
int Pin_6=47 ;
int Pin_7=45 ;
int Pin_8=43 ;
int Pin_9=41 ;
int Pin_10=39 ;
int Pin_11=37 ;
int Pin_12=35 ;

int Tastierino_pin_2=25;
int Tastierino_2=0;

//***********************************************************************
//Out put
//***********************************************************************
//pin di comando
int Pin_Out_1=52;
int Pin_Out_2=50;
int Pin_Out_3=48;
int Pin_Out_4=46;
int Pin_Out_5=44;
int Pin_Out_6=42;
int Pin_Out_7=40;
int Pin_Out_8=38;


//***********************************************************************
//Debug
//***********************************************************************
uint8_t Debug_Out_Contatore=1;
float Debug_Out_TempoScarto=500; //500ms


//***********************************************************************
//Variabili per i pannelli
//***********************************************************************
//Pannello Marcia Arresto:
//  Default:
//    INPUT
int Pin_MarciaArresto_NO=3;
int Pin_MarciaArresto_NC=4;
//    OUTPUT
int Pin_MarciaArresto_Out=1;

//Stati
boolean Stato_MA_1=0;

//**********************************
//Pannello Inversione:
//  Default:
//    INPUT
int Pin_Inversione_NO_1=3;
int Pin_Inversione_NC_1=4;
int Pin_Inversione_NO_2=5;
//    OUTPUT
int Pin_Inversione_Out_1=1;
int Pin_Inversione_Out_2=2;

//Stati
int Stato_Inv_1=0;
int Stato_Inv_2=0;



//**********************************
//Pannello InversioneFinecorsa:
//  Default:
//    INPUT
int Pin_InversioneFinecorsa_NO_1=3;
int Pin_InversioneFinecorsa_NC_1=4;
int Pin_InversioneFinecorsa_NO_2=5;
int Pin_InversioneFinecorsa_NC_2=6;
int Pin_InversioneFinecorsa_NC_3=7;
//    OUTPUT
int Pin_InversioneFinecorsa_Out_1=1;
int Pin_InversioneFinecorsa_Out_2=2;

//stati
int Stato_InvF_3=0;
int Stato_InvF_2=0;
int Stato_InvF_1=0;



//**********************************
//Pannello InversioneFinecorsa:
//  Default:
//    INPUT
int Pin_InversioneFinecorsaRitardo_NO_1=3;
int Pin_InversioneFinecorsaRitardo_NC_1=4;
int Pin_InversioneFinecorsaRitardo_NO_2=5;
int Pin_InversioneFinecorsaRitardo_NC_2=6;
int Pin_InversioneFinecorsaRitardo_NC_3=7;
//    OUTPUT
int Pin_InversioneFinecorsaRitardo_Out_1=1;
int Pin_InversioneFinecorsaRitardo_Out_2=2;

float InversioneFinecorsaRitardo_Tempo_A1=1;
float InversioneFinecorsaRitardo_Tempo_A2=1;





// **********************************************************************
// Prototipi
// **********************************************************************
void lcdml_menu_display();
void lcdml_menu_clear();
void lcdml_menu_control();



// **********************************************************************
// Variabili globali
// **********************************************************************
float Tempo_SYS=0;
float Tempo_AT_SYS=0;

// **********************************************************************
// Oggetti
// **********************************************************************
LCDMenuLib2_menu LCDML_0 (255, 0, 0, NULL, NULL); // root menu element
LCDMenuLib2 LCDML(LCDML_0, _LCDML_DISP_rows, _LCDML_DISP_cols, lcdml_menu_display, lcdml_menu_clear, lcdml_menu_control);



// *********************************************************************
// LCDML MENU/DISP
// *********************************************************************
// LCDML_0        => layer 0
// LCDML_0_X      => layer 1
// LCDML_0_X_X    => layer 2
// LCDML_0_X_X_X  => layer 3
// LCDML_0_...      => layer ...

// LCDML_add(id, prev_layer, new_num, lang_char_array, callback_function)
LCDML_add         (0  ,   LCDML_0         , 1  , "Menu"                       , NULL);
LCDML_add         (1  ,   LCDML_0         , 2  , "|1-Marcia arresto"          , NULL);
//**********************************************************************************************************
//Marcia arresto (sottomenu 2)
LCDML_add         (2   ,  LCDML_0_2       , 1  , "Marcia e arresto"           , NULL);
LCDML_addAdvanced (3   ,  LCDML_0_2       , 2  , NULL,          ""            , Dyn_MarciaArresto_Visualizza_pin  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (4   ,  LCDML_0_2       , 3  , NULL,          ""            , Dyn_MarciaArresto_Visualizza_Out  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (5   ,  LCDML_0_2       , 4  , "Impostazioni"               , NULL);
LCDML_add         (6   ,  LCDML_0_2_4     , 1  , "Impostazioni"               , NULL);
LCDML_add         (7   ,  LCDML_0_2_4     , 2  , "Set pin input"              , NULL);
LCDML_add         (8   ,  LCDML_0_2_4_2   , 1  , "Set Input"                  , NULL);
LCDML_addAdvanced (9   ,  LCDML_0_2_4_2   , 2  , NULL,          ""            , Dyn_MarciaArresto_Set_Input_NO    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (10  ,  LCDML_0_2_4_2   , 3  , NULL,          ""            , Dyn_MarciaArresto_Set_Input_NC    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (11  ,  LCDML_0_2_4_2   , 4  , "Salva ed esci"              , mFunc_back);
LCDML_add         (12  ,  LCDML_0_2_4     , 3  , "Set output"                 , NULL);
LCDML_add         (13  ,  LCDML_0_2_4_3   , 1  , "Set Output"                 , NULL);
LCDML_addAdvanced (14  ,  LCDML_0_2_4_3   , 2  , NULL,          ""            , Dyn_MarciaArresto_Set_Out         , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (15  ,  LCDML_0_2_4_3   , 3  , "Salva ed esci"              , mFunc_back);
LCDML_add         (16  ,  LCDML_0_2_4     , 4  , "Annulla"                    , mFunc_back);
LCDML_add         (17  ,  LCDML_0_2       , 5  , "Avvia"                      , MarciaArresto_Avvia);
LCDML_add         (18  ,  LCDML_0_2       , 6  , "Annulla"                    , mFunc_back);

//Impostazioni


//Set Input


//Set Output


//**********************************************************************************************************
LCDML_add         (19  ,   LCDML_0        , 3  , "|2-Inversione"              , NULL);
//Inversione (sottomenu 3)
LCDML_add         (20  ,  LCDML_0_3       , 1  , "Inversione"                 , NULL);
LCDML_addAdvanced (21  ,  LCDML_0_3       , 2  , NULL,          ""            , Dyn_Inversione_Visualizza_Out  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (22  ,  LCDML_0_3       , 3  , NULL,          ""            , Dyn_Inversione_Visualizza_pin  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (23  ,  LCDML_0_3       , 4  , "Impostazioni"               , NULL);
LCDML_add         (24  ,  LCDML_0_3_4     , 1  , "Impostazioni"               , NULL);
LCDML_add         (25  ,  LCDML_0_3_4     , 2  , "Set pin input"              , NULL);
LCDML_add         (26  ,  LCDML_0_3_4_2   , 1  , "Set Input"                  , NULL);
LCDML_addAdvanced (27  ,  LCDML_0_3_4_2   , 2  , NULL,          ""            , Dyn_Inversione_Set_Input_NO_1  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (28  ,  LCDML_0_3_4_2   , 3  , NULL,          ""            , Dyn_Inversione_Set_Input_NC_1  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (29  ,  LCDML_0_3_4_2   , 4  , NULL,          ""            , Dyn_Inversione_Set_Input_NO_2  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (30  ,  LCDML_0_3_4_2   , 5  , "Salva ed esci"              , mFunc_back);

LCDML_add         (31  ,  LCDML_0_3_4     , 3  , "Set output"                 , NULL);
LCDML_add         (32  ,  LCDML_0_3_4_3   , 1  , "Set Output"                 , NULL);
LCDML_addAdvanced (33  ,  LCDML_0_3_4_3   , 2  , NULL,          ""            , Dyn_Inversione_Set_Out_1        , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (34  ,  LCDML_0_3_4_3   , 3  , NULL,          ""            , Dyn_Inversione_Set_Out_2        , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (35  ,  LCDML_0_3_4_3   , 4  , "Salva ed esci"              , mFunc_back);

LCDML_add         (36  ,  LCDML_0_3_4     , 4  , "Annulla"                    , mFunc_back);

LCDML_add         (37  ,  LCDML_0_3       , 5  , "Avvia"                      , Inversione_Avvia);
LCDML_add         (38  ,  LCDML_0_3       , 6  , "Annulla"                    , mFunc_back);

//Impostazioni

//Set Input

//Set Output


//**********************************************************************************************************
LCDML_add         (39  ,   LCDML_0        , 4  ,"|3-Inv. finecorsa"          , NULL);
//Inversione finecorsa (sottomenu 4)
LCDML_add         (40  ,  LCDML_0_4       , 1  , "Inversione con"             , NULL);
LCDML_add         (41  ,  LCDML_0_4       , 2  , "finecorsa A1 e A2"          , NULL);
LCDML_addAdvanced (42  ,  LCDML_0_4       , 3  , NULL,          ""            , Dyn_InversioneFinecorsa_Visualizza_pin_1  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (43  ,  LCDML_0_4       , 4  , NULL,          ""            , Dyn_InversioneFinecorsa_Visualizza_pin_2  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (44  ,  LCDML_0_4       , 5  , NULL,          ""            , Dyn_InversioneFinecorsa_Visualizza_pin_3  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (45  ,  LCDML_0_4       , 6  , NULL,          ""            , Dyn_InversioneFinecorsa_Visualizza_pin_4  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (46  ,  LCDML_0_4       , 7  , NULL,          ""            , Dyn_InversioneFinecorsa_Visualizza_pin_5  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (47  ,  LCDML_0_4       , 8  , NULL,          ""            , Dyn_InversioneFinecorsa_Visualizza_Out    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (48  ,  LCDML_0_4       , 9  , "Impostazioni"               , NULL);
LCDML_add         (49  ,  LCDML_0_4       , 10 , "Avvia"                      , InversioneFinecorsa_Avvia);
LCDML_add         (50  ,  LCDML_0_4       , 11 , "Annulla"                    , mFunc_back);

//Impostazioni
LCDML_add         (51  ,  LCDML_0_4_9     , 1  , "Impostazioni"               , NULL);
LCDML_add         (52  ,  LCDML_0_4_9     , 2  , "Set pin input"              , NULL);
LCDML_add         (53  ,  LCDML_0_4_9     , 3  , "Set output"                 , NULL);
LCDML_add         (54  ,  LCDML_0_4_9     , 4  , "Annulla"                    , mFunc_back);

//Set Input
LCDML_add         (55  ,  LCDML_0_4_9_2   , 1  , "Set Input"                  , NULL);
LCDML_addAdvanced (56  ,  LCDML_0_4_9_2   , 2  , NULL,          ""            , Dyn_InversioneFinecorsa_Set_Input_NO_1    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (57  ,  LCDML_0_4_9_2   , 3  , NULL,          ""            , Dyn_InversioneFinecorsa_Set_Input_NC_1    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (58  ,  LCDML_0_4_9_2   , 4  , NULL,          ""            , Dyn_InversioneFinecorsa_Set_Input_NO_2    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (59  ,  LCDML_0_4_9_2   , 5  , NULL,          ""            , Dyn_InversioneFinecorsa_Set_Input_NC_2    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (60  ,  LCDML_0_4_9_2   , 6  , NULL,          ""            , Dyn_InversioneFinecorsa_Set_Input_NC_3    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (61  ,  LCDML_0_4_9_2   , 7  , "Salva ed esci"              , mFunc_back);

//Set Output
LCDML_add         (62  ,  LCDML_0_4_9_3   , 1  , "Set Output"                 , NULL);
LCDML_addAdvanced (63  ,  LCDML_0_4_9_3   , 2  , NULL,          ""            , Dyn_InversioneFinecorsa_Set_Out_1         , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (64  ,  LCDML_0_4_9_3   , 3  , NULL,          ""            , Dyn_InversioneFinecorsa_Set_Out_2         , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (65  ,  LCDML_0_4_9_3   , 4  , "Salva ed esci"              , mFunc_back);

//**********************************************************************************************************
LCDML_add         (66  ,   LCDML_0        , 5  ,"|4-Inv.ritardo+aut"          , NULL);
//Inversione finecorsa con ritardo all'inserzione (sottomenu 5)
LCDML_add         (67  ,  LCDML_0_5       , 1  , "Inversione con"             , NULL);
LCDML_add         (68  ,  LCDML_0_5       , 2  , "ritardo alla"               , NULL);
LCDML_add         (69 ,  LCDML_0_5       , 3  ,"inserzione con"              , NULL);
LCDML_add         (70  ,  LCDML_0_5       , 4  , "finecorsa A1 e A2"          , NULL);
LCDML_addAdvanced (71  ,  LCDML_0_5       , 5  , NULL,          ""            , Dyn_InversioneFinecorsaRitardo_Visualizza_pin_1  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (72  ,  LCDML_0_5       , 6  , NULL,          ""            , Dyn_InversioneFinecorsaRitardo_Visualizza_pin_2  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (73  ,  LCDML_0_5       , 7  , NULL,          ""            , Dyn_InversioneFinecorsaRitardo_Visualizza_pin_3  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (74  ,  LCDML_0_5       , 8  , NULL,          ""            , Dyn_InversioneFinecorsaRitardo_Visualizza_pin_4  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (75  ,  LCDML_0_5       , 9  , NULL,          ""            , Dyn_InversioneFinecorsaRitardo_Visualizza_pin_5  , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (76  ,  LCDML_0_5       , 10 , NULL,          ""            , Dyn_InversioneFinecorsaRitardo_Visualizza_Out    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (77  ,  LCDML_0_5       , 11 , "Impostazioni"               , NULL);
LCDML_add         (78  ,  LCDML_0_5       , 12 , "Avvia"                      , InversioneFinecorsaRitardo_Avvia);
LCDML_add         (79  ,  LCDML_0_5       , 13 , "Annulla"                    , mFunc_back);

//Impostazioni
LCDML_add         (80  ,  LCDML_0_5_11    , 1  , "Impostazioni"               , NULL);
LCDML_add         (81  ,  LCDML_0_5_11    , 2  , "Set pin input"              , NULL);
LCDML_add         (82  ,  LCDML_0_5_11    , 3  , "Set output"                 , NULL);
LCDML_add         (83  ,  LCDML_0_5_11    , 4  , "Set tempi"                  , NULL);
LCDML_add         (84  ,  LCDML_0_5_11    , 5  , "Annulla"                    , mFunc_back);

//Set Input
LCDML_add         (85  ,  LCDML_0_5_11_2   , 1  ,"Set Input"                  , NULL);
LCDML_addAdvanced (86  ,  LCDML_0_5_11_2   , 2  , NULL,          ""           , Dyn_InversioneFinecorsaRitardo_Set_Input_NO_1    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (87  ,  LCDML_0_5_11_2   , 3  , NULL,          ""           , Dyn_InversioneFinecorsaRitardo_Set_Input_NC_1    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (88  ,  LCDML_0_5_11_2   , 4  , NULL,          ""           , Dyn_InversioneFinecorsaRitardo_Set_Input_NO_2    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (89  ,  LCDML_0_5_11_2   , 5  , NULL,          ""           , Dyn_InversioneFinecorsaRitardo_Set_Input_NC_2    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (90  ,  LCDML_0_5_11_2   , 6  , NULL,          ""           , Dyn_InversioneFinecorsaRitardo_Set_Input_NC_3    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (91  ,  LCDML_0_5_11_2   , 7  , "Salva ed esci"             , mFunc_back);

//Set Output
LCDML_add         (92  ,  LCDML_0_5_11_3   , 1  , "Set Output"                 , NULL);
LCDML_addAdvanced (93  ,  LCDML_0_5_11_3   , 2  , NULL,          ""            , Dyn_InversioneFinecorsaRitardo_Set_Out_1         , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (94  ,  LCDML_0_5_11_3   , 3  , NULL,          ""            , Dyn_InversioneFinecorsaRitardo_Set_Out_2         , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (95  ,  LCDML_0_5_11_3   , 4  , "Salva ed esci"              , mFunc_back);

//Set Tempo
LCDML_add         (96  ,  LCDML_0_5_11_4   , 1  , "Set Tempo "                 , NULL);
LCDML_addAdvanced (97  ,  LCDML_0_5_11_4   , 2  , NULL,          ""            , Dyn_InversioneFinecorsaRitardo_Set_Tempo_A1      , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (98  ,  LCDML_0_5_11_4   , 3  , NULL,          ""            , Dyn_InversioneFinecorsaRitardo_Set_Tempo_A2      , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (99  ,  LCDML_0_5_11_4   , 4  , "Salva ed esci"              , mFunc_back);

//**********************************************************************************************************
LCDML_add         (100  ,   LCDML_0         , 6  , "|5-Vuoto "                  , NULL);
LCDML_add         (101 ,   LCDML_0         , 7  , "|6-Vuoto "                  , NULL);
LCDML_add         (102 ,   LCDML_0         , 8  , "|7-DEBUG"                   , NULL);
//Debug (sottomenu 8)
LCDML_add         (103 ,  LCDML_0_8        , 1  , "Debug:"                     , NULL);
LCDML_add         (104 ,  LCDML_0_8        , 2  , "Output"                     , Debug_Output);
LCDML_add         (105 ,  LCDML_0_8        , 3  , "Input"                      , Debug_Input);
LCDML_add         (106 ,  LCDML_0_8        , 4  , "Tastiera"                   , Debug_Tastiera);
LCDML_add         (107 ,  LCDML_0_8        , 5  , "Annulla"                    , mFunc_back);

//**********************************************************************************************************

LCDML_add         (108 ,   LCDML_0         , 9  , "|8-Impostazioni"             , NULL);
//Impostazioni (sottomenu 9)
LCDML_add         (109 ,  LCDML_0_9        , 1  , "Impostazioni:"               , NULL);
LCDML_addAdvanced (110 ,  LCDML_0_9        , 2  , NULL,          ""             , Impostazioni_Ora                    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (111 ,  LCDML_0_9        , 3  , "Inserisci"                   , NULL);
LCDML_add         (112 ,  LCDML_0_9        , 4  , "Comando uscite"              , NULL);

LCDML_add         (113 ,  LCDML_0_9_3      , 1  , "Scegli il carattere"         , NULL);
LCDML_addAdvanced (114 ,  LCDML_0_9_3      , 2  , NULL,          ""             , Prova_SelezioneCarattere            , 0  ,   _LCDML_TYPE_dynParam);
LCDML_addAdvanced (115 ,  LCDML_0_9_3      , 3  , NULL,          ""             , Prova_Stringa_SelezioneCarattere    , 0  ,   _LCDML_TYPE_dynParam);
LCDML_add         (116 ,  LCDML_0_9_3      , 4  , "Cancella"                    , Prova_Stringa_SelezioneCarattere_Cancella);


// Parte del menu Avanzate (a scopo di lucro) con più impostazioni
// Esempio per una funzione e diversi parametri
// Si consiglia di utilizzare i parametri per cambiare impostazioni come, (piccola bevanda, bevanda media, bevanda grande) o (200 ml, 400 ml, 600 ml, 800 ml) ...
// il cambio parametro può anche essere rilasciato con dynParams nel prossimo esempio
// LCDMenuLib_add(id, prev_layer,     new_num, condition,   lang_char_array, callback_function, parameter (0-255), menu function type  )
//LCDML_addAdvanced (16 , LCDML_0         , 5  , NULL,          "Parameter"      , NULL,                0,            _LCDML_TYPE_default);


LCDML_addAdvanced (117 , LCDML_0         , 10  , COND_hide,  "screensaver"        , mFunc_screensaver,        0,   _LCDML_TYPE_default);  


// numero di elementi del menu - ultimo elemento id
// questo valore deve essere uguale all'ultimo elemento del menu
#define _LCDML_DISP_cnt    117


// create menu
LCDML_createMenu(_LCDML_DISP_cnt);

//**********************************************************************************************************
//Fine Dichiarazioni
//**********************************************************************************************************
//                                          SETUP
//**********************************************************************************************************
void setup() {
  //Seriale
  Serial.begin(9600);

  pinMode(Pin_1,INPUT);
  pinMode(Pin_2,INPUT);
  pinMode(Pin_3,INPUT);
  pinMode(Pin_4,INPUT);
  pinMode(Pin_5,INPUT);
  pinMode(Pin_6,INPUT);
  pinMode(Pin_7,INPUT);
  pinMode(Pin_8,INPUT);
  pinMode(Pin_9,INPUT);
  pinMode(Pin_10,INPUT);
  pinMode(Pin_11,INPUT);
  pinMode(Pin_12,INPUT);

  pinMode(Pin_Out_1,OUTPUT);
  pinMode(Pin_Out_2,OUTPUT);
  pinMode(Pin_Out_3,OUTPUT);
  pinMode(Pin_Out_4,OUTPUT);
  pinMode(Pin_Out_5,OUTPUT);
  pinMode(Pin_Out_6,OUTPUT);
  pinMode(Pin_Out_7,OUTPUT);
  pinMode(Pin_Out_8,OUTPUT);  

  pinMode(Tastierino_pin_2,INPUT);

  //*********************************************
  //LCD
  lcd.begin(_LCDML_DISP_cols,_LCDML_DISP_rows);
  //Setta caratteri speciali per la scrollbar
  lcd.createChar(0, (uint8_t*)scroll_bar[0]);
  lcd.createChar(1, (uint8_t*)scroll_bar[1]);
  lcd.createChar(2, (uint8_t*)scroll_bar[2]);
  lcd.createChar(3, (uint8_t*)scroll_bar[3]);
  lcd.createChar(4, (uint8_t*)scroll_bar[4]);

  lcd.createChar(5, display_carattere_1);
  lcd.createChar(6, display_carattere_2);
  

  //*********************************************
  // LCDMenuLib Setup
  LCDML_setup(_LCDML_DISP_cnt);

  // Enable Menu Rollover
  LCDML.MENU_enRollover();

  // Enable Screensaver (screensaver, tempo per attivarsi in ms)
  LCDML.SCREEN_enable(mFunc_screensaver, 100000);
  //LCDML.SCREEN_disable();

  // Alcuni metodi necessari

  // È possibile passare a una funzione di menu da qualsiasi posizione con
  // LCDML.OTHER_jumpToFunc(); // il parametro è il nome della funzione
}


//**********************************************************************************************************
//                                          LOOP
//**********************************************************************************************************
unsigned long g_timer_1000ms = 0;
uint8_t dyn_hour = 0;
uint8_t dyn_min  = 0;
uint8_t dyn_sec  = 0;
boolean dyn_menu_is_displayed = false;

void loop() {
  Tempo_SYS=millis();
  Tastierino_2=digitalRead(Tastierino_pin_2);
  
    //Dividi in loop() in loop_control() e loop_menu()
    LCDML.loop_control();

    if(LCDML.TIMER_ms(g_timer_1000ms, 1000))
    {
      if(LCDML.MENU_checkDynContent() == true)
      {
        LCDML.DISP_update();
      }    
      dyn_sec++;
      if(dyn_sec==60) {
        dyn_sec = 0;
        dyn_min++;
        if(dyn_min==60) {
          dyn_min = 0;
          dyn_hour++;
        }
      }     
    }



    // chiamare il contenuto del menu "normale"
    LCDML.loop_menu();
}




