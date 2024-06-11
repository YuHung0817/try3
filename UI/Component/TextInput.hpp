#ifndef TEXTINPUT_HPP
#define TEXTINPUT_HPP

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <memory>
#include <string>
#include "Engine/IObject.hpp"

namespace Engine {
    class TextInput : public IObject {
    protected:
        std::shared_ptr<ALLEGRO_FONT> font;
        bool focused;
    public:
        std::string Text;
        ALLEGRO_COLOR Color;
        ALLEGRO_COLOR BackgroundColor;
        int score;

        explicit TextInput(const std::string& font, int fontSize, float x, float y, float width, float height,
                           unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255,
                           unsigned char bgR = 255, unsigned char bgG = 255, unsigned char bgB = 255, unsigned char bgA = 255,
                           float anchorX = 0, float anchorY = 0);

        void Draw() const override;
        void OnTextInput(const char* input);
        void OnKeyDown(int keycode);
        void SetFocus(bool focus);
        std::string getText();
    };
}

#endif // TEXTINPUT_HPP
