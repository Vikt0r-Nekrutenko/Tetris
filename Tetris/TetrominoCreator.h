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

class LTetrominoCreator : public TetrominoCreator
{
public:
	LTetrominoCreator(const int offsetX);
	Tetromino *Create() const final;
};

class TTetrominoCreator : public TetrominoCreator
{
public:
	TTetrominoCreator(const int offsetX);
	Tetromino *Create() const final;
};

class OTetrominoCreator : public TetrominoCreator
{
public:
	OTetrominoCreator(const int offsetX);
	Tetromino *Create() const final;
};

class ITetrominoCreator : public TetrominoCreator
{
public:
	ITetrominoCreator(const int offsetX);
	Tetromino *Create() const final;
};

class STetrominoCreator : public TetrominoCreator
{
public:
	STetrominoCreator(const int offsetX);
	Tetromino *Create() const final;
};

class ZTetrominoCreator : public TetrominoCreator
{
public:
	ZTetrominoCreator(const int offsetX);
	Tetromino *Create() const final;
};