#pragma once

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
protected:
	const int m_width;
	const int m_height;
};

