#include "DxLib.h"
#include "Map.h"



//この関数内での変数
static int map_image=NULL;

static int window_W, window_H;//ウィンドウのサイズ
static int map_W, map_H;//マップサイズ
static int map_X, map_Y;//マップ座標
static int scroll_speed = 8;
static int jump_scroll_speed = 3;
static int fall_scroll_speed = 5;
static int right_flag=0;
static int motion_flag = 0;

static int map_back;
static int map_front;

static int chip_jump_data=0;


//初期化
void initializeMap(){

	
	map_image = LoadGraph("map1.jpg");  //マップをメモリに読み込み
	

	GetGraphSize(map_image, &map_W, &map_H);//横幅と縦幅取得

	GetWindowSize(&window_W, &window_H);

	//map_Y = window_H - map_H;
	map_Y = 0;
	map_X = 0;
}

//マップを描画する
void drawMap(){
	
	/*DrawGraph(map_X, map_Y, map_image, FALSE);
	DrawGraph(map_X, map_Y, map_back, true);
	DrawGraph(map_X, map_Y, map_front, true);*/

	DrawExtendGraph(map_X, map_Y, map_X+640,map_Y+480, map_image, TRUE);

	

}

/*//スクロールマップ
void scrollMap(){

	switch (motion_flag){
	case 0:map_X += scroll_speed;//左(キャラ)マップは右へ流れる
		break;
	case 1:map_X -= scroll_speed;//右（キャラ）マップは左へ流れる
		break;
	case 2://stop(キャラ)マップは止まる
		break;
	}

}*/

//マップが右にスクロール

void rightScroll(){
	map_X += scroll_speed;
}

//マップが左にスクロール

void leftScroll(){
	map_X -= scroll_speed;
}

//マップが下にスクロール

void downScroll(){
	map_Y += jump_scroll_speed;
}

//マップが上にスクロール

void upScroll(){
	map_Y -= jump_scroll_speed;
}

//ジャンプスクロール関数

void jumpScroll(){

	chip_jump_data++;
	
	if (chip_jump_data <= 24){
		map_Y += 10;
	}
	else{
		if (chip_jump_data <= 56){
			map_Y -= 7;
		}
		else{ chip_jump_data = 0; }
	}
}
