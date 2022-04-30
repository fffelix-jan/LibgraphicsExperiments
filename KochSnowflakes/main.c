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

void segment(double length, int depth)
{
	if (depth == 0)
	{
		forward(length);
	}
	else
	{
		segment(length / 3, depth - 1);
		turn(-60);
		segment(length / 3, depth - 1);
		turn(120);
		segment(length / 3, depth - 1);
		turn(-60);
		segment(length / 3, depth - 1);
	}
}

void snowflake(double size, int depth)
{
	segment(size, depth);
	turn(120);
	segment(size, depth);
	turn(120);
	segment(size, depth);
}

void Main()
{
	SetWindowTitle("Koch Snowflakes");
	InitGraphics();

	// Set pen colour
	SetPenColor("Blue");

	double y = GetWindowHeight() / 2;

	// Move pen to centre of screen
	MovePen(0.2, y);

	snowflake(2, 0);
	Angle = 0;
	move(2.5);
	snowflake(2, 1);
	Angle = 0;
	move(2.5);
	snowflake(2, 2);
	Angle = 0;
	move(2.5);
	snowflake(2, 3);
}