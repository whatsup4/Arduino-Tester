int timekeep=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // Not sure how in depth I would make this but this would be a good start so they see at faster baud the time is slower
  timekeep=millis();
  Serial.print("123456789012345678901234567890");
  Serial.println("0123456789");
  timekeep=millis()-timekeep;
  Serial.print("that took ");
  Serial.print(timekeep);
  Serial.println("miliseconds to type");
  //delay(1000);
}
