#include "DxLib.h"

#ifndef DEF_MAP_H //二重include防止

#define DEF_MAP_H

//初期化処理
void initializeMap();

//マップを描画する
void drawMap();

//スクロールマップ
void scrollMap();

//右スクロール
void rightScroll();

//左スクロール
void leftScroll();

//下スクロール
void downScroll();

//上スクロール
void upScroll();

//ジャンプスクロール
void jumpScroll();

#endif 