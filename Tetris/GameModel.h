#pragma once

#include "Tetromino.h"
#include "Keys.h"

class GameModel
{
public:
	GameModel(const int w, const int h);
	~GameModel();

	const Vec2d m_size;

	inline float GetScore() const
	{
		return m_score;
	}

	inline int GetLevel() const
	{
		return m_level;
	}

	inline int GetLines() const
	{
		return m_lines;
	}

	inline const Tetromino *GetCurrentTetromino() const
	{
		return m_currentTetromino;
	}

	void KeyHandler(const Key &key);
private:
	Tetromino *m_currentTetromino = nullptr;
	float m_score = 0.f;
	int m_level = 1;
	int m_lines = 0;
};

