#include "motESP.h"
#include <driver/ledc.h> 
//hey, si estas leyendo esto, preparate para el mucho texto :)
#ifndef ESP32
  #define ESP32
#endif
void motesp::iniciarPWM(int EN,int CO1,int CO2,int torque){
	this-> en = EN;
	this-> co1 = CO1;
	this-> co2 = CO2;
	this-> velocidad = torque;
    ledcAttach(en, frequency, resolution);
	pinMode(co1,OUTPUT);
	pinMode(co2,OUTPUT);
}
void motesp::iniciar(int EN, int CO1,int CO2){
	this-> en = EN;
	this-> co1 = CO1;
	this-> co2 = CO2;
	pinMode(en,OUTPUT);
	pinMode(co1,OUTPUT);
	pinMode(co2,OUTPUT);
}
void motesp::mover(char dir){
	switch(dir){
		case 'S':
			digitalWrite(en,0);
			digitalWrite(co1,0);
			digitalWrite(co2,0);
			break;
		case 'F':
			digitalWrite(en,1);
			digitalWrite(co1,1);
			digitalWrite(co2,0);
			break;
		case 'B':
			digitalWrite(en,1);
			digitalWrite(co1,0);
			digitalWrite(co2,1);
			break;
		default:
			digitalWrite(en,0);
		break;
	}
}
void motesp::alto(){
	digitalWrite(en,0);
	digitalWrite(co1,0);
	digitalWrite(co2,0);
}
void motesp::moverPWM(char dir){
	//:)
	switch(dir){
	case 'F':
		ledcWrite(en,velocidad);
		digitalWrite(co1,1);
		digitalWrite(co2,0);
	break;
	case 'B':
		ledcWrite(en,velocidad);
		digitalWrite(co1,0);
		digitalWrite(co2,1);
	break;
	case 'S':
		ledcWrite(en,0);
		digitalWrite(co1,1);
		digitalWrite(co2,0);
	break;
	}
}
