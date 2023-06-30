#pragma once
#include "GameObject.h"
class Block;

class Player : public GameObject
{
public:
	sf::Sprite sprite;
	sf::Vector2f velocity;
	sf::Vector2f jumpVelocity;
	sf::Vector2f gravity;

	float yPos;
	float jumpSpeed;

	bool isLeftCol;
	bool isRightCol;
	bool isGround;

	Player(const std::string n = "");
	virtual ~Player() override;

	virtual void SetPosition(const sf::Vector2f p);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);


	virtual void Init() override;	// 생성자 new 역할
	virtual void Release() override;	// 소멸자 delete 역할
	virtual void Reset() override;	// 값 세팅

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetGravity(sf::Vector2f gravity);
	void CollideBlock(sf::FloatRect other);
	//sf::FloatRect GetPlayerCol();
	void SetGravity();

	//void SetBlock(Block*& block);
};

