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

    // �X�e�[�^�X
    std::unique_ptr<DirectX::CommonStates> m_states;

protected:
    // �e�N�X�`��
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;

    // �X�v���C�g�o�b�`
    std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;

    // Direct3D�̃I�u�W�F�N�g
    Microsoft::WRL::ComPtr<ID3D11Device>            d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     d3dContext;

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
