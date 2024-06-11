#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <memory>
#include <iostream>

#include "TextInput.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"

namespace Engine {
    TextInput::TextInput(const std::string& font, int fontSize, float x, float y, float width, float height,
                         unsigned char r, unsigned char g, unsigned char b, unsigned char a,
                         unsigned char bgR, unsigned char bgG, unsigned char bgB, unsigned char bgA,
                         float anchorX, float anchorY) :
            IObject(x, y, width, height, anchorX, anchorY),
            font(Resources::GetInstance().GetFont(font, fontSize)),
            focused(false),
            Text(""),
            Color(al_map_rgba(r, g, b, a)),
            BackgroundColor(al_map_rgba(bgR, bgG, bgB, bgA)) {
        //std::cout<<"constructor\n";
    }

    void TextInput::Draw() const {

        al_draw_filled_rectangle(Position.x - Anchor.x * Size.x, Position.y - Anchor.y * Size.y,
                                 Position.x + (1 - Anchor.x) * Size.x, Position.y + (1 - Anchor.y) * Size.y,
                                 BackgroundColor);
        al_draw_text(font.get(), Color, Position.x - Anchor.x * Size.x + 5, Position.y - Anchor.y * Size.y + (Size.y - al_get_font_line_height(font.get())) / 2, 0, Text.c_str());
        if (focused) {
            int textWidth = al_get_text_width(font.get(), Text.c_str());
            al_draw_line(Position.x - Anchor.x * Size.x + 5 + textWidth, Position.y - Anchor.y * Size.y + (Size.y - al_get_font_line_height(font.get())) / 2,
                         Position.x - Anchor.x * Size.x + 5 + textWidth, Position.y - Anchor.y * Size.y + (Size.y + al_get_font_line_height(font.get())) / 2,
                         Color, 1.0);
        }
    }

    void TextInput::OnTextInput(const char* input) {
        if(focused) Text += input;
    }

    void TextInput::OnKeyDown(int keycode) {
        std::cout<<Text<<std::endl;
        if(focused){
            if (keycode == ALLEGRO_KEY_BACKSPACE) {
                 if(!Text.empty()) Text.pop_back();
            }else /*if(keycode== ALLEGRO_EVENT_KEY_CHAR)*/{
                const char* input = al_keycode_to_name(keycode);
                if (input != nullptr) {
                    OnTextInput(input);
                }
            }
        }

    }

    void TextInput::SetFocus(bool focus) {
        focused = focus;
    }
    std::string TextInput::getText(){

        return Text;

    }
}
