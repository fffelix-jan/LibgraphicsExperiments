#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include <Windows.h>
#include <WinUser.h>

char text[1000] = "";

void display(void)
{
	DisplayClear();
	drawLabel(0.5, GetWindowHeight() / 2 + 0.5, "Type whatever you want below, and press ENTER to see what you typed in a message box.");
	textbox(GenUIID(0), 0.5, GetWindowHeight() / 2, 9, 0.3, text, sizeof(text));
}

void CharEventProcess(char ch)
{
	uiGetChar(ch);
	display();
}

void KeyboardEventProcess(int key, int event)
{
	if (key == VK_RETURN && event == KEY_DOWN)
	{
		MessageBox(NULL, text, "You Typed:", MB_ICONINFORMATION);
	}
	uiGetKeyboard(key, event);
	display();
}

void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x, y, button, event);
	display();
}

#define MY_TIMER  1

void TimerEventProcess(int timerID)
{
	if (timerID == MY_TIMER)
	{
		display();
	}
}


void Main()
{
	SetWindowTitle("Typing Window");
	InitGraphics();

	registerCharEvent(CharEventProcess);
	registerKeyboardEvent(KeyboardEventProcess);
	registerMouseEvent(MouseEventProcess);
	registerTimerEvent(TimerEventProcess);
}