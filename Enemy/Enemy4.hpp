#ifndef ENEMY4_HPP
#define ENEMY4_HPP

#include "Enemy.hpp"

class Enemy4 : public Enemy {
private:
    float invisibleTime;  // 记录不可见时间的计时器
    bool isVisible;       // 记录当前可见状态
public:
    Enemy4(int x, int y);
    void Update(float deltaTime) override;
};

#endif // ENEMY4_HPP
