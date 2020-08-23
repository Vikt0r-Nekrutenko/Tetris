#include "Tetromino.h"

Tetromino::Tetromino(const Vec2d & b1, const Vec2d & b2, const Vec2d & b3, const Vec2d & b4)
	: m_bricks({ b1, b2, b3, b4 })
{

}

void Tetromino::MoveLeft()
{
	for (Vec2d &brick : m_bricks)
	{
		brick.x--;
	}
}

void Tetromino::MoveRight()
{
	for (Vec2d &brick : m_bricks)
	{
		brick.x++;
	}
}

void Tetromino::MoveDown(const float deltaTime)
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

void Tetromino::Rotate(const Vec2d & origin)
{
	for (Vec2d &brick : m_bricks)
	{
		brick = brick.Rotate(origin, m_rotationAngle);
	}
}

JTetromino::JTetromino(const Vec2d & offset)
	: Tetromino(Vec2d(1, 0) + offset, Vec2d(1, 1) + offset, Vec2d(1, 2) + offset, Vec2d(0, 2) + offset)
{
}

LTetromino::LTetromino(const Vec2d & offset)
	: Tetromino(Vec2d(0, 0) + offset, Vec2d(0, 1) + offset, Vec2d(0, 2) + offset, Vec2d(1, 2) + offset)
{
}

ITetromino::ITetromino(const Vec2d & offset)
	: NotSymmetricalTetromino(Vec2d(0, 0) + offset, Vec2d(0, 1) + offset, Vec2d(0, 2) + offset, Vec2d(0, 3) + offset)
{
}

TTetromino::TTetromino(const Vec2d & offset)
	: Tetromino(Vec2d(0, 0) + offset, Vec2d(1, 0) + offset, Vec2d(1, 1) + offset, Vec2d(2, 0) + offset)
{
}

OTetromino::OTetromino(const Vec2d & offset)
	: NotSymmetricalTetromino(Vec2d(0, 0) + offset, Vec2d(0, 1) + offset, Vec2d(1, 0) + offset, Vec2d(1, 1) + offset)
{
}

ZTetromino::ZTetromino(const Vec2d & offset)
	: NotSymmetricalTetromino(Vec2d(0, 0) + offset, Vec2d(1, 0) + offset, Vec2d(1, 1) + offset, Vec2d(2, 1) + offset)
{
}

STetromino::STetromino(const Vec2d & offset)
	: NotSymmetricalTetromino(Vec2d(2, 0) + offset, Vec2d(1, 0) + offset, Vec2d(1, 1) + offset, Vec2d(0, 1) + offset)
{
}

NotSymmetricalTetromino::NotSymmetricalTetromino(const Vec2d & b1, const Vec2d & b2, const Vec2d & b3, const Vec2d & b4)
	: Tetromino(b1, b2, b3, b4)
{
}

void NotSymmetricalTetromino::Rotate(const Vec2d & origin)
{
	Tetromino::Rotate(origin);
	m_rotationAngle = -m_rotationAngle;
}
