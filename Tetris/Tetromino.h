#pragma once

#include <vector>
#include <functional>
#include "Vec2d.h"

class Tetromino
{
public:
	Tetromino(const Vec2d &b1, const Vec2d &b2, const Vec2d &b3, const Vec2d &b4);
	virtual ~Tetromino() = default;

	inline const std::vector<Vec2d> &GetBricks() const
	{
		return m_bricks;
	}

	void MoveLeft()
	{
		for (Vec2d &brick : m_bricks)
		{
			brick.x--;
		}
	}

	void MoveRight()
	{
		for (Vec2d &brick : m_bricks)
		{
			brick.x++;
		}
	}
private:
	std::vector<Vec2d> m_bricks;
};


class JTetromino : public Tetromino
{
public:
	JTetromino(const Vec2d &offset);
};

class TetrominoCreator
{
public:
	TetrominoCreator(const Vec2d offset);

	virtual Tetromino *Create() const = 0;
protected:
	const Vec2d m_offset;
};

class JTetrominoCreator : public TetrominoCreator
{
public:
	JTetrominoCreator(const int offsetX);
	Tetromino *Create() const final;
};
