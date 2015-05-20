//
// Texture.h
//

// @Author ka-s

#pragma once

#include "pch.h"

class texture
{
private:
    // テクスチャ
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
    // スプライトバッチ
    std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;

    // Direct3Dのオブジェクト
    Microsoft::WRL::ComPtr<ID3D11Device>            d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     d3dContext;

public:
    // コンストラクタ
    //   画像読み込み
    texture(std::wstring pass);

    // 描画メソッド
    void render(DirectX::SimpleMath::Vector2 pos);
};
