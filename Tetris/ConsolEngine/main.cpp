// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "TestApp.h"
#include "../GameView.h"
#include "../MenuView.h"
#include "../GameModel.h"
#include "../Vec2d.h"
#include "../EndView.h"
#include <conio.h>

class GameApp : public BaseApp
{
public:
	GameApp(const int w, const int h)
		: BaseApp(w, h),
		m_model(15, h - 2),
		m_gameView(&m_model, w, h),
		m_menuView(w, h),
		m_endView(&m_model, w, h),
		m_currentView(&m_menuView)
	{
		// next crutch resolve the error #87 when call base app constructor
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
		if (m_currentView->Update(deltaTime) == State::END)
		{
			m_currentView = &m_endView;
		}
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
			m_currentView = &m_gameView;
			break;
		case State::NEW_GAME:
			m_model.ResetModel();
			m_currentView = &m_gameView;
			break;
		case State::EXIT:
			exit(0);
			break;
		case State::PAUSE:
			m_currentView = &m_menuView;
			break;
		}
	}

private:
	GameModel m_model;
	GameView m_gameView;
	MenuView m_menuView;
	EndView m_endView;
	View* m_currentView;
};

void main ()
{
	GameApp app(25, 26);
	app.Run();
}
