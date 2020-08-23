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
		m_menu(w, h),
		m_currentView(&m_menu)
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
		m_currentView->Clear(this);
		m_currentView->Show(this);
	}

	void KeyPressed(int btnCode) final
	{
		if (btnCode == 224)
		{
			btnCode = getch();
		}

		State state = m_currentView->KeyHandler(Key(btnCode));

		switch (state)
		{
		case State::CONTINUE:
			
			break;
		case State::NEW_GAME:
			m_currentView = &m_view;
			break;
		case State::EXIT:
			exit(0);
			break;
		case State::PAUSE:
			m_currentView = &m_menu;
			break;
		}
	}

private:
	View m_view;
	MenuView m_menu;
	View* m_currentView;
};

void main ()
{
	GameApp app(25, 25);
	app.Run();
}
