#pragma once

#include "TetrominoCreator.h"
#include "Keys.h"
#include "Well.h"
#include "View.h"

#include <random>

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

	inline const Tetromino *GetNextTetromino() const
	{
		return m_nextTetromino;
	}

	inline const Well &GetWell() const
	{
		return m_well;
	}
	void ResetModel();

	void KeyHandler(const Key &key);

	State Update(const float deltaTime);
private:
	bool MoveIsPossible(std::function<void(std::vector<Vec2d> &, const Vec2d &)> motionFunction) const;

	std::vector<const TetrominoCreator *> m_creators;
	Well m_well;

	std::random_device m_device;
	std::mt19937 m_engine;
	
	Tetromino *m_currentTetromino = nullptr;
	Tetromino *m_nextTetromino = nullptr;

	float m_score = 0.f;
	float m_factor = 1.f;
	int m_level = 1;
	int m_lines = 0;
};

