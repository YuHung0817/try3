#include <allegro5/allegro.h>
#include <algorithm>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <functional>
#include <string>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <fstream>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/TextInput.hpp"
#include "PlayScene.hpp"
#include "Engine/Point.hpp"
#include "WinScene.hpp"
#include "UI/Component/TextInput.hpp"



void WinScene::Initialize() {
	ticks = 0;
	int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
	int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
	int halfW = w / 2;
	int halfH = h / 2;
	AddNewObject(new Engine::Image("win/benjamin-sad.png", halfW, halfH, 0, 0, 0.5, 0.5));
	AddNewObject(new Engine::Label("You Win!", "pirulen.ttf", 48, halfW, halfH / 4 -10, 255, 255, 255, 255, 0.5, 0.5));
	Engine::ImageButton* btn;
	btn = new Engine::ImageButton("win/dirt.png", "win/floor.png", halfW - 200, halfH * 7 / 4 - 50, 400, 100);
	btn->SetOnClickCallback(std::bind(&WinScene::BackOnClick, this, 2));
	AddNewControlObject(btn);
	AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 7 / 4, 0, 0, 0, 255, 0.5, 0.5));

    inputButton = new Engine::ImageButton("win/dirt.png", "win/floor.png", halfW - 100-200+30, halfH-300+30, 270, 50);
    inputButton->SetOnClickCallback(std::bind(&WinScene::OnInputButtonClick, this));
    AddNewControlObject(inputButton);
    AddNewObject(new Engine::Label("Enter Name", "pirulen.ttf", 24, halfW-200+30+30, halfH + 25-300+30, 0, 0, 0, 255, 0.5, 0.5));


    textInput = new Engine::TextInput("pirulen.ttf", 32, halfW+100+30+30, halfH-300+25+30, 300, 50, 0, 0, 0, 255, 255, 255, 255, 255, 0.5, 0.5);
    inputActive = false;

    bgmId = AudioHelper::PlayAudio("win.wav");
}
void WinScene::Terminate() {
	IScene::Terminate();
	AudioHelper::StopBGM(bgmId);
}
void WinScene::Update(float deltaTime) {
	ticks += deltaTime;
	if (ticks > 4 && ticks < 100 &&
		dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetScene("play"))->MapId == 2) {
		ticks = 100;
		bgmId = AudioHelper::PlayBGM("happy.ogg");
	}

    IScene::Update(deltaTime);
}
void WinScene::BackOnClick(int stage) {
    //to store the text to the scorefile

    WriteStringToFile();
	Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
void WinScene::WriteStringToFile() {
    // 開啟文件，模式為輸出（寫入），如果文件不存在則創建
    std::ofstream fin;
    std::string filename = std::string("Resource/scoreboard") + ".txt";
    fin.open(filename, std::ios::out | std::ios::app);

    if (!fin.is_open()) {
        std::cerr << "Failed to open or create the file: " << filename << std::endl;
        return;
    }
    //name
    std::string name=textInput->getText();
    if(name=="") name="GUEST\0";
    //score
    int score=Engine::GameEngine::getScore();
    std::string Score=std::to_string(score);
    //datetime
    // 獲取當前日期時間
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::string currentDateTime = std::ctime(&now_time);
    std::cout<<currentDateTime<<std::endl;

    //Fri May 24 20:56:28 2024

    fin << name <<" "<< Score <<" "<<currentDateTime;
    fin.flush();
    fin.close();
}
// 處理按鈕點擊事件，顯示 TextInput
void WinScene::OnInputButtonClick() {
    textInput->SetFocus(1);
    inputActive = true;
   AddNewObject(textInput);
}

// 處理鍵盤事件

void WinScene::OnKeyDown(int keycode) {
    if (inputActive && textInput) {
        if(keycode==ALLEGRO_KEY_ENTER){
            textInput->SetFocus(0);
            textInput->Text+='\0';
            inputActive=false;
        }
        else textInput->OnKeyDown(keycode);
    }
}

