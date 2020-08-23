#include "MenuView.h"
#include "ConsolEngine\BaseApp.h"


MenuView::MenuView(const int w, const int h)
	: View(w, h),
	m_items({ L"Continue", L"New game", L"Exit" })
{

}

void MenuView::Show(BaseApp * app) const
{
	int offset_y = 0;
	for (const std::wstring &item : m_items)
	{
		int x = (m_width >> 1) - (item.length() >> 1);
		ShowText(x, 8 + offset_y, item, app);

		offset_y += 2;
	}

	int lselector_x = (m_width >> 1) - (m_items.at(m_selector).length() >> 1) - 2;
	app->SetChar(lselector_x, 8 + m_selector * 2, wchar_t(Particle::LSELECTOR));
	
	int rselector_x = lselector_x + m_items.at(m_selector).length() + 3;
	app->SetChar(rselector_x, 8 + m_selector * 2, wchar_t(Particle::RSELECTOR));

	View::Show(app);
}

State MenuView::KeyHandler(const Key & key)
{
	switch (key)
	{
	case Key::UP:
		if (m_selector > 0)
		{
			m_selector--;
		}
		break;
	case Key::DOWN:
		if (m_selector < m_items.size() - 1)
		{
			m_selector++;
		}
		break;
	case Key::ENTER:
		return State(m_selector);
		break;
	}
	return State::NONE;
}
