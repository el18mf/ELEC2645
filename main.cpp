/*ELEC2645 - Embedded Systems Project by Mathew Fuller */

#include "mbed.h"
#include "N5110.h"
#include <string>

//==============================================================================================
//==============================================================================================
//Pin assignment format:  lcd(IO, Ser_TX, Ser_RX, MOSI, SCLK, PWM)  
    N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
//==============================================================================================
//==============================================================================================
//buses          top(0), right(1), bottom(2), left(3), enter/side button(4)
    BusIn buttons(PC_0, PC_1, PB_0, PA_4, PA_1);
//==============================================================================================
//==============================================================================================
//PwmOut declarations
    PwmOut buzzer(PA_15); //buzzer
    PwmOut R(PB_13); //Red of LED
    PwmOut G(PB_14); //Green of LED
    PwmOut B(PB_15); //Blue of LED
//==============================================================================================
//==============================================================================================
//Digital Out
    DigitalOut Red_LED(PA_14);
    DigitalOut Green_LED(PA_0);
//==============================================================================================
//==============================================================================================
//Digital in's/Buttons
    DigitalIn top(PC_0);
    DigitalIn right(PC_1);
    DigitalIn left(PA_4);
    DigitalIn bottom(PB_0);
    DigitalIn select(PA_1);
//==============================================================================================
//==============================================================================================
//sensors (both real and simulated with pots)
    AnalogIn LDR(PC_2); //real use of LDR sensor
    AnalogIn FSR(); //real use of FSR sensor
    AnalogIn TMP_ambient(PC_3); //real use of TMP sensor
    AnalogIn TMP_Oven(PA_5); //simulated with left most Pots
    AnalogIn TMP_Stove(PA_6); //simulated with middle Pots
//==============================================================================================
//==============================================================================================
//struct's 
    //struct song{ //disabled the struct as for some reason if the struct was used, it would cause the 2nd triggering of the song playing to get stuck on 1 note and crash the mbed via stack overflow
//==============================================================================================
//==============================================================================================
//Notes, frequencies & durations of songs
    //defined notes for the pirates of the caribbean alarm song
    #define NOTE_C4 262
    #define NOTE_D4 294
    #define NOTE_E4 330
    #define NOTE_F4 349
    #define NOTE_G4 392
    #define NOTE_A4 440
    #define NOTE_B4 494
    #define NOTE_C5 523
    #define NOTE_D5 587
    #define NOTE_E5 659
    #define NOTE_F5 698
    #define NOTE_G5 784
    #define NOTE_A5 880
    #define NOTE_B5 988
    //defined notes for the doom song for indicator/heat level reached...time to rip & tear those ingredients
    #define NOTE_B0  31
    #define NOTE_C1  33
    #define NOTE_CS1 35
    #define NOTE_D1  37
    #define NOTE_DS1 39
    #define NOTE_E1  41
    #define NOTE_F1  44
    #define NOTE_FS1 46
    #define NOTE_G1  49
    #define NOTE_GS1 52
    #define NOTE_A1  55
    #define NOTE_AS1 58
    #define NOTE_B1  62
    #define NOTE_C2  65
    #define NOTE_CS2 69
    #define NOTE_D2  73
    #define NOTE_DS2 78
    #define NOTE_E2  82
    #define NOTE_F2  87
    #define NOTE_FS2 93
    #define NOTE_G2  98
    #define NOTE_GS2 104
    #define NOTE_A2  110
    #define NOTE_AS2 117
    #define NOTE_B2  123
    #define NOTE_C3  131
    #define NOTE_CS3 139
    #define NOTE_D3  147
    #define NOTE_DS3 156
    #define NOTE_E3  165
    #define NOTE_F3  175
    #define NOTE_FS3 185
    #define NOTE_G3  196
    #define NOTE_GS3 208
    #define NOTE_A3  220
    #define NOTE_AS3 233
    #define NOTE_B3  247
    #define NOTE_C4  262
    #define NOTE_CS4 277
    #define NOTE_D4  294
    #define NOTE_DS4 311
    #define NOTE_E4  330
    #define NOTE_F4  349
    #define NOTE_FS4 370
    #define NOTE_G4  392
    #define NOTE_GS4 415
    #define NOTE_A4  440
    #define NOTE_AS4 466
    #define NOTE_B4  494
    #define NOTE_C5  523
    #define NOTE_CS5 554
    #define NOTE_D5  587
    #define NOTE_DS5 622
    #define NOTE_E5  659
    #define NOTE_F5  698
    #define NOTE_FS5 740
    #define NOTE_G5  784
    #define NOTE_GS5 831
    #define NOTE_A5  880
    #define NOTE_AS5 932
    #define NOTE_B5  988
    #define NOTE_C6  1047
    #define NOTE_CS6 1109
    #define NOTE_D6  1175
    #define NOTE_DS6 1245
    #define NOTE_E6  1319
    #define NOTE_F6  1397
    #define NOTE_FS6 1480
    #define NOTE_G6  1568
    #define NOTE_GS6 1661
    #define NOTE_A6  1760
    #define NOTE_AS6 1865
    #define NOTE_B6  1976
    #define NOTE_C7  2093
    #define NOTE_CS7 2217
    #define NOTE_D7  2349
    #define NOTE_DS7 2489
    #define NOTE_E7  2637
    #define NOTE_F7  2794
    #define NOTE_FS7 2960
    #define NOTE_G7  3136
    #define NOTE_GS7 3322
    #define NOTE_A7  3520
    #define NOTE_AS7 3729
    #define NOTE_B7  3951
    #define NOTE_C8  4186
    #define NOTE_CS8 4435
    #define NOTE_D8  4699
    #define NOTE_DS8 4978
    #define REST      0

    int notes[203] = {
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4, 0,

    NOTE_A4, NOTE_A4,
    //Repeat of first part
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
    NOTE_A4, NOTE_G4, NOTE_A4, 0,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
    NOTE_D5, NOTE_E5, NOTE_A4, 0,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
    NOTE_C5, NOTE_A4, NOTE_B4, 0,
    //End of Repeat

    NOTE_E5, 0, 0, NOTE_F5, 0, 0,
    NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
    NOTE_D5, 0, 0, NOTE_C5, 0, 0,
    NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

    NOTE_E5, 0, 0, NOTE_F5, 0, 0,
    NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
    NOTE_D5, 0, 0, NOTE_C5, 0, 0,
    NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4};

    int durations[203] = {
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 125, 250, 125,

    125, 125, 250, 125, 125,
    250, 125, 250, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 375,

    250, 125,
    //Rpeat of First Part
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 125,

    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 250, 125, 125,
    125, 125, 125, 250, 125,

    125, 125, 250, 125, 125,
    250, 125, 250, 125,
    125, 125, 250, 125, 125,
    125, 125, 375, 375,
    //End of Repeat

    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 125, 125, 125, 375,
    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 500,

    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 125, 125, 125, 375,
    250, 125, 375, 250, 125, 375,
    125, 125, 125, 125, 125, 500};//};
//==============================================================================================
//==============================================================================================
//initiliasations to set up buttons, lcd, leds etc.
    void init_buttons(); //initialise buttons
    void init_lcd(); //intialise lcd
//==============================================================================================
//==============================================================================================
//Main Menu system
    void main_menu();
    //std::string main_options[2] = {"Cooking Menu", "Ambient Control"};
    //std::string cook_menu[3] = {"Recipes", "Set Alarm", "Temp Sensors"};
    //std::string ambient_control[2] = {"Lighting", "Heating"};

//==============================================================================================
//==============================================================================================
//cooking menu sub-sections and related
    void cooking_menu();
    void recipes(),recipe_1(),r1_method(),recipe_2(),recipe_3(),recipe_4();
    /*void recipe_1();
    void r1_method();
    void recipe_2();
    void recipe_3();
    void recipe_4();*/
    void set_alarm(),alarm_set(),set_interrupt(int),alarm_trigger();
    /*void alarm_set();
    void set_interrupt(int);
    void alarm_trigger();*/
    int j=0;

//==============================================================================================
//==============================================================================================
//sensor menu & sub-menu's
    void sensors_menu();
    void cooking_temp();
    void stove_temp();
    void stove_indicator(int, int);
    void oven_temp();
    void oven_indicator(int);
    void ambient_temp();

//==============================================================================================
//==============================================================================================
//control menu & sub-menu's
    void control_menu();

    void lighting();
    void lux_level_set();
    void light_colour(int,int,int);
    void red();
    void green();
    void blue();
    void init_RGB();

    int heat_val=20;

    std::string colour_choice[8] = {"Red", "Green", "Blue", "Yellow", "Sky Blue", "Orange", "Gold", "Purple"};

    float Colour_red[3] = {1.0,0.0,0.0};  
    float Colour_green[3] = {0.0,1.0,0.0};
    float Colour_blue[3] = {0.0,0.0,1.0};
    float Colour_yellow[3] = {1.0,1.0,0.0};
    float Colour_skyblue[3] = {0.53,0.81,0.92};
    float Colour_orange[3] = {1.0,0.65,0.0};
    float Colour_gold[3] = {1.0,0.84,0.0};
    float Colour_purple[3] = {0.5,0.0,0.5};

    //float r_fsm[8] = {1.0,0.0,0.0,1.0,135.0/255,1.0,1.0,128.0/255};
    //float g_fsm[8] = {0.0,1.0,0.0,1.0,206.0/255,165.0/255,0.84};
    //float b_fsm[8] = {0.0,0.0,1.0,0.0,235.0/255,0.0,0.0,128.0/255};

    float red_level;
    float blue_level;
    float green_level;

    void heating();
    void status();
    void heating_control();
    void set_heat(int);
    void temp_interrupt();

    void tmp_isr();
    //void tmpfall_isr(); //these were from an attempt to use a rising and falling interrupt with the temperature sensor so it would update the temp value/heating controls whenever the temperature changed however I decided a time-based interrupt was a better idea
    //void tmprise_isr();

    int h_val=0;

    std::string heating_o[2] = {"Heat Control", "Status"};
    std::string heater_status = "Off";
    std::string aircon_status = "Off";
    volatile int heater_temp;
    volatile int aircon_temp;

    int light_o;
    int lo=0;
    int col_val=0;

    std::string light_options[2] = {"Set Light lvl","Set Colour"};
    std::string lux_levels[4] = {"Dim","Normal","Work Lighting","Turn On/Off"};

    float lux_lvl_val[3] = {85,170,255};
    float dim=0.3333333;
    float Normal = 0.6666667;
    float Work_Place = 1;


    
//==============================================================================================
//==============================================================================================
//alarm playing
    void playnote();
    void play(int);
    void play_indicators();
//==============================================================================================
//Interrupts
//==============================================================================================
    void check_interrupts(int);
    
    
    
    //==============================================================================================
    //interrupt objects/tickers
        Ticker alarmticker;
        Ticker tmpticker;

    //==============================================================================================
    //==============================================================================================
    //Interrupt In's
        //InterruptIn ldr_I(); //real use of LDR sensor
        //InterruptIn fsr_I(); //real use of FSR sensor
        //InterruptIn tmp_i(PC_3); //real use of TMP sensor
        //InterruptIn pots_oven(PA_5); //simulated with left most Pots
        //InterruptIn pots_tove_I(PA_6); //simulated with middle Pots
    //==============================================================================================
    //==============================================================================================
    //volatile declarations
        volatile int alarm_flag = 0, stove_flag = 0, oven_flag = 0, lux_isr = 0, /*tmp_flagR=0, tmp_flagF=0,*/tmp_val=20, current_tmp=0,tmp_flag=0;
        /*volatile int stove_flag = 0;
        volatile int oven_flag = 0;
        volatile int lux_isr = 0;*/
        int alarm_active = 0;
    //==============================================================================================
    //==============================================================================================
    //function prototype's
        void alarm_isr(),stove_isr(),oven_isr(),ldr_isr(),room_isr();
        /*void stove_isr();
        void oven_isr();
        void ldr_isr();
        void room_isr();
        void indicator();*/

    //==============================================================================================
//==============================================================================================
//variables
    int timer = 1, number=0,i=1,a_state = 0,frequency(),tempo = 225,wholenote = (60000 * 4) / tempo,divider = 0, noteDuration = 0, b_state, play_return, chosen_temp, oven_set;
    float alarm = 0;
    string temp_levels[3] = {"low", "medium", "high"};
    //==============================================================================================
    int temp_lvls[3] = {120,175,230};
    /*int number = 0;
    int i=1;
    int a_state = 0; //alarm interrupt state
    int frequency(); //variable used to store frequency used with the buzzer
    int tempo = 225; //tempo for doom song/indicator 
    int wholenote = (60000 * 4) / tempo; //calculates tempo/allows future customisation
    int divider = 0, noteDuration = 0;
    int b_state;*/
//==============================================================================================
//==============================================================================================
//sensor variables
    int lux_val = 100,a_val = 330,o_val = 330,s_val = 330,fsr_val = 100,indi_val = 100; //light dependant resistor value, multiplied to 100 to make it %'s
    /*int a_val = 330; //room's ambient temp value, multiplied by 330 as the sensor is 10mv/C thus the 3.3 volt output means a 330 celsius range
    int o_val = 330; //Oven temp value, multiplied by 330 as the sensor is 10mv/C thus the 3.3 volt output means a 330 celsius range thus this is done to simulate the actual sensor
    int s_val = 330; //stove temp value, multiplied by 330 as the sensor is 10mv/C thus the 3.3 volt output means a 330 celsius range thus this is done to simulate the actual sensor
    int fsr_val = 100; //force sensitive resistor value, multiplied to 100 to make it %'s
    int indi_val = 100; //stores indicator values*/
//==============================================================================================
//==============================================================================================
//char Const's
    //used to store the string/characters of the values that allows them to be printing using printString
    char const *char_timer,*a_temp = "0",*s_temp = "0",*o_temp = "0",*lux = "0"; //timer value
    /*char const *a_temp = "0"; //ambient temp
    char const *s_temp = "0"; //stove temp
    char const *o_temp = "0"; //oven temp
    char const *lux = "0"; //ambient light levels
    char const *indi = "100";*/
//==============================================================================================


int main() {
    
     //greyed out as I was worried it would blank-out my lcd screen again as this is the last thing I added before that occured
    init_buttons();
    init_lcd();
    main_menu();
}

//==================================================================
//intialisation's of components
//==================================================================
    //button initialisation
    void init_buttons(){ 
        buttons.mode(PullNone);};
    //==============================================================
    //lcd initialisation
    void init_lcd(){
        lcd.init(LPH7366_1);        //initialise LPH7366-1
        lcd.setContrast(0.55);      // contrst = 55%
        lcd.setBrightness(0.50);     //brightness = 50% 
        lcd.clear();
    }
    void init_RGB(){
        R.write(0.0);                 //initialise leds with inital PWM value to 0.0 = 0%
        G.write(0.0); 
        B.write(1.0);
            
        R.period(1.0/100);        //set the period of the wave form as 1/100Hz
        G.period(1.0/100); 
        B.period(1.0/100);
        }
    

//==================================================================
//Interrupt Checking
//==================================================================
    

    void check_interrupts(){
        if (alarm_active==1){alarm_trigger();}
        temp_interrupt();
        return;
    }
//==================================================================
//Song/Alarm Sound play
//==================================================================
    void playnote(int frequency, int wait){
        lcd.inverseMode();
        lcd.refresh();
        if(frequency == 0) {
            ThisThread::sleep_for(1ms*wait);
        } else{    
        buzzer.period_us((float) 1000000.0f/ (float) frequency);    //set the period of the pwm signal (in us)
        buzzer.pulsewidth_us(buzzer.read_period_us()/2);            //set pulse width of the pwm to 1/2 the period
        ThisThread::sleep_for(1ms*wait);}                               //play sound for 500ms
        }
    //==============================================================================================
    void play(int){
    int totalnotes = 0;
    totalnotes = 203;
    while(1){
        for(int note=0; note < totalnotes; note++){
            lcd.normalMode();
            lcd.refresh();
            playnote(/*song().*/notes[note],/*song().*/durations[note]);
            if(select.read()==1){buzzer.pulsewidth(0);
            if (play_return==1){alarm_active=0;lcd.normalMode();return;}
            else if (play_return==2) {lcd.normalMode();lcd.refresh();oven_temp();}
            else if (play_return==3) {lcd.normalMode();lcd.refresh();stove_temp();}
            }
        }
        
    }
    }
    //==================================================================
    /*void play_indicators(){ //no longer need, keeping just in case
        ThisThread::sleep_for(150ms);
        int totalnotes = sizeof(song().notes) / sizeof(int);
        while(1){
            for(int note=0; note < totalnotes; note++){
                playnote(song().notes[note],song().durations[note]);
                if(select.read()==1){buzzer.pulsewidth(0);cooking_temp();}
            }
            
        }}*/

//==================================================================
//main menu
//==================================================================
    void main_menu(){
        lcd.clear();

        lcd.printString("==============", 0, 0);
        lcd.printString("     KASS", 0, 1);
        lcd.printString("==============", 0, 2);
        lcd.printString("-  cooking", 0, 3);
        lcd.printString("-  sensors", 0, 4);
        lcd.printString("-  controls", 0, 5);
        ThisThread::sleep_for(500ms);  //sleep for 2 seconds
        lcd.refresh();
        while (1) {
        check_interrupts();
        if (top.read() == 1) {cooking_menu();}
        else if (left.read()==1||right.read()==1){sensors_menu();}
        else if (bottom.read()==1){control_menu();}
        else if (select.read()==1){main_menu();}}}

//==================================================================
//cooking sub-section menu's
//==================================================================
    void cooking_menu(){

        lcd.clear();
        lcd.printString("==============", 0, 0);
        lcd.printString(" cooking menu ", 0, 1);
        lcd.printString("==============", 0, 2);
        lcd.printString("- set alarm   ", 0, 3);
        lcd.printString("-   recipes   ", 0, 4);
        lcd.printString("-    back     ", 0, 5);
        lcd.refresh();

        ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds
        
        while (1) {
            check_interrupts(); //checks to see if any interrupts have been triggered
            if (top.read() == 1) {set_alarm();}
            else if (left.read()==1||right.read()==1){recipes();}
            else if (bottom.read()==1){main_menu();}}}
    //==============================================================================================
    //Alarm
        void set_alarm(){

            //sets character limit so that the timer does not go into the negative nor goes over the character size limits left over on section y1 (which is 4 characters after the Minutes:)
            if (timer <= 1) {
                timer = 1;
            } else if(timer >=9999) {
                timer = 9999;
            }

            //converts timer to a string, so that it can then be turned into a char const which is required to print using lcd.printString
            std::string s_timer = std::to_string(timer);
            char const *char_timer = s_timer.c_str(); 

            lcd.clear();

                //prints set timer menu and updates the current timer value
                lcd.printString("==============", 0, 0);
                lcd.printString("minutes: ", 0, 1);
                lcd.printString(char_timer, 48, 1); //prints the current value of the timer, and is at x=48 so that it directly follows the Minutes: 
                lcd.printString("==============", 0, 2);
                lcd.printString("  select time ", 0, 3);
                lcd.printString("<= - set + => ", 0, 4); //shows that the left button reduces the value, and that the right button increases the value
                lcd.printString("    Back      ", 0, 5);
                lcd.refresh();
                ThisThread::sleep_for(400ms);
            while(1) {
                if (top.read()==1){
                    alarm_set();
                } //confirms the current value of timer as the length of the alarm

                else if(right.read()==1){timer++;set_alarm();} //sets the right button to increase the value of the timer/alarm
                else if(left.read()==1){timer--;set_alarm();} //sets the left button to decrease teh value of the timer/alarm
                else if (bottom.read()==1){cooking_menu();} //cancels setting the alarm and returns to the cooking menu
                check_interrupts();

            }        }
        //==============================================================================================
        void alarm_set(){
            std::string s_timer = std::to_string(timer);
            char const *char_timer = s_timer.c_str(); 
                lcd.clear();
                lcd.printString("==============", 0, 0);
                lcd.printString(" Min Alarm", 24, 1);
                lcd.printString(char_timer, 0, 1); //prints the current value of the timer, and is at x=48 so that it directly follows the Minutes: 
                lcd.printString("==============", 0, 2);
                lcd.printString("Confirm Alarm ", 0, 3);
                lcd.printString("    Cancel    ", 0, 4); //shows that the left button reduces the value, and that the right button increases the value
                lcd.printString("     Back     ", 0, 5);
                lcd.refresh();
                ThisThread::sleep_for(500ms);
            while(1) {
                check_interrupts();
                if (top.read()==1){
                    Red_LED=1;
                    alarm_active = 1;
                    set_interrupt(timer);            
                    set_alarm();
                }else if(right.read()==1||left.read()==1){cooking_menu();} //sets the right button to increase the value of the timer/alarm
                else if (bottom.read()==1){set_alarm();} //cancels setting the alarm and returns to the cooking menu
            }        }
        //==============================================================================================
        void set_interrupt(int){
            alarmticker.attach(&alarm_isr,60s*timer);}
        //==============================================================================================
        void alarm_isr(){
            alarm_flag = 1;}
        //==============================================================================================
        void alarm_trigger(){
                //Green=!Green;
                if (alarm_flag==1&&alarm_active==1){alarm_flag = 0; alarm_active = 0; timer = 1; //sets alarm flag to 0 disabling it, sets alarm_active to 0 telling the program that the alarm is no longer active, resets alarm LED, resets timer
                    Red_LED=0;
                    play(play_return=1); //plays alarm song/sound
                }else {return;}}
    //==============================================================================================
    //==============================================================================================
    //Recipes
        void recipes(){
            //to make it so that the selection will revolve around, thus allowing you to press just left or right 
            ThisThread::sleep_for(100ms);

            if (number >3){
                number = 0;
            } else if (number <0) {
                number = 3;
            }
            string r_names[4] = {"  Cloud Bread ", " Ham & Cheese ", "  Tomato Soup ", " Chicken Pizza "};  //stored strings of the names of each recipe, only completed one so far is Cloud Bread
            char const *char_recipe = r_names[number].c_str();
            lcd.clear();
            lcd.printString("==============", 0, 0);
            lcd.printString("    Recipes   ", 0, 1);
            lcd.printString("==============", 0, 2);
            //lcd.printString("-  ", 0, 3);
            lcd.printString(char_recipe, 0, 3); //prints recipes name
            lcd.printString("<-  Select  ->", 0, 4);
            lcd.printString("-    Back     ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds
            
            while (1) {
                check_interrupts();
                if (top.read() == 1) {
                    if (number==0) {recipe_1();}
                    else if (number==1) {recipe_2();}
                    else if (number==2) {recipe_3();}
                    else if (number==3) {recipe_4();}}
                else if (left.read()==1){number--; recipes();}
                else if (right.read()==1){number++; recipes();}
                else if (bottom.read()==1){cooking_menu();}        
            }
        }
        //============================================================================================== 
        //Only filled out recipe was recipe 1, or cloud bread, just wanted to show how a full compeleted one would work out. I was going to fill them all in after I had finished everything at the end of the project, but as I had issues with my lcd I lost too much time and was unable to do so
        void recipe_1(){
            lcd.clear();
            lcd.printString("==============", 0, 0);
            lcd.printString("  Cloud Bread ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString("- Ingredients ", 0, 3);
            lcd.printString("-   Method    ", 0, 4);
            lcd.printString("-    Back     ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds
            
            while (1) {
                check_interrupts();
                if (left.read() == 1||right.read()==1) {r1_method();}    
                else if (top.read()==1){
                    lcd.clear();
                    lcd.printString("- 3 Eggs      ", 0, 0);
                    lcd.printString("-1/8 tsp cream", 0, 1);
                    lcd.printString("  of tartar   ", 0, 2);
                    lcd.printString("- 3 tbps Greek", 0, 3);
                    lcd.printString("  yoghurt     ", 0, 4);
                    lcd.printString("-    Back     ", 0, 5);
                    lcd.refresh();
                    ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds
                    while(1) {
                    check_interrupts();
                    if (bottom.read()==1||left.read()==1||right.read()==1){recipe_1();}}
                }
                else if (bottom.read()==1){recipes();}
            }
        }
        //==============================================================================================
        void r1_method(){
                ThisThread::sleep_for(250ms);
                if (i<1||i>6) {i=1;recipe_1();}
                    switch (i){ //switch statement allowing you to scroll through the method pages
                            case 1:
                                //lcd.clear();
                                lcd.printString("1.Oven = 150C", 0, 0);
                                lcd.printString("2.Separate eggs", 0, 1);
                                lcd.printString("into two bowls ", 0, 2);
                                lcd.printString("3.Add cream of ", 0, 3);
                                lcd.printString("tartar->eggWyts", 0, 4);
                                lcd.printString("<-Back | Next->", 0, 5);
                                lcd.refresh();

                                ThisThread::sleep_for(250ms);  //sleep for 500 miliseconds
                                break;            
                            case 2:    
                                
                                lcd.printString("4.Add yoghurt &", 0, 0);
                                lcd.printString("combine by mix ", 0, 1);
                                lcd.printString("5.Fold 1/2 egg ", 0, 2);
                                lcd.printString("wyts in2 yolks.", 0, 3);
                                lcd.printString("Add rest & fold", 0, 4);
                                lcd.printString("<-Back | Next->", 0, 5);
                                lcd.refresh();
                                ThisThread::sleep_for(250ms);  //sleep for 500 miliseconds
                                break;
                            
                            case 3:
                                lcd.clear();
                                lcd.printString("6.Line baking ", 0, 0);
                                lcd.printString("sheet wth papr", 0, 1);
                                lcd.printString("&place 6 dollps", 0, 2);
                                lcd.printString("wyts in2 yolks.", 0, 3);
                                lcd.printString("               ", 0, 4);
                                lcd.printString("<-Back | Next->", 0, 5);
                                lcd.refresh();
                                ThisThread::sleep_for(250ms);  //sleep for 500 miliseconds
                                break;
                            
                            case 4:
                                lcd.clear();
                                lcd.printString("Spread out the", 0, 0);
                                lcd.printString("circles with a ", 0, 1);
                                lcd.printString("spatula to 1 cm", 0, 2);
                                lcd.printString("thick          ", 0, 3);
                                lcd.printString("7. Bake = 30 min", 0, 4);
                                lcd.printString("      Done      ", 0, 5);
                                lcd.refresh();
                                ThisThread::sleep_for(250ms);
                                break;
                                
                            case 5:
                                i=1;
                                recipe_1();
                                break;
                            default:
                                i=1;
                                break;}
            while(1){
                check_interrupts();
                if(left.read()==1){i--;r1_method();ThisThread::sleep_for(300ms);}
                else if (right.read()==1){i++;r1_method();ThisThread::sleep_for(300ms);}}
        }
        //==============================================================================================
        void recipe_2(){
            lcd.printString("==============", 0, 0);
            lcd.printString(" Cooking Menu ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString("- Ingredients ", 0, 3);
            lcd.printString("-   Method    ", 0, 4);
            lcd.printString("-    Back     ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds
            
            while (1) {
                check_interrupts();
                if (top.read() == 1) {set_alarm();}
                else if (left.read()==1||right.read()==1){recipes();}
                else if (bottom.read()==1){recipes();}
            }
        }
        //==============================================================================================
        void recipe_3(){
            lcd.printString("==============", 0, 0);
            lcd.printString(" Cooking Menu ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString("- Ingredients ", 0, 3);
            lcd.printString("-   Method    ", 0, 4);
            lcd.printString("-    Back     ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds
            
            while (1) {
                check_interrupts();
                if (top.read() == 1) {set_alarm();}
                else if (left.read()==1||right.read()==1){recipes();}
                else if (bottom.read()==1){recipes();}
            }
        }
        //==============================================================================================
        void recipe_4(){
            lcd.printString("==============", 0, 0);
            lcd.printString(" Cooking Menu ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString("- Ingredients ", 0, 3);
            lcd.printString("-   Method    ", 0, 4);
            lcd.printString("-    Back     ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds
            
            while (1) {
                check_interrupts();
                if (top.read() == 1) {set_alarm();}
                else if (left.read()==1||right.read()==1){recipes();}
                else if (bottom.read()==1){recipes();}
            }
        }
    //==============================================================================================
//==================================================================
//control sub-section's menus
    //==================================================================
    void control_menu(){
        lcd.clear();
        lcd.printString("==============", 0, 0);
        lcd.printString("   controls   ", 0, 1);
        lcd.printString("==============", 0, 2);
        lcd.printString("-  lighting   ", 0, 3);
        lcd.printString("-   heating   ", 0, 4);
        lcd.printString("-    back     ", 0, 5);
        lcd.refresh();
        ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds
        
            while (1) {
            check_interrupts();
            if (top.read() == 1) {lighting();}
            else if (left.read()==1 || right.read()==1){heating();}
            else if (bottom.read()==1){main_menu();}}
    }
    //==================================================================
    void lighting(){

        init_RGB(); 
        
        red_level = R.read();
        green_level = G.read();
        blue_level = B.read();      
        
                    //sets character limit so that the timer does not go into the negative nor goes over the character size limits left over on section y1 (which is 4 characters after the Minutes:)
        if (lo < 0) {
                lo = 1;    }
        else if(lo >1) {
                lo = 0;
            }
            
            char const *light_option = light_options[lo].c_str(); 

            lcd.clear();

                //Choose whether to set an auto-turn on the LED light if the Lux goes below a certain value, or to choose which colour to use
                lcd.printString("==============", 0, 0);
                lcd.printString(" Control Menu ", 0, 1);
                lcd.printString("==============", 0, 2);
                lcd.printString(light_option, 0, 3);
                lcd.printString("<=         => ", 0, 4); //shows that the left button reduces the value, and that the right button increases the value
                lcd.printString("    Back      ", 0, 5);
                lcd.refresh();
                ThisThread::sleep_for(400ms);
            while (1){
                check_interrupts(); //checks to see if an interrupt has triggered
                if (top.read()==1){
                    if (lo==0){lux_level_set();}
                    else if (lo==1){light_colour(red_level,green_level,blue_level);}
                }
                else if (right.read()==1){lo++;lighting();}
                else if (left.read()==1){lo--;lighting();}
                else if (bottom.read()==1){control_menu();}
            }}
    //==================================================================
    void lux_level_set(){

        if (lo < 0) {
                lo = 3;    }
        else if(lo >3) {
                lo = 0;
        }
        char const *light_option = lux_levels[lo].c_str(); 

        lcd.clear();

            //Choose whether to set an auto-turn on the LED light if the Lux goes below a certain value, or to choose which colour to use
            lcd.printString("==============", 0, 0);
            lcd.printString("Set Lux Level ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString(light_option, 0, 3);
            lcd.printString("<=         => ", 0, 4); //shows that the left button reduces the value, and that the right button increases the value
            lcd.printString("    Back      ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(400ms);
            while (1){
                check_interrupts(); //checks to see if an interrupt has triggered
                if (top.read()==1){
                    if (lo==0){R.write(dim);G.write(dim);B.write(dim);init_lcd();}
                    else if (lo==1){R.pulsewidth(Normal);G.write(Normal);;B.write(Normal);init_lcd();}
                    else if (lo==2){R.write(Work_Place);G.write(Work_Place);B.write(Work_Place);init_lcd();}
                    else if (lo==3){ if(R.read()!=0) {R.write(0),G.write(0),B.write(0);init_lcd();lcd.setBrightness(0.5);lcd.refresh();lighting();} else {R.write(1),G.write(1),B.write(1);init_lcd();}}}
                else if (right.read()==1){lo++;lux_level_set();}
                else if (left.read()==1){lo--;lux_level_set();}
                else if (bottom.read()==1){lighting();}
            }}
    //==================================================================
    //an attempt to allow the ability to change the colour of the lights, however I was not able to figure out why it wouldn't work and prioritise on my stated functions instead of focusing on an extra just because I was interested in it
    void light_colour(int,int,int){
        ThisThread::sleep_for(50ms);

        if (col_val < 0) {
                col_val = 7;    }
        else if(col_val >7) {
                col_val = 0;
        }
        char const *colour_option = colour_choice[col_val].c_str(); 

        lcd.clear();

        //Choose whether to set an auto-turn on the LED light if the Lux goes below a certain value, or to choose which colour to use
        lcd.printString("==============", 0, 0);
        lcd.printString("  Set Colour  ", 0, 1);
        lcd.printString("==============", 0, 2);
        lcd.printString(colour_option, 0, 3);
        lcd.printString("<=         => ", 0, 4); //shows that the left button reduces the value, and that the right button increases the value
        lcd.printString("    Back      ", 0, 5);
        lcd.refresh();
        ThisThread::sleep_for(400ms);
        while (1){
            check_interrupts(); //checks to see if an interrupt has triggered
            if (select.read()==1) {init_lcd();}
            else if (top.read()==1){


                if (lo==0) {R.write(1.0);G.write(0);B.write(0);return;}
                else if (lo==1) {
                    R.write(Colour_green[0]);G.write(Colour_green[1]*green_level);B.write(Colour_green[2]*blue_level);}
                else if (lo==2) {R.write(Colour_blue[0]*red_level);G.write(Colour_blue[1]*green_level);B.write(Colour_blue[2]*blue_level);}
                else if (lo==3) {R.write(Colour_yellow[0]*red_level);G.write(Colour_yellow[1]*green_level);B.write(Colour_yellow[2]*blue_level);}
                else if (lo==4) {R.write(Colour_skyblue[0]*red_level);G.write(Colour_skyblue[1]*green_level);B.write(Colour_skyblue[2]*blue_level);}
                else if (lo==5) {R.write(Colour_orange[0]*red_level);G.write(Colour_orange[1]*green_level);B.write(Colour_orange[2]*blue_level);}
                else if (lo==6) {R.write(Colour_gold[0]*red_level);G.write(Colour_gold[1]*green_level);B.write(Colour_gold[2]*blue_level);}
                else if (lo==7) {R.write(Colour_purple[0]*red_level);G.write(Colour_purple[1]*green_level);B.write(Colour_purple[2]*blue_level);}
            }
            else if (right.read()==1){col_val++;light_colour(red_level,green_level,blue_level);}
            else if (left.read()==1){col_val--;light_colour(red_level,green_level,blue_level);}
            else if (bottom.read()==1){control_menu();}
        }}    
    //==================================================================
    void heating(){
        ThisThread::sleep_for(50ms);

        if (h_val < 0) {
                h_val = 1;    }
        else if(h_val >1) {
                h_val = 0;
        }
        
        char const *heating_option = heating_o[h_val].c_str(); 

        lcd.clear();

        //Choose whether to set an auto-turn on the LED light if the Lux goes below a certain value, or to choose which colour to use
        lcd.printString("==============", 0, 0);
        lcd.printString("   Heating    ", 0, 1);
        lcd.printString("==============", 0, 2);
        lcd.printString(heating_option, 6, 3);
        lcd.printString("<=         => ", 0, 4); //shows that the left button reduces the value, and that the right button increases the value
        lcd.printString("    Back      ", 0, 5);
        lcd.refresh();
        ThisThread::sleep_for(400ms);
        while (1){
            check_interrupts(); //checks to see if an interrupt has triggered
            if (top.read()==1){
                if (h_val==0) {heating_control();}
                else if (h_val==1) {status();}}
            else if (right.read()==1){h_val++;heating();}
            else if (left.read()==1){h_val--;heating();}
            else if (bottom.read()==1){control_menu();}
        }}
    //==================================================================
    void status(){
        
        
        char const *heater_char = heater_status.c_str();
        char const *aircon_char = aircon_status.c_str(); 

        std::string temp_h = std::to_string(heater_temp);
        char const *heater_value = temp_h.c_str();

        std::string temp_a = std::to_string(aircon_temp);
        char const *aircon_value = temp_a.c_str();

        lcd.clear();

        if (heater_status=="On") {
            //Choose whether to set an auto-turn on the LED light if the Lux goes below a certain value, or to choose which colour to use
            lcd.printString("==============", 0, 0);
            lcd.printString("   Status    ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString("Heater||Aircon", 0, 3);
            lcd.printString("||",30,4);
            lcd.printString(heater_value, 6, 4); 
            lcd.printString(aircon_char,54,4);
            lcd.printString("    Back      ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(400ms);}
        else if (aircon_status=="On") {
            lcd.printString("==============", 0, 0);
            lcd.printString("    Status    ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString("Heater||Aircon", 0, 3);
            lcd.printString(heater_char, 6, 4);
            lcd.printString("||",36,4);
            lcd.printString(aircon_value,54,4);
            lcd.printString("    Back      ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(400ms);
        }
        else {
            lcd.printString("==============", 0, 0);
            lcd.printString("   Status    ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString("Heater||Aircon", 0, 3);
            lcd.printString(heater_char, 6, 4); 
            lcd.printString("||",30,4);
            lcd.printString(aircon_char,54,4);
            lcd.printString("    Back      ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(400ms);
        }
        while (1){
            check_interrupts(); //checks to see if an interrupt has triggered
            if (left.read()==1||right.read()==1||bottom.read()==1){heating();}
        }}
    //==================================================================
    void heating_control(){
        ThisThread::sleep_for(50ms);

        if (heat_val < 2) {
                heat_val = 100;    }
        else if(heat_val >100) {
                heat_val = 2;
            }
            std::string h_val = std::to_string(heat_val);
            char const *celsius_val = h_val.c_str(); 

            std::string temp_val = std::to_string(tmp_val);
            char const *cels_val = temp_val.c_str();
            
            lcd.clear();

            //Choose whether to set an auto-turn on the LED light if the Lux goes below a certain value, or to choose which colour to use
            lcd.printString(" Heat Control ", 0, 0);
            lcd.printString("==============", 0, 1);
            lcd.printString("Set Temp:",0,2);
            lcd.printString(cels_val,54,2);
            lcd.printString("^C",66,2);
            lcd.printString(celsius_val, 30, 3);
            lcd.printString("^C",42,3);
            lcd.printString("<=         => ", 0, 4); //shows that the left button reduces the value, and that the right button increases the value
            lcd.printString("    Back      ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(400ms);

            tmpticker.attach(&tmp_isr,5s);
            
            //tmp_i.fall(&tmpfall_isr);
            //tmp_i.rise(&tmprise_isr);
            
            while(1){
                check_interrupts();
                if (select.read()==1) {heating_control();}
                else if(top.read()==1){set_heat(heat_val);}
                else if (right.read()==1){heat_val++;heating_control();}
                else if (left.read()==1){heat_val--;heating_control();}
                else if (bottom.read()==1){heating();}
                }}
    //==================================================================
    void set_heat(int){
        std::string tmp_string = std::to_string(heat_val);
        char const *tmp = tmp_string.c_str(); 

        lcd.clear();
        lcd.printString("==============", 0, 0);
        lcd.printString(" ^ Celsius", 24, 1);
        lcd.printString(tmp, 0, 1); //prints the current value of the timer, and is at x=48 so that it directly follows the Minutes: 
        lcd.printString("==============", 0, 2);
        lcd.printString(" Confirm Temp ", 0, 3);
        lcd.printString("    Cancel    ", 0, 4); //shows that the left button reduces the value, and that the right button increases the value
        lcd.printString("     Back     ", 0, 5);
        lcd.refresh();
        ThisThread::sleep_for(500ms);

        while(1) {
            check_interrupts();
            if (top.read()==1){
                tmp_val=heat_val;          
                heating_control();}
            else if(right.read()==1||left.read()==1){control_menu();} //sets the right button to increase the value of the timer/alarm
            else if (bottom.read()==1){heating_control();} //cancels setting the alarm and returns to the cooking menu
        }    }
    //==================================================================
    void tmp_isr(){
        tmp_flag=1;}
    //==================================================================   
    //void tmpfall_isr(){tmp_flagF=1;} //triggers when the temperature sensors voltage is detected as falling, therefore the ambient temperature of the room is dropping
    //==================================================================
    //void tmprise_isr(){tmp_flagR=1;} //triggers when the temperature sensors voltage is detected as rising, therefore the ambient temperature of the room is rising
    //==================================================================
    void temp_interrupt(){
        if (tmp_flag==1){
            tmp_flag=0;
            current_tmp=330*TMP_ambient.read();

            if (current_tmp<tmp_val-4 && heater_status!="On") { //giving a leeway of 4°C as the pots and real-life TMP sensors can vary by 1-2 degrees and so I want to make sure it does not activate at the slightest change in temp/fluxuations or spikes in voltage
                heater_status = "On";
                aircon_status = "Off";
                heater_temp = tmp_val;
                return;}
            
            else if (current_tmp>tmp_val+4&&aircon_status!="On"){
                aircon_status = "On";
                heater_status = "Off";
                aircon_temp = tmp_val;
                return;}

            else if (current_tmp<tmp_val-1&&current_tmp>tmp_val+1){
                aircon_status="Off";
                heater_status="Off";
                return;} 
            else {return;}
            }
        else {return;}}   
//==================================================================
//sensors 
//==================================================================
    //==================================================================
    //Temperature Sensors
    //================================================================== 
 
        void temp_sensors(){
            lcd.clear();
            lcd.printString("==============", 1, 0);
            lcd.printString(" temp sensors ", 1, 1);
            lcd.printString("==============", 1, 2);
            lcd.printString("- cooking temp", 1, 3);
            lcd.printString("- ambient temp", 1, 4);
            lcd.printString("-    back     ", 1, 5);
            lcd.refresh();
            ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds
            lcd.refresh();
            
            while (1) {
                check_interrupts();
                if (top.read() == 1) {cooking_temp();}
                else if (left.read()==1||right.read()==1){ambient_temp();}
                else if (bottom.read()==1){(sensors_menu());}        
            }
        }
        //==============================================================================================
        void cooking_temp(){
            lcd.clear();
            lcd.printString("==============", 0, 0);
            lcd.printString(" cooking temp ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString("-  oven temp  ", 0, 3);
            lcd.printString("- stove temp  ", 0, 4);
            lcd.printString("-    back     ", 0, 5);
            lcd.refresh();
            ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds
            
            while (1) {
                check_interrupts();
                if (top.read() == 1) {oven_temp();}
                else if (left.read()==1||right.read()==1){stove_temp();}
                else if (bottom.read()==1){temp_sensors();}        
            }
        }
        //==============================================================================================
        void oven_temp(){

            if (oven_set >330){oven_set=330;}
            else if (oven_set < 60) {oven_set = 60;}
            ThisThread::sleep_for(100ms);

            o_val=330*TMP_Oven.read();
            std::string o = std::to_string(o_val);
            char const *o_temp = o.c_str();

            std::string o2 = std::to_string(oven_set);
            char const *o2_temp = o2.c_str();

            lcd.clear();
            lcd.printString(" Oven temp is ", 0, 0);
            lcd.printString(o_temp, 6, 1);
            lcd.printString(" ^ celsius", 24, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString(o2_temp, 24, 3);
            lcd.printString("^ Celsius",48,3);
            lcd.printString("< -5      +5 >", 0, 4);
            lcd.printString("     back     ", 0, 5);
            ThisThread::sleep_for(150ms);
            lcd.refresh();
            
                while (1) {
                check_interrupts(); //checks to see if an interrupt has triggered
                if (bottom.read()==1) {cooking_temp();}      
                else if(select.read()==1) {  
                oven_temp();
                }
                else if (left.read()==1) {oven_set = oven_set-5;oven_temp();}
                else if (right.read()==1) {oven_set = oven_set+5;oven_temp();}
                else if (top.read()==1){
                    oven_indicator(oven_set);
                }
            }
        }
        //==============================================================================================
        //==============================================================================================
        int indi_o=100;
        //==============================================================================================
        void oven_indicator(int){

                o_val=330*TMP_Oven.read();
                std::string o = std::to_string(o_val);
                char const *o_temp = o.c_str();

                std::string o2 = std::to_string(oven_set);
                char const*o2_temp = o2.c_str();

                lcd.clear();
                lcd.printString(" Oven temp is ", 0, 0);
                lcd.printString(o_temp, 0, 1);
                lcd.printString(" ^ celsius", 24, 1);
                lcd.printString("==============", 0, 2);
                lcd.printString("wait for ", 0, 3);
                lcd.printString(o2_temp, 54, 3);
                lcd.printString("^C",72,3);
                lcd.printString("    cancel    ", 0, 4);
                lcd.printString("-    back     ", 0, 5);
                ThisThread::sleep_for(250ms);
                lcd.refresh();

                    while(1){
                        check_interrupts();
                        o_val=330*TMP_Oven.read();

                        if(left.read()==1||right.read()==1){cooking_temp();} else if (bottom.read()==1){oven_temp();}
                        else if(select.read()==1){      
                                oven_indicator(oven_set);}
                        else if(oven_set <= o_val) {
                            play(play_return=2);
                        }}
        }
        //==============================================================================================
        void stove_temp(){

            if (j<0) {j=2;} else if (j>2) {j=0;}

            lcd.clear();

            s_val = 330*TMP_Stove.read();
            std::string s = std::to_string(s_val); 
            char const *s_temp = s.c_str();
            
            char const *temp_lvl = temp_levels[j].c_str();

            lcd.printString("stove temp is ", 0, 0);
            lcd.printString(s_temp, 0, 1);
            lcd.printString("^ celsius", 24, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString(temp_lvl,  24,3);
            lcd.printString("^C",48,4);
            lcd.printString("<= -     + => ", 0, 4);
            lcd.printString("-    back     ", 0, 5);
            ThisThread::sleep_for(150ms);
            lcd.refresh();
            s_val=0;
                while (1) {
                check_interrupts(); //checks to see if an interrupt has triggered
                if (bottom.read()==1) {cooking_temp();}      
                else if(select.read()==1) {
                    s_val = TMP_Stove.read()*330;    
                stove_temp();
                }
                else if (left.read()==1){j--;stove_temp();}
                else if (right.read()==1){j++;stove_temp();}
                else if (top.read()==1){chosen_temp = temp_lvls[j]; stove_indicator(j,chosen_temp);}
            }
        }
        //==============================================================================================

        void stove_indicator(int, int){

            s_val = 330*TMP_Stove.read();

            std::string lvl = std::to_string(temp_lvls[j]);
            char const *char_lvl = lvl.c_str();

            std::string s_i = std::to_string(s_val);
            char const *i_o = s_i.c_str();

            lcd.clear();
            lcd.printString("==============", 0, 0);
            lcd.printString(i_o, 24, 1);
            lcd.printString("^C", 42, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString("wait for ", 0, 3);
            lcd.printString(char_lvl, 54, 3);
            lcd.printString("^C",72,3);
            lcd.printString("    cancel", 0, 4);
            lcd.printString("-    back     ", 0, 5);
            ThisThread::sleep_for(150ms);
            lcd.refresh();

                while(1){ 
                    s_val = 330*TMP_Stove.read();

                    check_interrupts(); //checks to see if an interrupt has triggered
                    if(left.read()==1||right.read()==1){temp_sensors();} else if (bottom.read()==1){stove_temp();} else if (select.read()==1){stove_indicator(j,chosen_temp);}
                    else if(s_val > chosen_temp) {
                        play(play_return=3);
                        stove_temp();
                    }

            }
        }
        //==============================================================================================


        void ambient_temp(){ //room temperature reader, for use with control system but included ability to see current room temp...just because really
            
            a_val = 330*TMP_ambient.read();

            std::string a = std::to_string(a_val); 
            char const *a_temp = a.c_str();


            lcd.clear();
            lcd.printString("==============", 0, 0);
            lcd.printString("  Room Temp   ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString(a_temp,0,3);
            lcd.printString(" ^ celsius", 24, 3);
            lcd.printString("set heat level", 0, 4);
            lcd.printString("-    back     ", 0, 5);
            ThisThread::sleep_for(250ms);  //sleep for 500 miliseconds
            lcd.refresh();

            while (1) {
                a_val = 330*TMP_ambient.read();

                std::string a = std::to_string(a_val); 
                char const *a_temp = a.c_str();

                ThisThread::sleep_for(100ms);
                lcd.printString(a_temp,0,4);

                check_interrupts();
                if (select.read() == 1) {
                    ambient_temp();
                }
                else if (left.read()==1||right.read()==1) {heating_control();}
                else if (bottom.read()==1){temp_sensors();}            
            }
        }
        //==============================================================================================
    //==================================================================
    //Light Levels
    //==================================================================   
        void light_levels(){    
            lux_val = 250*LDR.read();

            std::string luxx = std::to_string(lux_val); //converts the variable inside of std::to_string to a string
            char const *lux_char = luxx.c_str(); //takes the string and changes it to a char const
            
            lcd.clear();
            lcd.printString("==============", 0, 0);
            lcd.printString(" Light Level ", 0, 1);
            lcd.printString("==============", 0, 2);
            lcd.printString("room lux:", 0, 3);
            lcd.printString(lux_char,54,3);
            lcd.printString(" Set Room Lux ",0,4);
            lcd.printString("-    back     ", 0, 5);
            ThisThread::sleep_for(250ms);  //sleep for 500 miliseconds
            lcd.refresh();
                while(1){
                    check_interrupts();
                    if (left.read()==1||right.read()==1){lux_level_set();}
                    else if (select.read()==1){light_levels();}
                    else if (bottom.read()==1){sensors_menu();}}};
    //==================================================================
    //sensor main menu
    //==================================================================
        void sensors_menu(){
        lcd.clear();
        lcd.printString("==============", 0, 0);
        lcd.printString("   sensors    ", 0, 1);
        lcd.printString("==============", 0, 2);
        lcd.printString("- temp sensors", 0, 3);
        lcd.printString("- light levels", 0, 4);
        lcd.printString("-    back     ", 0, 5);
        lcd.refresh();
        ThisThread::sleep_for(500ms);  //sleep for 500 miliseconds

        while (1) {
            check_interrupts();
            if (top.read() == 1) {temp_sensors();}
            else if (left.read()==1 || right.read()==1){light_levels();}
            else if (bottom.read()==1){main_menu();}        
        }    }
//==================================================================
//bottom of program