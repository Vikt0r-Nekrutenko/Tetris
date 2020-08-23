#include "GameModel.h"

GameModel::GameModel(const int w, const int h)
	: m_size(w, h),
	m_well(Vec2d(w, h))
{
	m_currentTetromino = new JTetromino(Vec2d(w / 2, 0));
}

GameModel::~GameModel()
{
	delete m_currentTetromino;
}

void GameModel::KeyHandler(const Key & key)
{
	switch (key)
	{
	case Key::LEFT:
		if (MotionIsValid([](std::vector<Vec2d> &newBricksPositions, const Vec2d &brick) {
			newBricksPositions.push_back(brick + Vec2d(-1, 0));
		}) == true)
		{
			m_currentTetromino->MoveLeft();
		}
		break;

	case Key::RIGHT:
		if (MotionIsValid([](std::vector<Vec2d> &newBricksPositions, const Vec2d &brick) {
			newBricksPositions.push_back(brick + Vec2d(+1, 0));
		}) == true)
		{
			m_currentTetromino->MoveRight();
		}
		break;

	case Key::DOWN:
		m_currentTetromino->IncreaseVelocity();
		break;

	case Key::SPACE:
		if (MotionIsValid([this](std::vector<Vec2d> &newBricksPositions, const Vec2d &brick) {
			newBricksPositions.push_back(brick.Rotate(GetCurrentTetromino()->GetBricks().at(1), GetCurrentTetromino()->GetRotationAngle()));
		}) == true)
		{
			m_currentTetromino->Rotate(m_currentTetromino->GetBricks().at(1));
		}
		break;
	}
}

void GameModel::Update(const float deltaTime)
{
	if (MotionIsValid([this, deltaTime](std::vector<Vec2d> &newBricksPositions, const Vec2d &brick) {
		int newBrickY = GetCurrentTetromino()->GetRealY() + GetCurrentTetromino()->GetDownVelocity() * deltaTime;
		newBricksPositions.push_back(brick + Vec2d(0, newBrickY));
	}) == true)
	{
		m_currentTetromino->MoveDown(deltaTime);
	}
	else 
	{
		for (const Vec2d &brick : m_currentTetromino->GetBricks())
		{
			m_well.PlaceBrick(brick);
		}

		delete m_currentTetromino;

		m_currentTetromino = new JTetromino(Vec2d(m_size.x / 2, 0));

		m_lines += m_well.CleanFilledLines();
	}
}

bool GameModel::MotionIsValid(std::function<void(std::vector<Vec2d> &, const Vec2d &)> motionFunction) const
{
	std::vector<Vec2d> newBrickPositions;

	for (const Vec2d &brick : m_currentTetromino->GetBricks())
	{
		motionFunction(newBrickPositions, brick);

		if (newBrickPositions.back().x < 0 || newBrickPositions.back().y < 0 || newBrickPositions.back().x >= m_size.x || newBrickPositions.back().y >= m_size.y)
		{
			return false;
		}

		for (const Vec2d &brick : m_well.GetBricks())
		{
			if (newBrickPositions.back() == brick)
			{
				return false;
			}
		}
	}
	return true;
}
