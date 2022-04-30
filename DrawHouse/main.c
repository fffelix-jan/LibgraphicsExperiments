#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"

void Main()
{
	SetWindowTitle("Felix's House");
	InitGraphics();

	// Draw chimney
	double w = GetWindowWidth(), h = GetWindowHeight();
	MovePen(2, h - 2);
	double chimneyStartX = GetCurrentX(), chimneyStartY = GetCurrentY();
	drawRectangle(chimneyStartX, chimneyStartY, 1, 0.4, 0);
	MovePen(chimneyStartX + 0.2, chimneyStartY);
	DrawLine(0, -1.5);
	MovePen(chimneyStartX + 0.8, chimneyStartY);
	DrawLine(0, -1);

	// Draw roof
	MovePen(GetCurrentX() - 1.2, GetCurrentY() - 1.2);
	DrawLine(3, 3);
	DrawLine(3, -3);
	DrawLine(-6, 0);

	// Draw body
	MovePen(GetCurrentX() + 1, GetCurrentY());
	drawRectangle(GetCurrentX(), GetCurrentY(), 4, -2.5, 0);

	// Draw door
	MovePen(GetCurrentX() + 2.5, GetCurrentY() - 2.5);
	double doorX = GetCurrentX(), doorY = GetCurrentY();
	drawRectangle(GetCurrentX(), GetCurrentY(), 1, 1.75, 0);

	// Draw text above door
	MovePen(GetCurrentX() + 0.05, GetCurrentY() + 1.9);
	DrawTextString("Felix's House");

	// Draw doorknob
	MovePen(doorX + 0.3, doorY + 0.875);
	DrawArc(0.1, 0, 360);

	// Draw window
	MovePen(doorX - 2.25, doorY + 0.5);
	drawRectangle(GetCurrentX(), GetCurrentY(), 1.75, 1.5, 0);
}