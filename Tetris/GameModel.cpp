#include "GameModel.h"

GameModel::GameModel(const int w, const int h)
	: m_size(w, h)
{
	m_currentTetromino = new JTetromino(Vec2d(w / 2, 0));
}

GameModel::~GameModel()
{
	delete m_currentTetromino;
}
