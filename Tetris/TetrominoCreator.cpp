#include "TetrominoCreator.h"

TetrominoCreator::TetrominoCreator(const Vec2d offset)
	: m_offset(offset)
{
}

JTetrominoCreator::JTetrominoCreator(const int offsetX)
	: TetrominoCreator(Vec2d(offsetX - 1, 0))
{

}


LTetrominoCreator::LTetrominoCreator(const int offsetX)
	: TetrominoCreator(Vec2d(offsetX - 1, 0))
{

}


TTetrominoCreator::TTetrominoCreator(const int offsetX)
	: TetrominoCreator(Vec2d(offsetX - 2, 0))
{

}


OTetrominoCreator::OTetrominoCreator(const int offsetX)
	: TetrominoCreator(Vec2d(offsetX - 1, 0))
{

}


ITetrominoCreator::ITetrominoCreator(const int offsetX)
	: TetrominoCreator(Vec2d(offsetX - 1, 0))
{

}


ZTetrominoCreator::ZTetrominoCreator(const int offsetX)
	: TetrominoCreator(Vec2d(offsetX - 2, 0))
{

}


STetrominoCreator::STetrominoCreator(const int offsetX)
	: TetrominoCreator(Vec2d(offsetX - 2, 0))
{

}

Tetromino * JTetrominoCreator::Create() const
{
	return new JTetromino(m_offset);
}

Tetromino * LTetrominoCreator::Create() const
{
	return new LTetromino(m_offset);
}

Tetromino * TTetrominoCreator::Create() const
{
	return new TTetromino(m_offset);
}

Tetromino * OTetrominoCreator::Create() const
{
	return new OTetromino(m_offset);
}

Tetromino * ITetrominoCreator::Create() const
{
	return new ITetromino(m_offset);
}

Tetromino * ZTetrominoCreator::Create() const
{
	return new ZTetromino(m_offset);
}

Tetromino * STetrominoCreator::Create() const
{
	return new STetromino(m_offset);
}