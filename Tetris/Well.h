#pragma once

#include "Vec2d.h"
#include <list>

class Well
{
public:
	const Vec2d m_size;

	Well(const Vec2d size);

	inline const std::list<Vec2d> &GetBricks() const
	{
		return m_bricks;
	}

	void PlaceBrick(const Vec2d &brick);
	int CleanFilledLines();
private:
	std::list<Vec2d> m_bricks;
};

