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

		if (y == 7 || y == 13 || y == 19)
		{
			for (int x = m_model->m_width + 1; x < m_width; ++x)
			{
				app->SetChar(x, y, wchar_t(Particle::BORDER));
			}
		}
	}

	const int info_x = m_model->m_width + 3;
	ShowText(info_x + 2, 2, L"\u25d9",app);
	ShowText(info_x + 2, 3, L"\u25d9",app);
	ShowText(info_x + 2, 4, L"\u25d9", app);
	ShowText(info_x + 2, 5, L"\u25d9", app);

	const int infoCenterX = m_model->m_width + ((m_width - m_model->m_width) >> 1);
	ShowText(info_x, 9, L"Score", app);
	std::wstring scoreView = std::to_wstring(int(m_model->GetScore()));
	ShowText(infoCenterX - (scoreView.length() >> 1), 11, scoreView, app);

	ShowText(info_x, 15, L"Level", app);
	std::wstring levelView = std::to_wstring(int(m_model->GetLevel()));
	ShowText(infoCenterX - (levelView.length() >> 1), 17, levelView, app);

	ShowText(info_x, 21, L"Lines", app);
	std::wstring linesView = std::to_wstring(int(m_model->GetLines()));
	ShowText(infoCenterX - (linesView.length() >> 1), 23, linesView, app);

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
