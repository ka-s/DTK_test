// 
// Texture.cpp
// 

// @Author ka-s

#include "pch.h"
#include "Texture.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

// コンストラクタ
//   テクスチャパスを渡す
texture::texture(wchar_t* pass)
{
    // SpriteBatchリセット
    m_spriteBatch.reset(new SpriteBatch(d3dContext.Get()));
    // リソース変数作成
    ComPtr<ID3D11Resource> resource;

    // 猫テクスチャ読み込み
    DX::ThrowIfFailed(
        CreateWICTextureFromFile(d3dDevice.Get(), pass, resource.GetAddressOf(),
        m_texture.ReleaseAndGetAddressOf()));
}

// 描画メソッド
void texture::render()
{
    // 猫描画
    m_spriteBatch->Draw(m_texture.Get(), Vector2(0.f, 0.f), nullptr, Colors::White, 0.f);
}
