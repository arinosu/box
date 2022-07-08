 #include "CameraController.h"
#include "Camera.h"
#include "Input/Input.h"

//更新処理
void CameraController::Update(float elapsedTime)
{
    GamePad& gamePad = Input::Instance().GetGamePad();

    //X軸のカメラ回転を制御
    if (angle.x > maxAngle)angle.x = maxAngle;
    if (angle.x < minAngle)angle.x = minAngle;

    //Y軸のカメラ回転を制御
    if (angle.y > maxAngle)angle.y = maxAngle;
    if (angle.y < minAngle)angle.y = minAngle;

    //カメラ回転値を回転行列に変換
    DirectX::XMMATRIX Transform = DirectX::XMMatrixRotationRollPitchYaw(angle.x, angle.y, angle.z);

    //回転行列から前方向ベクトルを取り出す
    DirectX::XMVECTOR Front = Transform.r[2];
    DirectX::XMFLOAT3 front;
    DirectX::XMStoreFloat3(&front, Front);

    //注視点から後ろベクトル方向に一定距離離れたカメラ視点を求める
    DirectX::XMFLOAT3 eye;
    eye.x = target.x - front.x * range;
    eye.y = target.y - front.y * range;
    eye.z = target.z - front.z * range;

    // ここでカメラの上下切り替えをする
    if (gamePad.GetButtonDown() & GamePad::BTN_A) CameraChange = !CameraChange;

    // 反転(上)
    if (CameraChange)
    {
        //カメラの視点と注視点を設定
        eye.y -= 4;
        eye.x += 5;
        target.y -= 4;
        float roll = rollSpeed * elapsedTime;

        angle.y += roll;
        angle.x += roll;

        Camera::Instance().SetLookAt(eye, target, DirectX::XMFLOAT3(angle.y, -angle.x, 0));
    }
    // 反転(下)
    else if (!CameraChange)
    {
        //カメラの視点と注視点を設定
        float roll = rollSpeed * elapsedTime;

        angle.y += roll;
        angle.x -= roll;

        Camera::Instance().SetLookAt(eye, target, DirectX::XMFLOAT3(angle.y, angle.x, 0));
    }
}