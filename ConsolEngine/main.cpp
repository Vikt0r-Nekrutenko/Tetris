// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "TestApp.h"
#include <conio.h>

constexpr int WINDOW_W = 25;
constexpr int WINDOW_H = 25;

class GameApp : public BaseApp
{
public:
	GameApp() : BaseApp(WINDOW_W, WINDOW_H)
	{
		CONSOLE_SCREEN_BUFFER_INFOEX csbiex;
		csbiex.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		GetConsoleScreenBufferInfoEx(GetStdHandle(STD_OUTPUT_HANDLE), &csbiex);
		csbiex.dwSize.X = csbiex.dwMaximumWindowSize.X = WINDOW_W;
		csbiex.dwSize.Y = csbiex.dwMaximumWindowSize.Y = WINDOW_H;
		SetConsoleScreenBufferInfoEx(GetStdHandle(STD_OUTPUT_HANDLE), &csbiex);
	}

	void UpdateF(float deltaTime) final
	{

	}

	void KeyPressed(int btnCode) final
	{
		if (btnCode == 224)
		{
			btnCode = getch();
		}
	}
};

void main ()
{
	GameApp app;
	app.Run();
}
