#include "stdafx.h"
#include "Player.h"
#include "InputMgr.h"
#include "Block.h"

Player::Player(const std::string n) : GameObject(n), velocity({ 0,0 }), gravity({ 0, 3.0f }), jumpVelocity({ 0, -50.f }), isGround(false), yPos(0), jumpSpeed(50.f), isLeftCol(false), isRightCol(false)
{
}

Player::~Player()
{
}

void Player::SetPosition(const sf::Vector2f p)
{
	position = p;
	sprite.setPosition(p);
}

void Player::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	sprite.setPosition(position);
}

void Player::SetOrigin(Origins origin)
{
	GameObject::SetOrigin(origin);
	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(sprite, origin);
	}
}

void Player::SetOrigin(float x, float y)
{
	GameObject::SetOrigin(x, y);
	sprite.setOrigin(x, y);
}

void Player::Init()
{
	Reset();
}

void Player::Release()
{
}

void Player::Reset()
{
	velocity = { 0, 0 };
	jumpVelocity = { 0,  -50.f};
	gravity = { 0, 3.0f };
}

void Player::Update(float dt)
{	
	if (INPUT_MGR.GetKey(sf::Keyboard::A) && !isLeftCol)
	{
		sprite.setScale(1.f, 1.f);
		sf::Vector2f pos = sprite.getPosition();
		pos += sf::Vector2f(-400.0f, 0.f)* dt;
		sprite.setPosition(pos);
	}
	if (INPUT_MGR.GetKey(sf::Keyboard::D) && !isRightCol)
	{
		sprite.setScale(-1.f, 1.f);
		sf::Vector2f pos = sprite.getPosition();
		pos += sf::Vector2f(400.0f, 0.f) * dt;
		sprite.setPosition(pos);
	}
	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Space) &&isGround)
	{
		isGround = false;
		sf::Vector2f pos = sprite.getPosition();
		velocity.y = jumpVelocity.y;
	}
	if (!isGround)
	{
		sf::Vector2f pos = sprite.getPosition();
		pos.y += velocity.y * dt * jumpSpeed;
		velocity.y += gravity.y * dt * jumpSpeed;
		sprite.setPosition(pos);
	}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Player::SetGravity(sf::Vector2f gravity)
{
	this->gravity = gravity;
}

void Player::CollideBlock(sf::FloatRect other)
{

}

void Player::SetGravity()
{
	velocity.y = 0;
	isGround = true;
}