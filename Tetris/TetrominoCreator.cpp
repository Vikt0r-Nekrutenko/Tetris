#include "TetrominoCreator.h"

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