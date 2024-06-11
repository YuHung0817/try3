#ifndef TURRET7_HPP
#define TURRET7_HPP
#include "Turret.hpp"

class Turret7: public Turret {
public:
    static const int Price;
    Turret7(float x, float y);
    void CreateBullet() override;
};
#endif // TURRET7_HPP
