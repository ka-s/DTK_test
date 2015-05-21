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
    //m_spriteBatch->Draw(t_cat.Get(), Vector2(100.f, 100.f), nullptr, Colors::White, 0.f);

    // 文字描画
    m_font->DrawString(m_spriteBatch.get(), L"Hello Cats!",
        Vector2(100.f, 0.f), Colors::White);

    //m_shape->Draw(m_world, m_view, m_proj, Colors::White, t_cat.Get());

    // Model
    m_model->Draw(d3dContext.Get(), *m_states, m_world, m_view, m_proj);

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
    m_font.reset(new SpriteFont(d3dDevice.Get(), L"meiryo.spritefont"));

    // 3DObject
    m_shape = GeometricPrimitive::CreateSphere(d3dContext.Get());
    m_world = Matrix::Identity;
    m_world = Matrix::CreateWorld(Vector3(0.f, 0.f, 0.f), Vector3::Forward, Vector3::UnitY);
    // Model
    m_fxFactory.reset(new EffectFactory(d3dDevice.Get()));
    m_model = Model::CreateFromCMO(d3dDevice.Get(), L"cup.cmo", *m_fxFactory);
}

// リソース作成
void render_manager::create_resource()
{
    // screenPos設定
    m_screenPos.x = 0.f;
    m_screenPos.y = 0.f;

    // 3DObject
    m_view = Matrix::CreateLookAt(Vector3(2.f, 2.f, 2.f), Vector3::Zero, Vector3::UnitY);
    m_proj = Matrix::CreatePerspectiveFieldOfView(XM_PI / 4.f,
        800.f / 600.f, 0.1f, 10.f);
}

// デバイスロスト時
void render_manager::on_device_lost()
{
    // テクスチャリセット
    m_texture.Reset();
    t_cat.Reset();
    // 3DObject
    m_shape.reset();
    // Model
    m_fxFactory.reset();
    m_model.reset();
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
