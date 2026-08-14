#include "motESP.h"
//hey, si estas leyendo esto, preparate para el mucho texto :)

void motesp::iniciarPWM(int EN,int CO1,int CO2,int torque){
	this-> en = EN;
	this-> co1 = CO1;
	this-> co2 = CO2;
	ledcSetup(en, frequency, resolution);
	ledcSetup(co1, frequency, resolution);
	ledcSetup(co2, frequency, resolution);
	ledcAttachPin(en,ledChannel);
	ledcAttachPin(co1,ledChannel);
	ledcAttachPin(co2,ledChannel);
	this-> velocidad = torque;
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