#pragma once

#include "Tetromino.h"

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