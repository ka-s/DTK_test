//
// Texture.h
//

// @Author ka-s

#pragma once

#include "pch.h"

class texture : public render_manager
{
private:

public:
    // コンストラクタ
    //   テクスチャパスを渡す
    texture(wchar_t* pass);

    // 描画メソッド
    void render();
};
