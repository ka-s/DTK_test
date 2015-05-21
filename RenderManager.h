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

    // ステータス
    std::unique_ptr<DirectX::CommonStates> m_states;

protected:
    // テクスチャ
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;

    // スプライトバッチ
    std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;

    // Direct3Dのオブジェクト
    Microsoft::WRL::ComPtr<ID3D11Device>            d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     d3dContext;

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
