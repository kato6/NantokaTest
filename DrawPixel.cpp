/*#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	int image[16];
	LoadDivGraph("c1.png", 28, 7, 4, 128, 128, image); // 画像の分割読み込み

	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0){

		DrawGraph(100, 100, image[9], TRUE);      // 画像を表示

	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}*/