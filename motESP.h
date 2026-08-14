#include <Arduino.h>

#ifndef motESP
#define motESP

//hey, si estas leyendo esto, preparate para el mucho texto :)
class motesp{
private:
	int EN;
	int CO1;
	int CO2;
	int en;
	int co1;
	int co2;
	const int ledChannel = 0;
	const int ledChael = 1;
	const int ledChanel = 2;
	const int frequency = 5000;  // Frecuencia en Hz
	const int resolution = 8;    // Resolución en bits (0-255 para 8 bits)
	int velocidad;
public:
	void iniciarPWM(int EN,int CO1,int CO2,int torque);
	void iniciar(int EN, int CO1,int CO2);
	void mover(char dir);
	void moverPWM(char dir);
	void alto();
	void altoActivo();
	void seleccionarVelocidad(int valor);
};
#endif
