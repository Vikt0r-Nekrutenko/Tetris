#include "View.h"
#include "ConsolEngine/BaseApp.h"

View::View(const int w, const int h)
	: 
	m_width(w),
	m_height(h)
{

}

void View::Show(BaseApp * app) const
{
	for (int y = 0; y < m_height; ++y)
	{
		for (int x = 0; x < m_width; ++x)
		{
			if (x == 0 || x == m_width - 1 || y == 0 || y == m_height - 1)
			{
				app->SetChar(x, y, wchar_t(Particle::BORDER));
			}
		}
	}
}

void View::Clear(BaseApp * app) const
{
	for (int y = 0; y < m_height; ++y)
	{
		for (int x = 0; x < m_width; ++x)
		{
			app->SetChar(x, y, wchar_t(Particle::SPACE));
		}
	}
}

void View::ShowText(const int x, const int y, const std::wstring & text, BaseApp * app) const
{
	for (size_t i = 0; i < text.length(); ++i)
	{
		app->SetChar(x + i, y, text.at(i));
	}
}

void View::ShowNumber(const int cx, const int y, const int number, BaseApp * app) const
{
	std::wstring numberView = std::to_wstring(number);
	ShowText(cx - (numberView.length() >> 1), y, numberView, app);
}
