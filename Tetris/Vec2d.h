#pragma once

#include <cmath>

struct Vec2d
{
	int x;
	int y;

	Vec2d(const int x, const int y)
	{
		this->x = x;
		this->y = y;
	}

	inline Vec2d operator +(const Vec2d &vec) const
	{
		return Vec2d(x + vec.x, y + vec.y);
	}

	inline Vec2d operator -(const Vec2d &vec) const
	{
		return Vec2d(x - vec.x, y - vec.y);
	}

	bool operator ==(const Vec2d &vec) const
	{
		Vec2d z = *this - vec;
		return std::abs(z.x) < 1 && std::abs(z.y) < 1;
	}

	Vec2d Rotate(const Vec2d &origin, const float angle) const
	{
		float s = std::sin(angle);
		float c = std::cos(angle);

		Vec2d noOffset = *this - origin;
		float newX = noOffset.x * c - noOffset.y * s;
		float newY = noOffset.x * s + noOffset.y * c;

		return Vec2d(origin.x + int(std::lround(newX)), 
					 origin.y + int(std::lround(newY)));
	}
};

