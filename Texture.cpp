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
//   画像読み込み
texture::texture(std::wstring pass)
{
    // SpriteBatchリセット
    m_spriteBatch.reset(new SpriteBatch(d3dContext.Get()));
    // リソース変数作成
    ComPtr<ID3D11Resource> resource;

    // テクスチャ読み込み
    DX::ThrowIfFailed(
        CreateWICTextureFromFile(d3dDevice.Get(), pass, resource.GetAddressOf(),
        m_texture.ReleaseAndGetAddressOf()));
}

// 描画メソッド
void texture::render(DirectX::SimpleMath::Vector2 pos)
{
    // SpriteBatch描画開始
    m_spriteBatch->Begin();

    // 猫描画
    m_spriteBatch->Draw(m_texture.Get(), pos, nullptr, Colors::White);

    // SpriteBatch描画終了
    m_spriteBatch->End();
}
