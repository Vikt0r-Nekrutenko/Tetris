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
		m_downVelocity = 25.f;
	}

	void MoveLeft();

	void MoveRight();

	void MoveDown(const float deltaTime);

	virtual void Rotate(const Vec2d &origin);

protected:
	float m_rotationAngle = 1.57f;
	float m_downVelocity = 2.f;
	float m_realY = 0.f;

private:
	std::vector<Vec2d> m_bricks;
};

class NotSymmetricalTetromino : public Tetromino
{
public:
	NotSymmetricalTetromino(const Vec2d &b1, const Vec2d &b2, const Vec2d &b3, const Vec2d &b4);
	void Rotate(const Vec2d &origin) override;
};

class JTetromino : public Tetromino
{
public:
	JTetromino(const Vec2d &offset);
};

class LTetromino : public Tetromino
{
public:
	LTetromino(const Vec2d &offset);
};

class ITetromino : public NotSymmetricalTetromino
{
public:
	ITetromino(const Vec2d &offset);
};

class TTetromino : public Tetromino
{
public:
	TTetromino(const Vec2d &offset);
};

class OTetromino : public NotSymmetricalTetromino
{
public:
	OTetromino(const Vec2d &offset);
	void Rotate(const Vec2d &origin) final { }
};

class ZTetromino : public NotSymmetricalTetromino
{
public:
	ZTetromino(const Vec2d &offset);
};

class STetromino : public NotSymmetricalTetromino
{
public:
	STetromino(const Vec2d &offset);
};