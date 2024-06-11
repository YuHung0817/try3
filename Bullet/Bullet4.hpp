#ifndef BULLET4_HPP
#define BULLET4_HPP
#include <allegro5/base.h>
#include <list>

#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class Bullet4 : public Bullet {
protected:
    const float rotateRadian = 2 * ALLEGRO_PI;
    std::list<Bullet*>::iterator lockedBulletIterator;
    float timeSinceLastCircle;
    bool circling;
public:
    explicit Bullet4(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void Update(float deltaTime) override;
    void OnExplode(Enemy* enemy) override;
};
#endif // BULLET4_HPP
