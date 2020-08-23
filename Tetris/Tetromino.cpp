#include "Tetromino.h"

Tetromino::Tetromino(const Vec2d & b1, const Vec2d & b2, const Vec2d & b3, const Vec2d & b4)
	: m_bricks({ b1, b2, b3, b4 })
{

}

JTetromino::JTetromino(const Vec2d & offset)
	: Tetromino(Vec2d(1, 0) + offset, Vec2d(1, 1) + offset, Vec2d(1, 2) + offset, Vec2d(0, 2) + offset)
{

}

TetrominoCreator::TetrominoCreator(const Vec2d offset)
	: m_offset(offset)
{
}

JTetrominoCreator::JTetrominoCreator(const int offsetX)
	: TetrominoCreator(Vec2d(offsetX, 0))
{

}

Tetromino * JTetrominoCreator::Create() const
{
	return new JTetromino(m_offset);
}
