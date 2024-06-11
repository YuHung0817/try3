#include "ScoredboardScene.hpp"
#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Slider.hpp"
#include "Scene/ScoredboardScene.hpp"
#include "Scene/SettingsScene.hpp"



bool compareByScore(const std::tuple<std::string, int, std::string,std::string,std::string,std::string,std::string>& a, const std::tuple<std::string, int, std::string,std::string,std::string,std::string,std::string>& b) {
    return std::get<1>(a) > std::get<1>(b);
}

void ScoredboardScene::Initialize() {
    //std::cout<<"page: ";
   // std::cout<<page<<std::endl<<std::endl;
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;


    AddNewObject(new Engine::Label("SCOREBOARD", "pirulen.ttf", 60, halfW, halfH/3-100, 0, 255, 0, 255, 0.5, 0.5));
    //initial
    if(!Do) {
        //std::cout<<"here\n\n";
        filename = std::string("Resource/scoreboard") + ".txt";
        std::string name;
        std::string D1,D2,D3,D4,D5;
        //Fri May 24 20:56:28 2024
        int score;
        fin.open(filename);
        while (fin >> name && fin >> score && fin>>D1 && fin>>D2 && fin>>D3 && fin>>D4 && fin>>D5) {
            Register.push_back({name, score,D1,D2,D3,D4,D5});
        }

        std::sort(Register.begin(), Register.end(), compareByScore);
    }

    int top=halfH/3-50;

    for(int i=0;i<10;i++) {
        if(10*page+i>Register.size()-1) {
            stop=1;
            break;
        }
        top+=55;
        std::string name = std::get<0>(Register[10 * page + i]);
        std::string score = std::to_string(std::get<1>(Register[10 * page + i]));
        std::string d1 = std::get<2>(Register[10 * page + i]);
        std::string d2 = std::get<3>(Register[10 * page + i]);
        std::string d3 = std::get<4>(Register[10 * page + i]);
        std::string d4 = std::get<5>(Register[10 * page + i]);
        std::string d5 = std::get<6>(Register[10 * page + i]);
        //std::string sc=std::to_string(Register[10*page+i].second);
        AddNewObject(new Engine::Label(name, "pirulen.ttf", 36, halfW/2-100+50, top, 0, 255, 0, 170, 0.5, 0.5));
        AddNewObject(new Engine::Label(score, "pirulen.ttf", 36, halfW, top, 0, 255, 0, 170, 0.5, 0.5));
        AddNewObject(new Engine::Label(d1, "pirulen.ttf", 24, halfW*3/2-150, top, 0, 255, 0, 170, 0.5, 0.5));
        AddNewObject(new Engine::Label(d2, "pirulen.ttf", 24, halfW*3/2-150+100, top, 0, 255, 0, 170, 0.5, 0.5));
        AddNewObject(new Engine::Label(d3, "pirulen.ttf", 24, halfW*3/2-150+200-30, top, 0, 255, 0, 170, 0.5, 0.5));
        AddNewObject(new Engine::Label(d4, "pirulen.ttf", 24, halfW*3/2-150+300, top, 0, 255, 0, 170, 0.5, 0.5));
        AddNewObject(new Engine::Label(d5, "pirulen.ttf", 24, halfW*3/2-150+450, top, 0, 255, 0, 170, 0.5, 0.5));
    }


    fin.close();

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 3 / 2 +70, 400, 100);
    btn->SetOnClickCallback(std::bind(&ScoredboardScene::BackOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("BACK", "pirulen.ttf", 48, halfW, halfH * 3/2 +120 , 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW /2-300, halfH * 3 / 2 +70, 400, 100);
    btn->SetOnClickCallback(std::bind(&ScoredboardScene::PrevpageOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("PREVPAGE", "pirulen.ttf", 48, halfW/2-100, halfH * 3/2 +120 , 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW*3/2-100, halfH * 3 / 2 +70, 400, 100);
    btn->SetOnClickCallback(std::bind(&ScoredboardScene::NextpageOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("NEXTPAGE", "pirulen.ttf", 48, halfW*3/2+100, halfH * 3/2 +120 , 0, 0, 0, 255, 0.5, 0.5));
}
void ScoredboardScene::Terminate() {
    IScene::Terminate();
}

void ScoredboardScene::BackOnClick(int stage) {
    Register.clear();
    page=0;
    Do=0;
    stop=0;
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
void ScoredboardScene::PrevpageOnClick(int stage){
    //std::cout<<"page: "<<page<<std::endl;
    stop=0;
    if(page>0) page--;
    Do=1;
    Engine::GameEngine::GetInstance().ChangeScene("scoreboard-scene");
}
void ScoredboardScene::NextpageOnClick(int stage) {
    if(!stop) page++;
    Do=1;
    Engine::GameEngine::GetInstance().ChangeScene("scoreboard-scene");
}
