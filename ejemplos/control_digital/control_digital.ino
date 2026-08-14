#include <motESP>  // incluye la líbreria, SI NO, NO SERÍA UN EJEMPLO DE MOTESP
const int ena = 16;
const int c1 = 27;
const int c2 = 14;

motesp motor;
void setup() {
  //este ejemplo usa el control digital
  motor.iniciar(ena, c1, c2)
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.mover('F');
  delay(2500);
  motor.mover('S');
  // motor.alto(); // es otra forma de frenar, para descomentariar presiona Ctrl + }
  motor.mover('B');
  delay(2500);
  motor.alto();
  // motor.mover('S'); //como tu quieras Ctrl + }
}
