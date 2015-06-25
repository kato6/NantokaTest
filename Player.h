#include "DxLib.h"

#ifndef DEF_PLAYER_H //二重include防止

#define DEF_PLAYER_H

// 初期化をする
void initializePlayer();

// 描画する
void drawPlayer();

//プレイヤーをsetする
void setPlayer();

//左移動
void leftMove();

//右移動
void rightMove();

//停止処理
void stopPlayer();

//ジャンプ
void jumpMove();

//ダッシュ
void dashPlayer();

//効果音指定
void setSound();

//マップあたり判定
void mapSize();

//コンフィグ状態を表示する
void drawConfig();

// 終了処理をする
void Player_Finalize();


#endif 