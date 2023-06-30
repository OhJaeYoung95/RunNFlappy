#include "stdafx.h"
#include "Bird.h"
#include "InputMgr.h"

Bird::Bird(const std::string n) : GameObject(n), gravity(9.8f), jumpForce(4.f), isLive(true)
{
}

Bird::~Bird()
{
}

void Bird::SetPosition(const sf::Vector2f p)
{
	position = p;
	bird.setPosition(p);
}

void Bird::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	bird.setPosition(position);
}

void Bird::SetOrigin(Origins origin)
{
	GameObject::SetOrigin(origin);
	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(bird, origin);
	}
}

void Bird::SetOrigin(float x, float y)
{
	GameObject::SetOrigin(x, y);
	bird.setOrigin(x, y);
}

void Bird::Init()
{

}

void Bird::Release()
{
}

void Bird::Reset()
{
}

void Bird::Update(float dt)
{
	if (isLive)
	{
		if (INPUT_MGR.GetKeyDown(sf::Keyboard::Space))
		{
			velocity = { 0, -1.f * jumpForce };
		}
	}
	velocity.y += gravity * dt;
	bird.setPosition(bird.getPosition() + velocity);
}

void Bird::Draw(sf::RenderWindow& window)
{
	window.draw(bird);
}
