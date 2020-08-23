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

	inline float GetRotationAngle() const
	{
		return m_rotationAngle;
	}

	inline float GetDownVelocity() const
	{
		return m_downVelocity;
	}

	inline float GetRealY() const
	{
		return m_realY;
	}

	inline void IncreaseVelocity()
	{
		m_downVelocity = 15.f;
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

	void MoveDown(const float deltaTime)
	{
		m_realY += m_downVelocity * deltaTime;

		if (m_realY >= 1.f)
		{
			for (Vec2d &brick : m_bricks)
			{
				brick.y++;
			}
			m_realY = 0.f;
		}
	}

	virtual void Rotate(const Vec2d &origin)
	{
		for (Vec2d &brick : m_bricks)
		{
			brick = brick.Rotate(origin, m_rotationAngle);
		}
	}
protected:
	float m_rotationAngle = 1.57f;
	float m_downVelocity = 1.5f;
	float m_realY = 0.f;

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
