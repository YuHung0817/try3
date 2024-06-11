#include <allegro5/base.h>
#include <cmath>
#include <string>
#include <iostream>

#include "Engine/AudioHelper.hpp"
#include "Bullet/Bullet6.hpp"
#include "Bullet/Bullet7.hpp"
#include "Bullet/Bullet8.hpp"
#include "Bullet/Bullet10.hpp"
#include "Engine/Group.hpp"
#include "Turret6.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"
//how much
const int Turret6::Price = 3500;
Turret6::Turret6(float x, float y) :
        Turret("play/tower-base.png", "play/turret-6.png", x, y, 300, Price, 0.5) {
    // Move center downward, since we the turret head is slightly biased upward.
    //Anchor.y += 8.0f / GetBitmapHeight();
}


void Turret6::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new Bullet6(Position + normalized * 36, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new Bullet7(Position + normalized * 36, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new Bullet8(Position + normalized * 36, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new Bullet10(Position + normalized * 36, diff, rotation, this));

    AudioHelper::PlayAudio("gun.wav");
}
