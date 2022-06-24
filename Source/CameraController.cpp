#include "CameraController.h"
#include "Camera.h"
#include "Input/Input.h"

//更新処理
void CameraController::Update(float elapsedTime)
{
    GamePad& gamePad = Input::Instance().GetGamePad();
    if (gamePad.GetButton() & GamePad::BTN_A)
    {
        float ax = 0;
        float ay = gamePad.BTN_A;
        //カメラの回転速度
        float speed = rollSpeed * elapsedTime;

        //スティックの入力値に合わせてＸ軸とＹ軸を回転
        angle.x += ay * speed;

        //X軸のカメラ回転を制御
        if (angle.y > maxAngle)angle.y = maxAngle;
        if (angle.y < minAngle)angle.y = minAngle;
        
        //Y軸の回転値を-3.14~3.14に収まるようにする
        if (angle.y < -DirectX::XM_PI)
        {
            angle.y += DirectX::XM_2PI;
        }
        if (angle.y > DirectX::XM_PI)
        {
            angle.y -= DirectX::XM_2PI;
        }
    }

    //カメラ回転値を回転行列に変換
    DirectX::XMMATRIX Transform = DirectX::XMMatrixRotationRollPitchYaw(angle.x, angle.y, angle.z);

    //回転行列から前方向ベクトルを取り出す
    DirectX::XMVECTOR Front = Transform.r[2];
    DirectX::XMFLOAT3 front;
    DirectX::XMStoreFloat3(&front, Front);

    //注視点から後ろベクトル方向に一定距離離れたカメラ視点を求める
    DirectX::XMFLOAT3 eye;
    eye.x = target.x - front.x * range;
    eye.y = target.y + front.y * range;
    eye.z = target.z - front.z * range;

    //カメラの視点と注視点を設定
    Camera::Instance().SetLookAt(eye, target, DirectX::XMFLOAT3(0, 1, 0));
}