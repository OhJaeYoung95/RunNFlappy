#pragma once
#include "Scene.h"

class SceneGame : public Scene
{
public:

	sf::FloatRect playerCol;
	sf::FloatRect bottomCol;
	sf::FloatRect col1;
	sf::FloatRect col2;

	SceneGame();
	virtual ~SceneGame() override = default;

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

};

