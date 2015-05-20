// 
// RenderManager.cpp
// 

// @Author ka-s

#include "pch.h"
#include "RenderManager.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using Microsoft::WRL::ComPtr;

// �`��
void render_manager::render()
{
    // SpriteBatch�`��J�n
    m_spriteBatch->Begin(SpriteSortMode_Deferred, m_states->NonPremultiplied());

    // �L�`��
    m_spriteBatch->Draw(m_texture.Get(), m_screenPos, nullptr, Colors::White, 0.f);

    // SpriteBatch�`��I��
    m_spriteBatch->End();
}

void render_manager::create_device()
{
    // SpriteBatch���Z�b�g
    m_spriteBatch.reset(new SpriteBatch(d3dContext.Get()));
    // ���\�[�X�ϐ��쐬
    ComPtr<ID3D11Resource> resource;

    // �L�e�N�X�`���ǂݍ���
    DX::ThrowIfFailed(
        CreateWICTextureFromFile(d3dDevice.Get(), L"cat.png", resource.GetAddressOf(),
        m_texture.ReleaseAndGetAddressOf()));

    // States���Z�b�g
    m_states.reset(new CommonStates(d3dDevice.Get()));
}

// ���\�[�X�쐬
void render_manager::create_resource()
{
    // screenPos�ݒ�
    m_screenPos.x = 0.f;
    m_screenPos.y = 0.f;
}

// �f�o�C�X���X�g��
void render_manager::on_device_lost()
{
    // �e�N�X�`�����Z�b�g
    m_texture.Reset();
    // SpriteBatch���Z�b�g
    m_spriteBatch.reset();
    // States���Z�b�g
    m_states.reset();
}

// Direct3D�̃I�u�W�F�N�g�X�V
void render_manager::update_d3d(
    Microsoft::WRL::ComPtr<ID3D11Device> device,
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> context)
{
    d3dDevice = device;
    d3dContext = context;
}
