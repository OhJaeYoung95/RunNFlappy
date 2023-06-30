#include "stdafx.h"
#include "FlappyBird.h"
#include "ResourceMgr.h"
#include "Framework.h"
#include "InputMgr.h"
#include "Bird.h"
#include "Pillar.h"
#include "TextGo.h"

FlappyBird::FlappyBird() : Scene(SceneId::Flappy)
{
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/bird.png"));
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/bg_pillarDown.png"));
	resources.push_back(std::make_tuple(ResourceTypes::Font, "fonts/KOMIKAP_.ttf"));
}

void FlappyBird::Init()
{
	Release();
	AddGo(new Bird("Bird"));
	for (int i = 0; i < 4; i++)
	{
		std::string s = "Pillar" + std::to_string(i);
		AddGo(new Pillar(s));
	}

	AddGo(new TextGo("DieLog"));

	for (auto go : gameObjects)
	{
		go->Init();
	}
}

void FlappyBird::Release()
{
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void FlappyBird::Enter()
{
	Scene::Enter();
	auto bird = (Bird*)FindGo("Bird");
	bird->bird.setTexture(*RESOURCE_MGR.GetTexture("graphics/bird.png"));
	bird->SetOrigin(Origins::BC);
	bird->SetPosition(50.f, FRAMEWORK.GetWindowSize().y * 0.5f);
	bird->sortLayer = 1;
	
	for (size_t i = 0; i < 4; i++)
	{
		std::string s = "Pillar" + std::to_string(i);
		auto pillar = (Pillar*)FindGo(s);
		pillar->pillar.setTexture(*RESOURCE_MGR.GetTexture("graphics/bg_pillarDown.png"));
		pillar->SetOrigin(Origins::BR);
		pillar->SetPosition(FRAMEWORK.GetWindowSize().x + i * 450, FRAMEWORK.GetWindowSize().y);
		pillar->startPos = { FRAMEWORK.GetWindowSize().x , FRAMEWORK.GetWindowSize().y };
		pillar->pillar.setScale(1.f, Utils::RandomRange(1.0f, 2.0f));
		pillar->sortLayer = 0;

	}

	auto text = (TextGo*)FindGo("DieLog");
	text->text.setFont(*RESOURCE_MGR.GetFont("fonts/KOMIKAP_.ttf"));
	text->text.setFillColor(sf::Color::White);
	text->SetPosition(sf::Vector2f(FRAMEWORK.GetWindowSize() * 0.5f));
	text->text.setString("GAME OVER");
	text->text.setCharacterSize(75);
	text->SetOrigin(Origins::MC);
	text->SetActive(false);
}

void FlappyBird::Exit()
{
	Scene::Exit();
}

void FlappyBird::Update(float dt)
{
	auto bird = (Bird*)FindGo("Bird");
	//for (size_t i = 0; i < 3; i++)
	//{
	//	auto pillar = (Pillar*)FindGo("Pillar" + std::to_string(i));
	//}
	Scene::Update(dt);

	for (size_t i = 0; i < 4; i++)
	{
		std::string s = "Pillar" + std::to_string(i);
		auto pillar = (Pillar*)FindGo(s);
		if (bird->bird.getGlobalBounds().intersects(pillar->pillar.getGlobalBounds()))
		{
			bird->isLive = false;
		}
	}

	if (!bird->isLive)
	{
		auto text = (TextGo*)FindGo("DieLog");
		text->SetActive(true);
	}
}

void FlappyBird::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
