#include <allegro5/color.h>

#include "Engine/GameEngine.hpp"
#include "Engine/IScene.hpp"
#include "Scene/PlayScene.hpp"
#include "ResurrectButton.hpp"

PlayScene* ResurrectButton::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}
ResurrectButton::ResurrectButton(std::string img, std::string imgIn, Engine::Sprite Base, Engine::Sprite Turret, float x, float y, int money) :
        ImageButton(img, imgIn, x, y), money(money), Base(Base), Turret(Turret) {
}
void ResurrectButton::Update(float deltaTime) {
    ImageButton::Update(deltaTime);
    if (getPlayScene()->GetMoney() >= money && getPlayScene()->GetLives()<=3) {
        Enabled = true;
        Base.Tint = Turret.Tint = al_map_rgba(255, 255, 255, 255);
    } else {
        Enabled = false;
        Base.Tint = Turret.Tint = al_map_rgba(0, 0, 0, 160);
    }
}
void ResurrectButton::Draw() const {
    ImageButton::Draw();
    Base.Draw();
    Turret.Draw();
}
