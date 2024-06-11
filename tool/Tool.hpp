#ifndef TOOL_HPP
#define TOOL_HPP
#include <allegro5/base.h>
#include <list>
#include <string>

#include "Engine/Sprite.hpp"

class Enemy;
class PlayScene;

class Tool: public Engine::Sprite {
protected:
    int price;
    float coolDown;
    float reload = 0;
    float rotateRadian = 2 * ALLEGRO_PI;
    Sprite imgBase;
    //std::list<Turret*>::iterator lockedTurretIterator;
    PlayScene* getPlayScene();
    // Reference: Design Patterns - Factory Method.
    //virtual void CreateBullet() = 0;

public:
    bool Enabled = true;
    bool Preview = false;
    //Enemy* Target = nullptr;
    Tool(std::string imgBase, std::string imgTool, float x, float y, float radius, int price, float coolDown);
    //void Update(float deltaTime) override;
    void Draw() const override;
    int GetPrice() const;
};
#endif // TOOL_HPP
