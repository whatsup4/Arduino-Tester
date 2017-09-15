#ifndef ASGN1_H
#define ASGN1_H

#include <string>
#include <iostream>
#include <sstream>


using namespace std;

void setup();
void loop();

class Cereal {
public:
    static void print(int s);
    static void print(string s);
    static void println(string s);
    static void begin(int baud);
};

int millis();

Cereal Serial;

string all_prints = "";
int baud_rate_setting = 0;

void Cereal::print(int i) {
  stringstream ss;
  ss << i;
  string str = ss.str();
  all_prints = all_prints + str;
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
