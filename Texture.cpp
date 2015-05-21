// 
// Texture.cpp
// 

// @Author ka-s

#include "pch.h"
#include "Texture.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

// �R���X�g���N�^
//   �e�N�X�`���p�X��n��
texture::texture(wchar_t* pass)
{
    // SpriteBatch���Z�b�g
    m_spriteBatch.reset(new SpriteBatch(d3dContext.Get()));
    // ���\�[�X�ϐ��쐬
    ComPtr<ID3D11Resource> resource;

    // �L�e�N�X�`���ǂݍ���
    DX::ThrowIfFailed(
        CreateWICTextureFromFile(d3dDevice.Get(), pass, resource.GetAddressOf(),
        m_texture.ReleaseAndGetAddressOf()));
}

// �`�惁�\�b�h
void texture::render()
{
    // �L�`��
    m_spriteBatch->Draw(m_texture.Get(), Vector2(0.f, 0.f), nullptr, Colors::White, 0.f);
}
