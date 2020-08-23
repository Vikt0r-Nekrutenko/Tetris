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
	if (m_model->GetCurrentTetromino() != nullptr)
	{
		for (const Vec2d &brick : m_model->GetCurrentTetromino()->GetBricks())
		{
			app->SetChar(brick.x + 1, brick.y + 1, wchar_t(Particle::BRICK));
		}
	}

	for (const Vec2d &brick : m_model->GetWell().GetBricks())
	{
		app->SetChar(brick.x + 1, brick.y + 1, wchar_t(Particle::BRICK));
	}

	for (int y = 0; y < m_height; ++y)
	{
		app->SetChar(m_model->m_size.x + 1, y, wchar_t(Particle::BORDER));

		if (y == 7 || y == 13 || y == 19)
		{
			for (int x = m_model->m_size.x + 1; x < m_width; ++x)
			{
				app->SetChar(x, y, wchar_t(Particle::BORDER));
			}
		}
	}

	if (m_model->GetNextTetromino() != nullptr)
	{
		const int offsetX = m_model->m_size.x - 1;
		for (const Vec2d &brick : m_model->GetNextTetromino()->GetBricks())
		{
			app->SetChar(brick.x + offsetX, brick.y + 2, wchar_t(Particle::BRICK));
		}
	}

	const int info_x = m_model->m_size.x + 3;
	const int infoCenterX = m_model->m_size.x + ((m_width - m_model->m_size.x) >> 1);
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

	for (int y = 1; y < m_model->m_size.y + 1; ++y)
	{
		for (int x = 1; x < m_model->m_size.x + 1; ++x)
		{
			if (x % 2 == 0)
			{
				app->SetChar(x, y, wchar_t(Particle::CELL));
			}
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

	m_model->KeyHandler(key);
	return State::NONE;
}

State GameView::Update(const float deltaTime)
{
	return m_model->Update(deltaTime);
}
