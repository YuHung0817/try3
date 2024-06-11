#include <allegro5/base.h>
#include <cmath>
#include <string>
#include <iostream>

#include "Engine/AudioHelper.hpp"
#include "Bullet/FireBullet.hpp"
#include "Engine/Group.hpp"
#include "Resurrect.hpp"
#include "Scene/PlayScene.hpp"
#include "Engine/Point.hpp"

const int Resurrect::Price = 1000;
Resurrect::Resurrect(float x, float y) :
// TODO: [CUSTOM-TOOL] You can imitate the 2 files: 'MachineGunTurret.hpp', 'MachineGunTurret.cpp' to create a new turret.
        Tool("play/tower-base.png", "play/resurrect.png", x, y, 200, Price, 0.5) {
    // Move center downward, since we the turret head is slightly biased upward.
   // Anchor.y += 8.0f / GetBitmapHeight();
}

