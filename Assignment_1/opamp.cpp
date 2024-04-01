#include "equation3_class.h"
#include "menu.h"
#include "opamp.h"
#include <string>
#include <regex>

//Main Menu for my sub-program
void opamp_menu() {
  print_opamp_menu();
  int input = opamp_get_user_input();
  menu_select(input);
}

//used to get the value assossiated with the users selection
int opamp_get_user_input() {
  int input;
  std::string string_selection;
  bool inputvalid = false;
  int menu_amount = 7;

  do {
    std::cout << "\nSelect Calculator Function: ";
      std::cin >> string_selection;
    inputvalid = opamp_is_integer(string_selection);
 
  if (inputvalid == false) {
    std::cout << "Invalid Selection! Input an Integer 1 to 7.\n";
  } else { 
    input = std::stoi(string_selection);
      if (input >= 1 && input <= menu_amount) {
        inputvalid = true;
      } else {
          std::cout << "Invalid Selection! Input an Integer 1 to 7.\n";
          inputvalid = false;
      }
     }
  }  while (inputvalid == false);
  return input;
}

//used in conjuction with the users input integer to determine and then call the appropriate function
void menu_select(int input) {
  switch (input) {
    case 1:
      gainequation1();
      break;
    case 2:
      gainequation2();
      break;
    case 3:
      gainclass();
      //gainequation3(); was the original function for the equation 3 code, which was replaced with the class 
      break;
    case 4:
      gainequation4();
      break;
    case 5:
      gainequation5();
      break;
    case 6:
      gainequation6();
      break;
    default:
      main_menu();
      break;
  }
}

//used to print the GUI of the selection menu for the op-amp calculator sub-program (my own design, used by ibrahim & chris so that we could have a common GUI theme across our programs and in the main menu)
void print_opamp_menu(){
  std::cout << "\n╔▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬╗\n";
  std::cout << "║░░░░░░░░░░░░░░ Op-Amp Calculator ░░░░░░░░░░░░░░║\n";
  std::cout << "║▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║         1. Open-Loop Gain from Voltages       ║\n";
  std::cout << "║              (Using Vout, V+ & V-)            ║\n";
  std::cout << "║         2. Closed-Loop Gain from Resistance   ║\n";
  std::cout << "║              (Using R1 & R2)                  ║\n";
  std::cout << "║         3. Closed-Loop Gain from Gains        ║\n";
  std::cout << "║              (Using A & AB)                   ║\n";
  std::cout << "║         4. Gain-Bandwidth Product (GBP)       ║\n";
  std::cout << "║              (Using GBP = G x bandwidth)      ║\n";
  std::cout << "║         5. Decibel from Gain                  ║\n";
  std::cout << "║              (Using dB = 20log(gain))         ║\n";
  std::cout << "║         6. Feedback Ratio (B)                 ║\n";
  std::cout << "║              (Using R1 & R2)                  ║\n";
  std::cout << "║         7. Return to main menu                ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "╚═══════════════════════════════════════════════╝\n";
}

//used to go back to the calculator selection screen in case you entered the wrong value
void go_back_to_opamp_menu(){
  std::string input;
  
  do {
    std::cout << "\nEnter b or B to go back to the Op-Amp menu: ";
      std::cin >> input;
  } while (input != "b" && input != "B");
  opamp_menu();
}

//used to check whether the user input to select which calculator function is a valid selection (one of the numbers corresponding to a function)
bool opamp_is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

//First equation to find A (open loop gain) using the voltages in the equation Vout = A(V+-V-) by re-arranging it to A= Vout/(V+ - V-)
void gainequation1() {
  float Vout, V1, V2, A;

  std::cout << "\nEnter Vout: ";
    std::cin >> Vout; 
  std::cout << "\nEnter V+: ";
    std::cin >> V1; 
  std::cout << "\nEnter V-: ";
    std::cin >> V2;

 A = Vout/(V1 - V2);
 std::cout << "The Open-Loop Gain is: " << A;
 go_back_to_opamp_menu();
}

//Second Equation option, to find the closed loop gain. i.e. for non-inverting G = 1+R2/R1 where G = Closed-loop gain, A = Open-loop gain, R1 & R2 are the resistors
void gainequation2(){

  std::string type;
  float R1, R2, G;

  std::cout << "\nEnter R1: ";
   std::cin >> R1;
  std::cout << "\nEnter R2: ";
    std::cin >> R2;

  std::cout << "\nIs the op-amp Inverting? y for inverting or n for non-inverting): ";
    std::cin >> type;
   if (type == "y"){
    G = 1+(R2/R1);
    std::cout << "\nThe Closed-Loop Gain (G) of the Inverting Op-Amp is: " << G;
    go_back_to_opamp_menu();
  } else if (type == "n") {
    G = -1*(R2/R1);
    std::cout << "\nThe Closed-Loop Gain (G) of the Non-Inverting Op-Amp is: " << G;
    go_back_to_opamp_menu();
    } else {
      std::cout << "Invalid answer! y/n only.";
      gainequation2();
    }
}

//third equation option, to find the open, closed or total loop gain. i.e. for non-inverting G = A/(1+AB) where G = Closed-loop gain, A = Open-loop gain, AB = Loop Gain
/* Original Third Equation code, as I was unable to use a class as I had hoped naturally, I replaced this with code that used a class to find the value you were seeking, as I wished to show that I understood class's, but I only know that it is not a good example to show my prowess of the code we have learnt this semester as it is a rather simple equation but I over-estimated the difficulty of the Op-amp gain related equations when I chose it for my sub-program. The replacement code is located in the seperate equation3_class.cpp and .h files
void gainequation3(){

  std::string type;
  float A, B, AB, G;

  std::cout << "\nEnter Open-loop gain (A): ";
    std::cin >> A;  
  std::cout << "\nEnter the Feedback Ratio (B): ";
    std::cin >> AB;
  //working out the loop gain (AB)
  AB = A*B;
  std::cout << "\nIs the op-amp Inverting? (y/n): ";
    std::cin >> type;

  if (type == "y"){
    G = A/(1+AB);
    std::cout << "The Closed-Loop Gain (G) of the Inverting Op-Amp is: " << G << "\n";
    go_back_to_opamp_menu();
  } else if (type == "n") {
    G = ((-1*A)*(1-B))/(1+AB);
    std::cout << "The Closed-Loop Gain (G) of the Non-Inverting Op-Amp is: " << G << "\n";
    go_back_to_opamp_menu();
    } else {
      std::cout << "Invalid answer! y/n only.";
      gainequation3();
    }
}*/

//Gain Bandwidth Product (GBP), which is used to find A under Ft (frequency when A=1)
void gainequation4(){
  float GBP, G, bandwidth;

  std::cout << "\nEnter Gain: ";
    std::cin >> G;
  std::cout << "\nEnter Bandwidth (frequency): ";
    std::cin >> bandwidth;

  GBP = G*bandwidth;
  std::cout << "\nThe Gain Bandwidth product (GBP) is: " << GBP << std::endl;
  go_back_to_opamp_menu();
}

//Gain to decibel conversion equation 
void gainequation5(){
  float G, dB;

  std::cout << "Enter Gain you want to be converted into Decibels\n";
    std::cin >> G;
  
  dB = 20*log(G);

  std::cout << "The Gain of " << G << " is converted to " << dB << " Decibels (dB).\n";
  go_back_to_opamp_menu();
}

//Equation to find Feedback ratio (B)
void gainequation6() {

  float B, R1, R2;

  std::cout << "\nEnter R1 (in ohms): ";
    std::cin >> R1;
  std::cout << "\nEnter R2 (in ohms): ";
    std::cin >> R2;

  B = R1/(R1+R2);
  std::cout << "\nThe Feedback Ratio (B) is: " << B;
  go_back_to_opamp_menu();
}


