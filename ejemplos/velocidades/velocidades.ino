#include <motESP.h>
motesp motor;
const int ena = 17;
const int c1 = 25;
const int c2 = 26;

void setup() {
  //este código hace girar el motor mientras aumenta la velocidad
  motor.iniciarPWM(ena, c1, c2, 0);
}

void loop() {
  motor.mover('F');
  for (int i = 0; i < 256; i++){ //aumenta la velocidad hacia delante
    motor.seleccionarVelocidad(i);
    delay(10);
  }

  motor.alto();
  delay(1000);

  motor.mover('B');
  for (int i = 0; i < 256; i++){ //aumenta la velocidad hacia atras
    motor.seleccionarVelocidad(i);
    delay(10);
  }

  delay(1000);
  motor.alto();
}
