#include "Enemy4.hpp"

// 构造函数初始化
Enemy4::Enemy4(int x, int y) : Enemy("play/enemy-4.png", x, y, 10, 50, 20, 20) {
    invisibleTime = 0.0f;  // 初始化不可见时间
    isVisible = true;      // 初始化为可见
}

// 更新函数
void Enemy4::Update(float deltaTime) {
    // 更新不可见时间
    invisibleTime += deltaTime;

    // 每两秒切换可见状态
    if (invisibleTime >= 2.0f) {
        invisibleTime = 0.0f;  // 重置计时器
        isVisible = !isVisible;  // 切换可见状态
    }

    // 根据可见状态设置透明度
    if (isVisible) {
        SetAlpha(255);  // 完全可见
    } else {
        SetAlpha(0);  // 完全透明
    }

    // 调用父类的更新函数
    Enemy::Update(deltaTime);
}
