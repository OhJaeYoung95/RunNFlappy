#pragma once
#include "GameObject.h"
class Bird : public GameObject
{
public:
	sf::Sprite bird;
	sf::Vector2f velocity;
	float jumpForce;
	float gravity;

	bool isLive;


	Bird(const std::string n = "");
	virtual ~Bird() override;

	virtual void SetPosition(const sf::Vector2f p);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);


	virtual void Init() override;	// ������ new ����
	virtual void Release() override;	// �Ҹ��� delete ����
	virtual void Reset() override;	// �� ����

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};

