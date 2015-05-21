// 
// RenderManager.cpp
// 

// @Author ka-s

#include "pch.h"
#include "RenderManager.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

// 描画
void render_manager::render()
{
    // SpriteBatch描画開始
    m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());

    // 猫描画
    m_spriteBatch->Draw(m_texture.Get(), m_screenPos, nullptr, Colors::White, 0.f);
    m_spriteBatch->Draw(t_cat.Get(), Vector2(100.f, 100.f), nullptr, Colors::White, 0.f);

    // SpriteBatch描画終了
    m_spriteBatch->End();
}

void render_manager::create_device()
{
    // SpriteBatchリセット
    m_spriteBatch.reset(new SpriteBatch(d3dContext.Get()));
    // リソース変数作成
    ComPtr<ID3D11Resource> resource;

    // 猫テクスチャ読み込み
    DX::ThrowIfFailed(
        CreateWICTextureFromFile(d3dDevice.Get(), L"cat.png", resource.GetAddressOf(),
        m_texture.ReleaseAndGetAddressOf()));
    DX::ThrowIfFailed(
        CreateWICTextureFromFile(d3dDevice.Get(), L"cat2.png", resource.GetAddressOf(),
        t_cat.ReleaseAndGetAddressOf()));

    // Statesリセット
    m_states.reset(new CommonStates(d3dDevice.Get()));

    // フォントリセット
    m_font.reset(new SpriteFont(d3dDevice.Get(), L"myfile.spritefont"));
}

// リソース作成
void render_manager::create_resource()
{
    // screenPos設定
    m_screenPos.x = 0.f;
    m_screenPos.y = 0.f;
}

// デバイスロスト時
void render_manager::on_device_lost()
{
    // テクスチャリセット
    m_texture.Reset();
    t_cat.Reset();
    // FontReset
    m_font.reset();
    // SpriteBatchリセット
    m_spriteBatch.reset();
    // Statesリセット
    m_states.reset();
}

// Direct3Dのオブジェクト更新
void render_manager::update_d3d(
    Microsoft::WRL::ComPtr<ID3D11Device> device,
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> context)
{
    d3dDevice = device;
    d3dContext = context;
}
