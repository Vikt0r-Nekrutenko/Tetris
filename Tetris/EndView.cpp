#include "EndView.h"
#include "GameModel.h"

EndView::EndView(GameModel * model, const int w, const int h)
	: View(w, h), m_model(model)
{
}

void EndView::Show(BaseApp * app) const
{
	const int viewCenterX = m_width >> 1;
	ShowText(viewCenterX - 4, 4, L"GAME OVER", app);
	ShowText(viewCenterX - 4, 5, L"\x3d\x3d\x3d\x3d\x3d\x3d\x3d\x3d\x3d", app);

	ShowText(viewCenterX - 5, 8, L"Your score:", app);
	ShowNumber(viewCenterX, 10, m_model->GetScore(), app);
	
	ShowText(viewCenterX - 5, 12, L"Your lines:", app);
	ShowNumber(viewCenterX, 14, m_model->GetLines(), app);
	
	ShowText(viewCenterX - 5, 16, L"Your level:", app);
	ShowNumber(viewCenterX, 18, m_model->GetLevel(), app);

	ShowText(viewCenterX - 7, 23, L"(press any key)", app);
	View::Show(app);
}

State EndView::KeyHandler(const Key & key)
{
	m_model->ResetModel();
	return State::PAUSE;
}
