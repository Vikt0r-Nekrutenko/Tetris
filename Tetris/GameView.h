#pragma once

#include "View.h"

class GameModel;

class GameView : public View
{
public:
	GameView(GameModel *model, const int w, const int h);

	void Show(BaseApp *app) const final;
	void Clear(BaseApp *app) const final;

	State KeyHandler(const Key &key) final;
	State Update(const float deltaTime) final;
	
private:
	GameModel *m_model;
};

