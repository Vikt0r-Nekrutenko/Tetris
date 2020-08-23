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
	// show next tetramino

	const int infoCenterX = m_model->m_width + ((m_width - m_model->m_width) >> 1);
	ShowText(info_x, 9, L"Score", app);
	ShowNumber(infoCenterX, 11, int(m_model->GetScore()), app);

	ShowText(info_x, 15, L"Level", app);
	ShowNumber(infoCenterX, 17, int(m_model->GetLevel()), app);

	ShowText(info_x, 21, L"Lines", app);
	ShowNumber(infoCenterX, 23, int(m_model->GetLines()), app);

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
