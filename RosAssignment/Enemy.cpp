#include "Enemy.h"
#include "ResorceHandles.h"

Enemy::Enemy(VECTOR direction, VECTOR translation, ENEMY_TYPE enemyType)
:Object(direction,translation)
{
	_enemyType = enemyType;
	_count = 0;
	_defeated = false;
}

void Enemy::Update(char input[])
{
	++_count;
}

void Enemy::Draw()
{
	MV1SetScale(ResourceHandles::getResourceHandles().EnemyHandle, VGet(2.5, 2.5, 2.5));
	MV1SetRotationXYZ(ResourceHandles::getResourceHandles().EnemyHandle, VGet(0, _count * DX_PI / 180.0f, 0));
	MV1SetPosition(ResourceHandles::getResourceHandles().EnemyHandle, _translation);
	MV1DrawModel(ResourceHandles::getResourceHandles().EnemyHandle);
}

bool Enemy::GetExpired()
{
	return _defeated;
}

void Enemy::SetDefeated(bool defeated)
{
	_defeated = defeated;
}

bool Enemy::Collide(VECTOR translation, float radius)
{
	VECTOR sub = VSub(_translation, translation);
	float dist = VDot(sub, sub);
	return dist <= (radius + 3)*(radius + 3);
}

bool Enemy_Erase(Enemy enemy)
{
	return enemy.GetExpired();
}