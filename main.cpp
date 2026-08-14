#include <Arduino.h>
#include <motESP.h>
motesp motor;
void setup(){
	motor.iniciar(25,5,17);
}
void loop(){
	motor.mover('F');
	delay(1000);
	motor.mover('S');
	delay(1000);
	motor.mover('b');
	delay(1000);
}