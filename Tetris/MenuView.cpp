#include "MenuView.h"



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

	View::Show(app);
}
