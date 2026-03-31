#include "Engine.h"
#include "InputSubsystem.h"
#include "ResourceSubsystem.h"
#include "RenderSubsystem.h"
#include "LevelSubsystem.h"

Engine::Engine(sf::RenderWindow& window)
{
	GWindow = &window;
	GInputSubsystem = new InputSubsystem();
	GResourceSubsystem = new ResourceSubsystem();
	GRenderSubsystem = new RenderSubsystem();
	GLevelSubsystem = new LevelSubsystem();
}

void Engine::BeginPlay()
{
	GInputSubsystem->BeginPlay();

	GLevelSubsystem->BeginPlay();

	GRenderSubsystem->BeginPlay();
}

void Engine::Update()
{

	GInputSubsystem->Update();

	GLevelSubsystem->Update();

	GRenderSubsystem->Update();

}
