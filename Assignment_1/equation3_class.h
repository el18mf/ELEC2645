#include <cmath>
#include <iostream>
#include <string>

void gainequation3();
void gainclass();
void printclassmenu1();
void go_back_to_class_menu();
void case1();
void class_menu_select(int class_input);
bool is_class_integer(std::string class_num);
int get_class_user_input();


class gain_equation {
  float A, B, loop, G;
  std::string inverting;

  public:
    void set_inverting();
    std::string get_inverting();

    void set_A();
    void set_B();
    void set_loop();
    void set_G();

    float get_A();
    float get_B();
    float get_loop();
    float get_G();
    
    void find_G(float A, float b, std::string inverting);
};



