#include <allegro5/base.h>
#include <random>
#include <string>

#include "UI/Animation/DirtyEffect.hpp"
#include "Enemy/Enemy.hpp"
#include "Engine/Group.hpp"
#include "Bullet10.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"
//Bullet9
class Turret;

Bullet10::Bullet10(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
        Bullet("play/bullet-10.png", 1000, 5, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
}
void Bullet10::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 10);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-3.png", dist(rng), enemy->Position.x, enemy->Position.y));
}
