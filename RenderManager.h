//
// RenderManager.h
//

// @Author ka-s

#pragma once

#include "pch.h"

class render_manager
{
private:
    // ���W
    DirectX::SimpleMath::Vector2 m_screenPos;

    // �X�v���C�g�o�b�`
    std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
    // �X�e�[�^�X
    std::unique_ptr<DirectX::CommonStates> m_states;
    // Font
    std::unique_ptr<DirectX::SpriteFont> m_font;

    // �e�N�X�`��
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> t_cat;

    // Direct3D�̃I�u�W�F�N�g
    Microsoft::WRL::ComPtr<ID3D11Device>            d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     d3dContext;

    // 3DObject
    DirectX::SimpleMath::Matrix m_world;
    DirectX::SimpleMath::Matrix m_view;
    DirectX::SimpleMath::Matrix m_proj;
    std::unique_ptr<DirectX::GeometricPrimitive> m_shape;

public:
    // �`��
    void render();
    // �f�o�C�X�쐬
    void create_device();
    // ���\�[�X�쐬
    void create_resource();
    // �f�o�C�X���X�g��
    void on_device_lost();

    // Direct3D�̃I�u�W�F�N�g�X�V
    void update_d3d(
        Microsoft::WRL::ComPtr<ID3D11Device> device,
        Microsoft::WRL::ComPtr<ID3D11DeviceContext> context);
};
