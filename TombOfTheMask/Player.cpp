#include "Player.h"

Player::Player(sf::Vector2f position) : Actor(ActorType::Player, position)
{
	canTick = true;

	CollisionBox = { position.x - SPRITE_GAME_SIZE / 4, position.y - SPRITE_GAME_SIZE / 4, SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE / 2 };
	
}

void Player::Update()
{

	UpdateLocation({ PlayerDirection.x * PLAYER_SPEED, PlayerDirection.y * PLAYER_SPEED });
}

void Player::OnCollision(Actor* OtherActor)
{
	UpdateLocation({ -PlayerDirection.x * PLAYER_SPEED, -PlayerDirection.y * PLAYER_SPEED });

	PlayerDirection = { 0.f, 0.f };
	CanAction = true;
}

void Player::SetDirection(MoveDirection Direction)
{
	if (CanAction)
	switch (Direction) {
		case MoveDirection::Up:
			PlayerDirection = { 0.f, -1.f };
			CanAction = false;
			ActorSprite->SetRotation(90.f);
			ActorSprite->Flip(true);
			break;
		case MoveDirection::Down:
			PlayerDirection = { 0.f, 1.f };
			CanAction = false;
			ActorSprite->SetRotation(90.f);
			ActorSprite->Flip(false);
			break;
		case MoveDirection::Left:
			PlayerDirection = { -1.f, 0.f };
			CanAction = false;
			ActorSprite->SetRotation(0.f);
			ActorSprite->Flip(true);
			break;
		case MoveDirection::Right:
			PlayerDirection = { 1.f, 0.f };
			CanAction = false;
			ActorSprite->SetRotation(0.f);
			ActorSprite->Flip(false);

			break;
		case MoveDirection::NoDirection:
			PlayerDirection = { 0.f, 0.f };
	}
}

void Player::UpdateLocation(sf::Vector2f position)
{
	ActorLocation += position;
	CollisionBox = { ActorLocation.x - SPRITE_GAME_SIZE / 4, ActorLocation.y - SPRITE_GAME_SIZE / 4, SPRITE_GAME_SIZE / 2, SPRITE_GAME_SIZE / 2 };
	ActorSprite->SetPosition(ActorLocation);
}

sf::FloatRect Player::GetCollisionBox()
{

	float TempWidth = SPRITE_GAME_SIZE / 2;
	float TempHeight = SPRITE_GAME_SIZE / 2;
	float TempLeft = ActorLocation.x - SPRITE_GAME_SIZE / 4 + (PlayerDirection.x * SPRITE_GAME_SIZE / 4);
	float TempTop = ActorLocation.y - SPRITE_GAME_SIZE / 4 + (PlayerDirection.y * SPRITE_GAME_SIZE / 4);

	return { TempLeft, TempTop, TempWidth, TempHeight };
}