#include "opamp.h"
#include "equation3_class.h"
#include <string>
#include <regex>




void gain_equation::set_A() {
    std::cout << "\nInput Open-Loop Gain (A): ";
    std::cin >> A;    
}

void gain_equation::set_B() {
  std::cout << "\nInput Feedback Ratio (B): ";
    std::cin >> B;    
}

void gain_equation::set_loop() {
  std::cout << "\nInput Loop Gain (AB): ";
    std::cin >> loop;    
}

void gain_equation::set_G() {
      std::cout << "\nInput Closed-Loop Gain (G): ";
    std::cin >> A;    
}

    
float gain_equation::get_A() {
    return A;
}

float gain_equation::get_B() {
    return B;
}

float gain_equation::get_loop() {
    return loop;
}

float gain_equation::get_G() {
    return G;
}
  
void gain_equation::set_inverting() {
    std::cout << "Is the Op-Amp inverting (y/n)? \n";
     std::cin >> inverting;
}

std::string gain_equation::get_inverting() {
    return inverting;
}

void gain_equation::find_G(float A, float B, std::string inverting) {
  if (inverting == "y"){
    G = A/(1+loop);
      std::cout << "The Open-Loop Gain (A) of the Inverting Op-Amp is: " << G << "\n";
      go_back_to_class_menu();
  } else if (inverting == "n") {
      G = ((-1*A)*(1-B))/(1+loop);
      std::cout << "The Open-Loop Gain (A) of the Non-Inverting Op-Amp is: " << G << "\n";
      go_back_to_class_menu();
  } else {
       std::cout << "Invalid inverting answer! y/n only.";
       gainclass();
     }   
}


void gainclass() {
  printclassmenu1();
  int class_input = get_class_user_input();
  class_menu_select(class_input);

}

//I had intended to use the class to re-work the equation so that you could find A, G, AB or B but I realised that you would not be able to do so with this specific equation as if you do not have A or B, you cannot have AB, thus you cannot work out the equation as you are missing too many variables, but I still coded the class as if I could re-order the equation because it allows the code to be more modular as in the future I can use this class as a template for other equations which can be re-ordered. I would have done this for one of the other equations I have in this calculator sub-program but I did not want to change my code so close to the deadline and risk it not working at all
void printclassmenu1() {
  std::cout << "\n╔▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬╗\n";
  std::cout << "║░░░░░░░░░░░░░░░ Gain Equation 3 ░░░░░░░░░░░░░░░║\n";
  std::cout << "║▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ஜ۩۞۩ஜ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║         1. Find Closed-Loop Gain (G)          ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "║         2. Return to main menu                ║\n";
  std::cout << "║                                               ║\n";
  std::cout << "╚═══════════════════════════════════════════════╝\n";
}

void go_back_to_class_menu(){
  std::string input;
  
  do {
    std::cout << "\nEnter b or B to go back to Equation 3's menu: ";
      std::cin >> input;
  } while (input != "b" && input != "B");
  gainclass();
}

void class_menu_select(int input) {
  switch (input) {
    case 1:
      case1();
      break;
    default:
    opamp_menu();
      break;
  }
}

//while there is only 1 case, more can be added in the future to increase the functionality of the class
void case1() {
  gain_equation class_g;

    class_g.set_A();
    class_g.set_loop();
    class_g.set_B();
    class_g.set_inverting();
    class_g.find_G(class_g.get_A(), class_g.get_B(), class_g.get_inverting());
}


int get_class_user_input() {
  int input;
  std::string class_string_selection;
  bool inputvalid = false;
  int menu_amount = 2;

  do {
    std::cout << "\nSelect Calculator Function: ";
      std::cin >> class_string_selection;
    inputvalid = is_class_integer(class_string_selection);
 
  if (inputvalid == false) {
    std::cout << "Invalid Selection! Input an Integer 1 to 2.\n";
  } else { 
    input = std::stoi(class_string_selection);
      if (input >= 1 && input <= menu_amount) {
        inputvalid = true;
      } else {
          std::cout << "Invalid Selection! Input an Integer 1 to 2.\n";
          inputvalid = false;
      }
     }
  }  while (inputvalid == false);
  return input;
}

bool is_class_integer(std::string class_num) {
  return std::regex_match(class_num, std::regex("[+-]?[0-9]+"));
}
