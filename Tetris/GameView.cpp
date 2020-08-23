#include "GameView.h"
#include "GameModel.h"
#include "ConsolEngine\BaseApp.h"

GameView::GameView(GameModel * model , const int w, const int h)
	: View(w, h),
	m_model(model)
{

}

void GameView::Show(BaseApp * app) const
{
	for (int y = 0; y < m_height; ++y)
	{
		app->SetChar(m_model->m_width + 1, y, wchar_t(Particle::BORDER));
	}

	int info_x = m_model->m_width + 3;
	ShowText(info_x + 2, 2, L"\u25d9",app);
	ShowText(info_x + 2, 3, L"\u25d9",app);
	ShowText(info_x + 2, 4, L"\u25d9", app);
	ShowText(info_x + 2, 5, L"\u25d9", app);

	for (int x = m_model->m_width + 1; x < m_width; ++x)
	{
		app->SetChar(x, 7, wchar_t(Particle::BORDER));
	}

	ShowText(info_x, 9, L"Score", app);
	ShowText(info_x, 11, L"12032", app);

	for (int x = m_model->m_width + 1; x < m_width; ++x)
	{
		app->SetChar(x, 13, wchar_t(Particle::BORDER));
	}

	ShowText(info_x, 15, L"Level", app);
	ShowText(info_x, 17, L"12", app);

	for (int x = m_model->m_width + 1; x < m_width; ++x)
	{
		app->SetChar(x, 19, wchar_t(Particle::BORDER));
	}

	ShowText(info_x, 21, L"Lines", app);
	ShowText(info_x, 23, L"124", app);

	ShowText(1, 1, L"O", app);
	ShowText(m_model->m_width, m_model->m_height, L"O", app);

	View::Show(app);
}

void GameView::Clear(BaseApp * app) const
{
	View::Clear(app);

	for (int y = 1; y < m_model->m_height + 1; ++y)
	{
		for (int x = 1; x < m_model->m_width + 1; ++x)
		{
			app->SetChar(x, y, wchar_t(Particle::CELL));
		}
	}
}

State GameView::KeyHandler(const Key & key)
{
	switch (key)
	{
	case Key::ESCAPE:
		return State::PAUSE;
		break;
	}
	return State::NONE;
}
