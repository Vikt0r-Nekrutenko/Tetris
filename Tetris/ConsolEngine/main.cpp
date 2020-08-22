// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "TestApp.h"
#include "../View.h"
#include "../MenuView.h"
#include <conio.h>

class GameApp : public BaseApp
{
public:
	GameApp(const int w, const int h) 
		: BaseApp(w, h), 
		m_view(w, h),
		m_menu(w, h)
	{
		CONSOLE_SCREEN_BUFFER_INFOEX csbiex;
		csbiex.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		GetConsoleScreenBufferInfoEx(GetStdHandle(STD_OUTPUT_HANDLE), &csbiex);
		csbiex.dwSize.X = csbiex.dwMaximumWindowSize.X = w;
		csbiex.dwSize.Y = csbiex.dwMaximumWindowSize.Y = h;
		SetConsoleScreenBufferInfoEx(GetStdHandle(STD_OUTPUT_HANDLE), &csbiex);
	}

	void UpdateF(float deltaTime) final
	{
		m_menu.Clear(this);

		m_menu.Show(this);
	}

	void KeyPressed(int btnCode) final
	{
		if (btnCode == 224)
		{
			btnCode = getch();
		}

		MenuItem item = m_menu.KeyHandler(Key(btnCode));

		switch (item)
		{
		case MenuItem::CONTINUE:
			break;
		case MenuItem::NEW_GAME:
			break;
		case MenuItem::EXIT:
			exit(0);
			break;
		}
	}

private:
	View m_view;
	MenuView m_menu;
};

void main ()
{
	GameApp app(25, 25);
	app.Run();
}
