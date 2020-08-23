#include "Well.h"

Well::Well(const Vec2d size)
	: m_size(size)
{

}

void Well::Clear()
{
	m_bricks.clear();
}

void Well::PlaceBrick(const Vec2d & brick)
{
	m_bricks.push_back(Vec2d(brick));
}

int Well::CleanFilledLines()
{
	int cleanLines = 0;
	for (int y = 0; y < m_size.y; ++y)
	{
		int bricksOnLine = 0;
		for (const Vec2d &brick : m_bricks)
		{
			if (brick.y == y)
			{
				bricksOnLine++;
			}
		}

		if (bricksOnLine == m_size.x)
		{
			for (std::list<Vec2d>::iterator it = m_bricks.begin(); it != m_bricks.end(); )
			{
				if (it->y < y)
				{
					it->y++;
					++it;
				}
				else if (it->y == y)
				{
					it = m_bricks.erase(it);
				}
				else
				{
					++it;
				}
			}
			cleanLines++;
		}
	}
	return cleanLines;
}

bool Well::IsFull() const
{
	for (const Vec2d &brick : m_bricks)
	{
		if (brick.y == 0)
		{
			return true;
		}
	}
	return false;
}

