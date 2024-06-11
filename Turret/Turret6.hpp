#ifndef TURRET6_HPP
#define TURRET6_HPP
#include "Turret.hpp"

class Turret6: public Turret {
public:
    static const int Price;
    Turret6(float x, float y);
    void CreateBullet() override;
};
#endif // TURRET6_HPP
