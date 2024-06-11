#ifndef INC_2024_I2P2_TOWERDEFENSE_WITH_ANSWER_ScoredboardSCENE_H
#define INC_2024_I2P2_TOWERDEFENSE_WITH_ANSWER_ScoredboardSCENE_H

#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"
#include <fstream>
#include <map>

#include "SettingsScene.hpp"

class ScoredboardScene final : public Engine::IScene {
private:
    std::ifstream fin;
    std::string filename;
    int page;
    int Do;
    int stop;
    std::vector<std::tuple<std::string,int,std::string,std::string,std::string,std::string,std::string>> Register;
public:
    explicit ScoredboardScene() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick(int stage);
    void PrevpageOnClick(int stage);
    void NextpageOnClick(int stage);
};
#endif //INC_2024_I2P2_TOWERDEFENSE_WITH_ANSWER_ScoredboardSCENE_H
