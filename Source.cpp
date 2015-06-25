/*#include "DxLib.h"

int Key[256]; // キーが押されているフレーム数を格納する

// キーの入力状態を更新する
int gpUpdateKey(){
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i<256; i++){
		if (tmpKey[i] != 0){ // i番のキーコードに対応するキーが押されていたら
			Key[i]++;     // 加算
		}
		else {              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}
	return 0;
}

// メニュー項目の表示に必要な構造体を用意する
typedef struct{
	int x, y;       // 座標格納用変数
	char name[128]; // 項目名格納用変数
} MenuElement_t;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	// メニュー項目要素を5つ作る
	MenuElement_t MenuElement[5] = {
		{ 80, 100, "ゲームスタート" }, // タグの中身の順番で格納される。xに80が、yに100が、nameに"ゲームスタート"が
		{ 100, 150, "おまけ" },
		{ 100, 200, "ヘルプ" },
		{ 100, 250, "コンフィグ" },
		{ 100, 300, "ゲーム終了" },
	};
	int SelectNum = 0; // 現在の選択番号

	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア, キー更新)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0){

		// 計算フェーズ 

		if (Key[KEY_INPUT_DOWN] == 1){ // 下キーが押された瞬間だけ処理

			SelectNum = (SelectNum + 1) % 5; // 現在の選択項目を一つ下にずらす(ループする)

			for (int i = 0; i<5; i++){              // メニュー項目数である5個ループ処理
				if (i == SelectNum){          // 今処理しているのが、選択番号と同じ要素なら
					MenuElement[i].x = 80; // 座標を80にする
				}
				else {                       // 今処理しているのが、選択番号以外なら
					MenuElement[i].x = 100;// 座標を100にする
				}
			}
		}

		// 描画フェーズ

		for (int i = 0; i<5; i++){ // メニュー項目を描画
			DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(255, 255, 255), MenuElement[i].name);
		}

	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}*/