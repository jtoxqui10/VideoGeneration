#pragma once
#include "global.h"
class Rectangle {
public:
	Rectangle(double h, double w, double x, double y); 
	void draw();
	void update(double dt); 
	void setVelocity(double dx, double dy); 
	void setColor(byte r, byte g, byte b); 
private:
	byte r; 
	byte g; 
	byte b;  
	double h;
	double w;  
	double dx; 
	double dy; 
	double x; 
	double y; 

};
