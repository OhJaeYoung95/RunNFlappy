#include "stdafx.h"
#include "Pillar.h"
#include "Framework.h"

Pillar::Pillar(const std::string n) : GameObject(n)
{
}

Pillar::~Pillar()
{
}

void Pillar::SetPosition(const sf::Vector2f p)
{
	position = p;
	pillar.setPosition(p);
}

void Pillar::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	pillar.setPosition(position);
}

void Pillar::SetOrigin(Origins origin)
{
	GameObject::SetOrigin(origin);
	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(pillar, origin);
	}
}

void Pillar::SetOrigin(float x, float y)
{
	GameObject::SetOrigin(x, y);
	pillar.setOrigin(x, y);
}

void Pillar::Init()
{
}

void Pillar::Release()
{
}

void Pillar::Reset()
{
}

void Pillar::Update(float dt)
{
	position.x += -400.f * dt;

	if (pillar.getPosition().x <= 0)
	{
		std::cout << startPos.x << std::endl;
		std::cout << pillar.getPosition().x << std::endl;
		pillar.setScale(1.f, Utils::RandomRange(1.0f, 2.0f));
		SetPosition(startPos);
	}
	else
	{
		SetPosition(position);
	}

}

void Pillar::Draw(sf::RenderWindow& window)
{
	window.draw(pillar);
}
