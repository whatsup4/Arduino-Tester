

#ifndef ASGN2_H
#define ASGN2_H

#include <string>//to handle string variables
#include <iostream>//to use cin and cout
#include <sstream>// for string streaming streaming is to send an unknown number of bytes

/*
functions are 
pinmode(pin#, input or output)
serial.
	begin(baud_rate_setting)
	println(text)
analogRead(pin0-5 or A0-A5)
analogWrite(pin3-6&9-11,value0-255)
*/
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
int analog_pins[6]={20,40,60,80,100,120};
int pin_mode[14]={};
int analog_read_val=99;
int analog_pin_vals[14]={};
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
	stringstream ss;
    ss << i;
    string str = ss.str();
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
//pinMode sets the array of pin_mode to 1 or 2 if they are in or out
void pinMode(int pin_num, string in_or_out){
	if (in_or_out=="INPUT"){
		pin_mode[pin_num]=1;
	}
	else if (in_or_out=="OUTPUT"){
		pin_mode[pin_num]=2;
	}
}
//analogRead returns analog_read_val
int analogRead(int read_pin){
	return analog_read_val;
}
//analogWrite assigns a value to a pin#
void analogWrite(int pin_num, int ana_val){
	if ((pin_num>=3&&pin_num<=6)||(pin_num>=9&&pin_num<=11)){
		if (pin_mode[pin_num]==2){
			analog_pin_vals[pin_num]=ana_val;
		}
	}
}
int millis() {
	return 10;
}


int main() {
	int grade=0;
  Serial = Cereal();
  setup();

  loop();
  if (analog_pin_vals[0]==99){
      grade=grade+20;
  }
  cout << analog_pin_vals[10];//"Their grade is:\n";
  //cout << grade;
}

#endif
