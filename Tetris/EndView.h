#pragma once
#include "View.h"

class GameModel;

class EndView : public View
{
public:
	EndView(GameModel * model, const int w, const int h);

	void Show(BaseApp * app) const final;
	State KeyHandler(const Key &key) final;

private:
	GameModel *m_model;
};

