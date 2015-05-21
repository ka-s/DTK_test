//
// Texture.h
//

// @Author ka-s

#pragma once

#include "pch.h"

class texture
{
private:

public:
    // コンストラクタ
    //   テクスチャパスを渡す
    texture(std::wstring pass);

    // 描画メソッド
    void render();
};