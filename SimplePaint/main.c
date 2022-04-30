#include "graphics.h"
#include "extgraph.h"
#include <Windows.h>
#include <winuser.h>

void ProcessMouseEvent(int x, int y, int button, int event)
{
	static double x1 = 0.0, y1 = 0.0;
	double x2, y2;
	x2 = ScaleXInches(x);
	y2 = ScaleYInches(y);
	static bool drawing = FALSE;

	switch (event)
	{
	case BUTTON_DOWN:
		if (button == LEFT_BUTTON) {
			drawing = TRUE;
		}
		break;
	case BUTTON_DOUBLECLICK:
		break;
	case BUTTON_UP:
		if (button == LEFT_BUTTON) drawing = FALSE;
		break;
	case MOUSEMOVE:
		if (drawing) {
			DrawLine(x2 - x1, y2 - y1);
			MovePen(x2, y2);
		}
		break;
	}
	x1 = x2;
	y1 = y2;
}

void ProcessKeyboardEvent()
{
	DisplayClear();
}


void Main()
{
	// Show instructions to user
	MessageBox(NULL, "Welcome to Simple Paint.\r\nClick and drag in the window to draw.\r\nPress any key to clear the screen.\r\nClick OK below to begin drawing.", "Welcome to Simple Paint", MB_ICONINFORMATION);

	SetWindowTitle("Simple Paint");
	InitGraphics();

	registerMouseEvent(ProcessMouseEvent);
	registerKeyboardEvent(ProcessKeyboardEvent);
	SetPenSize(1);
}
