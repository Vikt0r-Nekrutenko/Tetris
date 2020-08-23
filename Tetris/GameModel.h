#pragma once
class GameModel
{
public:
	GameModel(const int w, const int h);
	~GameModel();

	const int m_width;
	const int m_height;

	inline float GetScore() const
	{
		return m_score;
	}

	inline int GetLevel() const
	{
		return m_level;
	}

	inline int GetLines() const
	{
		return m_lines;
	}
private:
	float m_score = 0.f;
	int m_level = 1;
	int m_lines = 1;
};

