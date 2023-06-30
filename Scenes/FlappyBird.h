#pragma once
#include "Scene.h"
class FlappyBird : public Scene
{
public:
	FlappyBird();
	virtual ~FlappyBird() override = default;

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};

