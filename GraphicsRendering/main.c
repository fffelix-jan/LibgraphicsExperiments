#define _USE_MATH_DEFINES

#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"

double Angle = 0;

void forward(double distance)
{
	DrawLine(distance * cos(M_PI / 180 * Angle), distance * sin(M_PI / 180 * Angle));
}

void turn(double angle)
{
	Angle += angle;
}

void move(double distance)
{
	MovePen(GetCurrentX() + distance * cos(M_PI / 180 * Angle), GetCurrentY() + distance * sin(M_PI / 180 * Angle));
}

void Main()
{
	SetWindowTitle("Hexagon Fractal");
	InitGraphics();

	// Set pen colour
	SetPenColor("Brown");

	// Move pen to centre of screen
	MovePen(GetWindowWidth() / 2, GetWindowHeight() / 2);

	for (int i = 0; i < 24; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			forward(1.5);
			turn(60);
		}
		turn(15);
	}
}