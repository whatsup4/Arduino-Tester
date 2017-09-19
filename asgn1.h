//I'm adding in comments so I can better understand what is going on in the program

#ifndef ASGN1_H
#define ASGN1_H

#include <string>//to handle string variables
#include <iostream>//to use cin and cout
#include <sstream>// for string streaming streaming is to send an unknown number of bytes


using namespace std;//this prevents you from typing std in front of most functions

void setup();//declare this so the program knows these functions will be used
void loop();

class Cereal {//create a class cereal to take all the serial print comands
public://declaring all the functions of this class cereal
    static void print(int s);
    static void println(int s);
    static void print(string s);
    static void println(string s);
    static void begin(int baud);
};

int millis();//declares millis as a function that will be used later

Cereal Serial;//creates a variable called Serial which is of class Cereal

string all_prints = "";
int baud_rate_setting = 0;//Set this to 0 so we know it changes to the correct number

void Cereal::print(int i) {//
  stringstream ss;
  ss << i;
  string str = ss.str();
  all_prints = all_prints + str;
}
void Cereal::println(int i){
    string str = to_string i;//different way to convert int to string
    all_prints = all_prints + str + "\n";
}
void Cereal::print(string s) {
  all_prints = all_prints + s;
}

void Cereal::println(string s) {
  all_prints = all_prints + s + "\n";
}

void Cereal::begin(int i) {
  baud_rate_setting = i;  
}

int millis() {
  return 0;
}


int main() {
  Serial = Cereal();
  setup();

  loop();

  cout << "The output was:\n";
  cout << all_prints;
  cout << "\nThe baud rate was: \n";
  cout << baud_rate_setting;
}

#endif
