/*#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更,初期化,裏画面設定

	int x, y, Mouse, Wheel, Image;
	double size = 1.0;

	Image = LoadGraph("Character.jpg");//画像ロード

	// while( 裏画面を表画面に反映, メッセージ処理, 画面クリア )
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()){
		Mouse = GetMouseInput();                //マウスの入力状態取得
		Wheel = GetMouseWheelRotVol();  //ホイールの回転量取得
		GetMousePoint(&x, &y);                //マウスの座標取得
		if (Mouse & MOUSE_INPUT_LEFT){ //マウスの左ボタンが押されていたら
			DrawString(0, 0, "左ボタンが押されています", GetColor(255, 255, 255));
		}
		if (Wheel > 0){        //ホイールが+方向に回転していたら
			size += 0.1;
		}
		if (Wheel < 0){        //ホイールが－方向に回転していたら
			size -= 0.1;
		}
		DrawRotaGraph(x, y, size, 0.0, Image, TRUE);  //画像をx,yの位置にサイズsizeで描画
	}

	DxLib_End();
	return 0;
}*/