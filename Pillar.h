#pragma once
#include "GameObject.h"
class Pillar : public GameObject
{
public:
	sf::Sprite pillar;
	sf::Vector2f startPos;

	Pillar(const std::string n = "");
	virtual ~Pillar() override;

	virtual void SetPosition(const sf::Vector2f p);
	virtual void SetPosition(float x, float y);

	virtual void SetOrigin(Origins origin);
	virtual void SetOrigin(float x, float y);


	virtual void Init() override;	// 생성자 new 역할
	virtual void Release() override;	// 소멸자 delete 역할
	virtual void Reset() override;	// 값 세팅

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

};

