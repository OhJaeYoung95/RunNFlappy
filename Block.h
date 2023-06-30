#pragma once
#include "GameObject.h"

class Player;

class Block : public GameObject
{
public:
	sf::RectangleShape block;
	sf::FloatRect blockCol;
	sf::FloatRect tempRect;
	Player* player;

	bool isCol;

	Block(const std::string n = "");
	virtual ~Block() override;

	virtual void SetPosition(const sf::Vector2f p);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);


	virtual void Init() override;	// ������ new ����
	virtual void Release() override;	// �Ҹ��� delete ����
	virtual void Reset() override;	// �� ����

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void CheckCollide(sf::FloatRect other);

	sf::FloatRect GetBlockCol();
	void SetPlayer(Player*& player);

};

