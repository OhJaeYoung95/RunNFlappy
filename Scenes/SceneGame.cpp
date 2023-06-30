#include "stdafx.h"
#include "SceneGame.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "GameObject.h"
#include "Framework.h"
#include "Player.h"
#include "Block.h"

SceneGame::SceneGame() : Scene(SceneId::Game)
{
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/Cream Unicorn Cookie.png"));
}

void SceneGame::Init()
{
	Release();
	AddGo(new Player("Player"));
	for (int i = 0; i < 3; i++)
	{
		std::string s = "Block" + std::to_string(i);
		AddGo(new Block(s));
	}
	for (auto go : gameObjects)
	{
		go->Init();
	}
}

void SceneGame::Release()
{
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void SceneGame::Enter()
{
	Scene::Enter();

	auto player = (Player*)FindGo("Player");
	player->sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/Cream Unicorn Cookie.png"));
	player->SetOrigin(Origins::BC);
	player->sprite.setPosition(FRAMEWORK.GetWindowSize().x * 0.5f, FRAMEWORK.GetWindowSize().y * 0.5f + 300.f);
	player->sortLayer = 1;
	player->sortOrder = 1;

	auto bottom = (Block*)FindGo("Block0");
	bottom->block.setSize(sf::Vector2f(FRAMEWORK.GetWindowSize().x, 100.f));
	bottom->SetOrigin(Origins::BL);
	bottom->SetPosition(0, FRAMEWORK.GetWindowSize().y);
	bottom->SetPlayer(player);
	bottom->blockCol = bottom->block.getGlobalBounds();
	bottom->sortLayer = 1;
	bottom->sortOrder = 0;
	
	bottom = (Block*)FindGo("Block1");
	bottom->block.setSize(sf::Vector2f(100.f, 30.f));
	bottom->SetOrigin(Origins::BL);
	bottom->SetPosition(300.f, 500.f);
	bottom->SetPlayer(player);
	bottom->blockCol = bottom->block.getGlobalBounds();
	bottom->sortLayer = 1;
	bottom->sortOrder = 0;

	bottom = (Block*)FindGo("Block2");
	bottom->block.setSize(sf::Vector2f(150.f, 30.f));
	bottom->SetOrigin(Origins::BL);
	bottom->SetPosition(500.f , 700.f);
	bottom->SetPlayer(player);
	bottom->blockCol = bottom->block.getGlobalBounds();
	bottom->sortLayer = 1;
	bottom->sortOrder = 0;

}

void SceneGame::Exit()
{
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);
	auto player = (Player*)FindGo("Player");
	for (int i = 0; i < 3; i++)
	{
		std::string s = "Block" + std::to_string(i);
		auto block = (Block*)FindGo(s);
		sf::FloatRect tempRect;
		if (player->sprite.getGlobalBounds().intersects(block->blockCol, tempRect))
		{
			block->tempRect = tempRect;
			block->isCol = true;
		}
	}
	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneId::Title);
	}
}


void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);

}
