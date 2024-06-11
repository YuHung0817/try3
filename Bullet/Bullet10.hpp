#ifndef BULLET10_HPP
#define BULLET10_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class Bullet10 : public Bullet {
public:
    explicit Bullet10(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
};
#endif // BULLET10_HPP
