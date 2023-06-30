#include "stdafx.h"
#include "SceneTitle.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "Framework.h"

SceneTitle::SceneTitle() : Scene(SceneId::Title)
{
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/Season 2 Release.png"));
	resources.push_back(std::make_tuple(ResourceTypes::Font, "fonts/KOMIKAP_.ttf"));
}

void SceneTitle::Init()
{
	Release();

	AddGo(new SpriteGo("BG"));
	AddGo(new TextGo("text"));

	for (auto go : gameObjects)
	{
		go->Init();
	}
}

void SceneTitle::Release()
{
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void SceneTitle::Enter()
{
	Scene::Enter();

	SpriteGo* findGo = (SpriteGo*)FindGo("BG");
	findGo->sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/Season 2 Release.png"));
	findGo->sprite.setPosition(0, 0);
	findGo->sprite.setScale(0.64f, 0.55f);
	findGo->SetOrigin(Origins::TL);
	findGo->sortLayer = 0;

	TextGo* textGo = (TextGo*)FindGo("text");
	textGo->text.setFont(*RESOURCE_MGR.GetFont("fonts/KOMIKAP_.ttf"));
	textGo->text.setString("Press Enter to Start Game");
	textGo->text.setFillColor(sf::Color::Red);
	textGo->text.setCharacterSize(75);
	textGo->SetOrigin(Origins::MC);
	textGo->text.setOutlineThickness(5);
	textGo->text.setOutlineColor(sf::Color::White);
	textGo->SetPosition(FRAMEWORK.GetWindowSize().x * 0.5f, FRAMEWORK.GetWindowSize().y * 0.8f);
	textGo->sortLayer = 1;
}

void SceneTitle::Exit()
{
	Scene::Exit();
}

void SceneTitle::Update(float dt)
{
	Scene::Update(dt);

	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Return))
	{
		SCENE_MGR.ChangeScene(SceneId::Flappy);
	}
}

void SceneTitle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}