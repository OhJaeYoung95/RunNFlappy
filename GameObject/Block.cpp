#include "stdafx.h"
#include "Block.h"
#include "Player.h"

Block::Block(const std::string n) : GameObject(n) , isCol(false)
{
}

Block::~Block()
{
}

void Block::SetPosition(const sf::Vector2f p)
{
	position = p;
	block.setPosition(p);
}

void Block::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	block.setPosition(position);
}

void Block::SetOrigin(Origins origin)
{
	GameObject::SetOrigin(origin);
	if (this->origin != Origins::CUSTOM)
	{
		Utils::SetOrigin(block, origin);
	}
}

void Block::SetOrigin(float x, float y)
{
	GameObject::SetOrigin(x, y);
	block.setOrigin(x, y);
}

void Block::Init()
{

}

void Block::Release()
{
}

void Block::Reset()
{

}	

void Block::Update(float dt)
{
	float blockBottom = blockCol.top + blockCol.height;
	float blockTop = blockCol.top;
	float blockRight = blockCol.left + blockCol.width;
	float blockLeft = blockCol.left;
	
	float playerBottom = player->sprite.getGlobalBounds().top 
		+ player->sprite.getGlobalBounds().height;
	float playerTop = player->sprite.getGlobalBounds().top;
	float playerRight = player->sprite.getGlobalBounds().left 
		+ player->sprite.getGlobalBounds().width;
	float playerLeft = player->sprite.getGlobalBounds().left;


	if (isCol && !blockCol.intersects(player->sprite.getGlobalBounds()))
	{
		isCol = false;
		player->isGround = false;
	}

	if (isCol)
	{
		player->isLeftCol = false;
		player->isRightCol = false;

		if (tempRect.width > tempRect.height)	// 블록 상하
		{
			if (playerTop == tempRect.top)		// 블록 밑
			{
				player->isGround = false;
				player->velocity.y = 5.f;
			}
			else			// 블록 위
			{
				player->isGround = true;
				player->velocity.y = 0;
			}
		}
		else if (tempRect.width < tempRect.height)
		{
			if (playerLeft == tempRect.left)
			{
				player->isLeftCol = true;
			}
			 
			if (playerLeft < tempRect.left)
			{
				player->isRightCol = true;
			}
		}
	}
}

void Block::Draw(sf::RenderWindow& window)
{
	window.draw(block);
}

void Block::CheckCollide(sf::FloatRect other)
{
	if (blockCol.intersects(other))
	{
		isCol = true;
	}
	if (!blockCol.intersects(other))
	{
		isCol = false;
	}
}

sf::FloatRect Block::GetBlockCol()
{
	return block.getGlobalBounds();
}

void Block::SetPlayer(Player*& player)
{
	this->player = player;
}

