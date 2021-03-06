#pragma once

#include <string>
#include "Keys.h"

enum class Particle
{
	BORDER	 = L'\u2591',
	BRICK	 = L'\u25d9',
	SPACE	 = L'\x20',
	CELL	 = L'\u00b7',
	LSELECTOR = L'\u25ba',
	RSELECTOR = L'\u25c4',
};

enum class State
{
	NONE	 = 0xff,
	CONTINUE = 0x00,
	NEW_GAME = 0x01,
	EXIT	 = 0x02,
	PAUSE	 = 0x03,
	END		 = 0x04
};

class BaseApp;

class View
{
public:
	View(const int w, const int h);
	virtual ~View() = default;

	virtual void Show(BaseApp *app) const;
	virtual void Clear(BaseApp *app) const;

	virtual State Update(const float deltaTime);
	virtual State KeyHandler(const Key &key) = 0;

	void ShowText(const int x, const int y, const std::wstring &text, BaseApp *app) const;
	void ShowNumber(const int cx, const int y, const int number, BaseApp *app) const;
protected:
	const int m_width;
	const int m_height;
};

