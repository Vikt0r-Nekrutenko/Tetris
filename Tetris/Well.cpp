#include "Well.h"

Well::Well(const Vec2d size)
	: m_size(size)
{

}

void Well::PlaceBrick(const Vec2d & brick)
{
	m_bricks.push_back(Vec2d(brick));
}

