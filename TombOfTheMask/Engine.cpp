#include "Engine.h"
#include "InputSubsystem.h"
#include "ResourceSubsystem.h"
#include "RenderSubsystem.h"
#include "LevelSubsystem.h"
#include "PhysicsSubsystem.h"

Engine::Engine(sf::RenderWindow& window)
{
	GWindow = &window;
	GInputSubsystem = new InputSubsystem();
	GResourceSubsystem = new ResourceSubsystem();
	GRenderSubsystem = new RenderSubsystem();
	GLevelSubsystem = new LevelSubsystem();
	GPhysicsSubsystem = new PhysicsSubsystem();
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

	GPhysicsSubsystem->Update();

	GRenderSubsystem->Update();

}
