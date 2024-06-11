#include <allegro5/base.h>
#include <cmath>
#include <string>
#include <iostream>

#include "Engine/AudioHelper.hpp"
#include "Bullet/FireBullet.hpp"
#include "Bullet/Bullet10.hpp"
#include "Bullet/Bullet9.hpp"
#include "Engine/Group.hpp"
#include "Turret7.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"
//how much
const int Turret7::Price = 1500;
Turret7::Turret7(float x, float y) :
        Turret("play/tower-base.png", "play/turret-7.png", x, y, 100, Price, 0.5) {
    // Move center downward, since we the turret head is slightly biased upward.
    //Anchor.y += 8.0f / GetBitmapHeight();
}


void Turret7::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + normalized * 36, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new Bullet9(Position + normalized * 36, diff, rotation, this));
    getPlayScene()->BulletGroup->AddNewObject(new Bullet10(Position + normalized * 36, diff, rotation, this));
    AudioHelper::PlayAudio("gun.wav");
}
