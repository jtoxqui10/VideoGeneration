#include <iostream>
#include "global.h"
#include "frame.h"
#include "rectangle.h"


extern Frame frame;
Rectangle::Rectangle(double h, double w, double x, double y) {
	this->h = h;
	this->w = w;
	this->x = x;
	this->y = y;
}

void Rectangle::draw() {
	if (frame.isOut(&x, &y)) return;
	double x0 = x;
	double x1 = x + w;
	double y0 = y;
	double y1 = y + h;
	frame.clamp(&x0, &y0);
	frame.clamp(&x1, &y1);
	for (double y = y0; y < y1; ++y) {
		for (double x = x0; x < x1; ++x) {
			frame.setPixel(x, y, r, g, b);
		}
	}
}

void Rectangle::update(double dt) {
	x += dx*dt; 
	y += dy*dt; 
}

void Rectangle::setVelocity(double dx, double dy) {
	this->dx = dx; 
	this->dy = dy;
}

void Rectangle::setColor(byte r, byte g, byte b) {
	this->r = r; 
	this->g = g; 
	this->b = b; 
}

