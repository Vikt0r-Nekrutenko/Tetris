#pragma once

#include <string>

enum class Particle
{
	BORDER = L'\u2591',
	BRICK  = L'\u25d9',
	SPACE  = L'\x20',
	CELL   = L'\u00b7',
};

class BaseApp;

class View
{
public:
	View(const int w, const int h);
	virtual ~View() = default;

	virtual void Show(BaseApp *app) const;
	virtual void Clear(BaseApp *app) const;

	void ShowText(const int x, const int y, const std::wstring &text, BaseApp *app) const;
protected:
	const int m_width;
	const int m_height;
};

