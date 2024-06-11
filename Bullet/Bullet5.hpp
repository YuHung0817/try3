#ifndef BULLET5_HPP
#define BULLET5_HPP
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class Bullet5 : public Bullet {
public:
    explicit Bullet5(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;

};
#endif // BULLET5_HPP
