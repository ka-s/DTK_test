//
// RenderManager.h
//

// @Author ka-s

#pragma once

#include "pch.h"

class render_manager
{
private:
    // 座標
    DirectX::SimpleMath::Vector2 m_screenPos;

    // スプライトバッチ
    std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
    // ステータス
    std::unique_ptr<DirectX::CommonStates> m_states;
    // Font
    std::unique_ptr<DirectX::SpriteFont> m_font;

    // テクスチャ
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> t_cat;

    // Direct3Dのオブジェクト
    Microsoft::WRL::ComPtr<ID3D11Device>            d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     d3dContext;

    // 3DObject
    DirectX::SimpleMath::Matrix m_world;
    DirectX::SimpleMath::Matrix m_floor;
    DirectX::SimpleMath::Matrix m_view;
    DirectX::SimpleMath::Matrix m_proj;
    std::unique_ptr<DirectX::GeometricPrimitive> m_shape;

    // model
    std::unique_ptr<DirectX::IEffectFactory> m_fxFactory;
    std::unique_ptr<DirectX::Model> m_model;

    // light
    std::unique_ptr<DirectX::BasicEffect> m_effect;
    Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;

public:
    // 描画
    void render();
    // デバイス作成
    void create_device();
    // リソース作成
    void create_resource();
    // デバイスロスト時
    void on_device_lost();

    // Direct3Dのオブジェクト更新
    void update_d3d(
        Microsoft::WRL::ComPtr<ID3D11Device> device,
        Microsoft::WRL::ComPtr<ID3D11DeviceContext> context);
};
