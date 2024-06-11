#ifndef RESURRECTBUTTON_HPP
#define RESURRECTBUTTON_HPP
#include <string>

#include "UI/Component/ImageButton.hpp"
#include "Engine/Sprite.hpp"

class PlayScene;

class ResurrectButton : public Engine::ImageButton {
protected:
    PlayScene* getPlayScene();
public:
    int money;
    Engine::Sprite Base;
    Engine::Sprite Turret;
    ResurrectButton(std::string img, std::string imgIn, Engine::Sprite Base, Engine::Sprite Tool, float x, float y, int money);
    void Update(float deltaTime) override;
    void Draw() const override;
};
#endif // RESURRECTBUTTON_HPP
