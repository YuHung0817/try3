#ifndef WINSCENE_HPP
#define WINSCENE_HPP
#include <allegro5/allegro_audio.h>
#include "Engine/IScene.hpp"
#include "UI/Component/TextInput.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"

class WinScene final : public Engine::IScene {
private:
	float ticks;
	ALLEGRO_SAMPLE_ID bgmId;
    //std::unique_ptr<Engine::TextInput> textInput;  // 新增 TextInput 成員
    Engine::TextInput* textInput;
    Engine::ImageButton* inputButton;  // 新增按鈕成員
    bool inputActive;  // 控制 TextInput 顯示與否
public:
	explicit WinScene() = default;
	void Initialize() override;
	void Terminate() override;
	void Update(float deltaTime) override;
	void BackOnClick(int stage);
    void OnKeyDown(int keycode) override;  // 新增鍵盤事件處理函數
    //void OnTextInput(const char* text);  // 新增文字輸入事件處理函數
    void OnInputButtonClick();  // 按鈕點擊事件處理函數
    void WriteStringToFile();
};

#endif // WINSCENE_HPP
