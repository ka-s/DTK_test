// 
// RenderManager.cpp
// 

// @Author ka-s

#include "pch.h"
#include "RenderManager.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

render_manager::render_manager(
    Microsoft::WRL::ComPtr<ID3D11Device> device,
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> context)
{
    d3dDevice = device;
    d3dContext = context;
}

// 描画
void render_manager::render()
{
    // SpriteBatch描画開始
    m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());

    // 猫描画
    m_spriteBatch->Draw(m_texture.Get(), m_screenPos, nullptr, Colors::White, 0.f, m_origin);

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

    // 猫テクスチャ作成
    ComPtr<ID3D11Texture2D> cat;
    // 例外処理
    DX::ThrowIfFailed(resource.As(&cat));

    // 猫Desc作成
    CD3D11_TEXTURE2D_DESC catDesc;
    // 猫Desc取得
    cat->GetDesc(&catDesc);

    // originベクトル設定
    m_origin.x = float(catDesc.Width / 2);
    m_origin.y = float(catDesc.Height / 2);

    // Statesリセット
    m_states.reset(new CommonStates(d3dDevice.Get()));
}

// リソース作成
void render_manager::create_resource()
{
    // screenPos設定
    m_screenPos.x = 640 / 2.f;
    m_screenPos.y = 480 / 2.f;
}

// デバイスロスト時
void render_manager::on_device_lost()
{
    // テクスチャリセット
    m_texture.Reset();
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
