#include <allegro5/base.h>
#include <random>
#include <string>

#include "UI/Animation/DirtyEffect.hpp"
#include "Enemy/Enemy.hpp"
#include "Engine/Group.hpp"
#include "Bullet9.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"
//Bullet9
class Turret;

Bullet9::Bullet9(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
        Bullet("play/bullet-9.png", 1000, 1000, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
}
void Bullet9::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 10);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-2.png", dist(rng), enemy->Position.x, enemy->Position.y));
}
