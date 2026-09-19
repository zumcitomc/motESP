#include <motESP.h>
const int ena = 16;
const int c1 = 27;
const int c2 = 14;

motesp motor;
void setup() {
  //este ejemplo usa el control digital :D
  motor.iniciar(ena, c1, c2);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.mover_for(2500,'F');
  motor.alto();
  delay(2500);
  motor.mover_for(2500,'B');
}
