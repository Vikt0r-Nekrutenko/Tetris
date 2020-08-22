#pragma once

#include "View.h"
#include <vector>

class MenuView : public View
{
public:
	MenuView(const int w, const int h);

	void Show(BaseApp *app) const final;
private:
	std::vector<std::wstring> m_items;
	int m_selector = 0;
};

