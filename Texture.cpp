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
//   �摜�ǂݍ���
texture::texture(std::wstring pass)
{
    // SpriteBatch���Z�b�g
    m_spriteBatch.reset(new SpriteBatch(d3dContext.Get()));
    // ���\�[�X�ϐ��쐬
    ComPtr<ID3D11Resource> resource;

    // �e�N�X�`���ǂݍ���
    DX::ThrowIfFailed(
        CreateWICTextureFromFile(d3dDevice.Get(), pass, resource.GetAddressOf(),
        m_texture.ReleaseAndGetAddressOf()));
}

// �`�惁�\�b�h
void texture::render(DirectX::SimpleMath::Vector2 pos)
{
    // SpriteBatch�`��J�n
    m_spriteBatch->Begin();

    // �L�`��
    m_spriteBatch->Draw(m_texture.Get(), pos, nullptr, Colors::White);

    // SpriteBatch�`��I��
    m_spriteBatch->End();
}
