//
// Texture.h
//

// @Author ka-s

#pragma once

#include "pch.h"

class texture
{
private:
    // �e�N�X�`��
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;
    // �X�v���C�g�o�b�`
    std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;

    // Direct3D�̃I�u�W�F�N�g
    Microsoft::WRL::ComPtr<ID3D11Device>            d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     d3dContext;

public:
    // �R���X�g���N�^
    //   �摜�ǂݍ���
    texture(std::wstring pass);

    // �`�惁�\�b�h
    void render(DirectX::SimpleMath::Vector2 pos);
};
