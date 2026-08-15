#include <motESP.h>
motesp motor;
const int ena = 17;
const int c1 = 25;
const int c2 = 26;
int tiempo = 25;

void setup() {
  //este código hace girar el motor mientras aumenta la velocidad
  motor.iniciarPWM(ena, c1, c2, 0);
}

void loop() {
  for (int i = 0; i < 256; i++){ //aumenta la velocidad hacia delante
    motor.moverPWM('F');
    motor.seleccionarVelocidad(i);
    delay(tiempo);
  }
  motor.alto();
  delay(1000);
}