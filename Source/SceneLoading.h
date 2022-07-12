#pragma once

#include "Graphics/Sprite.h"
#include "Scene.h"
#include "Graphics/Shader.h"
#include "Graphics/Model.h"
#include <thread>

//���[�f�B���O�V�[��
class SceneLoading :public Scene
{
public:
    SceneLoading(Scene* nextScene) :nextScene(nextScene) {}
    ~SceneLoading()override {}

    //������
    void Initialize()override;

    //�I����
    void Finalize()override;

    //�X�V����
    void Update(float elapsedTime)override;

    //�`�揈��
    void Render()override;

private:
    //���[�f�B���O�X���b�h
    static void LoadingThread(SceneLoading* scene);

    //�`�揈��
    void RENDER(ID3D11DeviceContext* dc, Shader* shader);

    //�s��X�V����
    void UpdateTransform();

    DirectX::XMFLOAT3 position = { 0,0,0 };  //�ʒu
    DirectX::XMFLOAT3 angl = { 0,0,0 };     //��]
    DirectX::XMFLOAT3 scale = { 1,1,1 };     //�X�P�[��
    DirectX::XMFLOAT4X4 transform = {
        1,0,0,0,
        0,1,0,0,
        0,0,1,0,
        0,0,0,1
    };               //��L��XMFLOAT3���g���s����`����

private:
    Sprite* sprite = nullptr;
    float angle = 0.0f;
    Scene* nextScene = nullptr;
    std::thread* thread = nullptr;
    Model* model = nullptr;
};
