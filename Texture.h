//
// Texture.h
//

// @Author ka-s

#pragma once

#include "pch.h"

class texture : public render_manager
{
private:

public:
    // �R���X�g���N�^
    //   �e�N�X�`���p�X��n��
    texture(wchar_t* pass);

    // �`�惁�\�b�h
    void render();
};
