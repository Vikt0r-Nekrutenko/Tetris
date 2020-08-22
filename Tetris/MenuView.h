#pragma once

#include "View.h"
#include "Keys.h"
#include <vector>

enum class MenuItem
{
	NONE	 = 0xff,
	CONTINUE = 0x00,
	NEW_GAME = 0x01,
	EXIT	 = 0x02,
};

class MenuView : public View
{
public:
	MenuView(const int w, const int h);

	void Show(BaseApp *app) const final;
	MenuItem KeyHandler(const Key &key);
private:
	std::vector<std::wstring> m_items;
	int m_selector = 0;
};

