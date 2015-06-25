#include "DxLib.h"
#include "Player.h"



// このファイル内でしか使えないグローバル変数
static int p_x=150;     //x座標
static int p_y=150;		//y座標
static int c_tip[28]; //キャラ画像格納配列
static int char_chip[20];//並べ替えたキャラチップ
static int flag=0;	//キャラの左右反転時のフラグ
static int flag_stop = 0;//キャラの停止
static int flag_jump = 0;//キャラのジャンプ
//static int char_wait=4;

//フレーム管理変数
static int frame_left = 0;
static int frame_right = 0;
static int frame_stop = 0;
static int frame_jump = 0;

static int frame_left_data = 0;
static int frame_right_data = 0;
static int frame_stop_data = 0;
static int frame_jump_data = 0;

//コンフィグにも使用する変数
static int char_chip_count_left = 5;//左移動用
static int char_chip_count_right = 5;//右移動用
static int char_chip_count_stop = 0;//停止用
static int char_chip_count_jump = 13;//ジャンプ用
static int char_flag = 0;//キャラのモーションの初期化フラグ
static int p_w, p_h;



// 初期化をする
void initializePlayer(){
	LoadDivGraph("c1.png", 28, 7, 4, 128, 128, c_tip);//ユニティーちゃん読み込み
	
	// 0～2、停止
	char_chip[0] = c_tip[0];
	char_chip[1] = c_tip[1];
	char_chip[2] = c_tip[2];

	//使ってない
	char_chip[3] = c_tip[3];
	char_chip[4] = c_tip[4];
	
	//移動処理5~8
	char_chip[5] = c_tip[7];
	char_chip[6] = c_tip[8];
	char_chip[7] = c_tip[9];
	char_chip[8] = c_tip[10];
	//移動処理9~12
	char_chip[9] = c_tip[14];
	char_chip[10] = c_tip[15];
	char_chip[11] = c_tip[16];
	char_chip[12] = c_tip[17];

	//ジャンプ処理（上昇中）13~15
	char_chip[13] = c_tip[21];
	char_chip[14] = c_tip[22];
	char_chip[15] = c_tip[23];

	//ジャンプ処理(下降中)16~18
	char_chip[16] = c_tip[24];
	char_chip[17] = c_tip[25];
	char_chip[18] = c_tip[26];
	char_chip[19] = c_tip[27];

	GetGraphSize(char_chip[0], &p_w, &p_h);//横幅と縦幅取得

	//キャラクターを中央に設置
	int window_W, window_H;
	GetWindowSize(&window_W,&window_H);
	p_x = window_W / 2 - p_w / 2;
	//p_y = window_H / 2 - p_h / 2;
	p_y = window_H - p_h;


}


// 描画する
void drawPlayer(){
	
	switch (flag){

	case 0: DrawTurnGraph(p_x, p_y, char_chip[char_chip_count_left], TRUE);
		
		break;//左描画
	
	case 1: DrawGraph(p_x, p_y, char_chip[char_chip_count_right], TRUE);
		

		break;//右描画
	
	case 2: if (flag_stop == 0){ DrawTurnGraph(p_x, p_y, char_chip[char_chip_count_stop], TRUE); }
			else{ DrawGraph(p_x, p_y, char_chip[char_chip_count_stop], TRUE); }
		break;//停止

		
	}
	
}

//左移動
void leftMove(){

	/*
	//char_chipを5にセットする(毎回初期化しないのは、一つのチップしか反映されなくなるため)
	while(char_chip_count<4*char_wait||char_chip_count>11*char_wait){
	char_chip_count++;
	if (char_chip_count==12*char_wait){
	char_chip_count = 0;
	}
	}
	//キャラを動かせる
	char_chip_count++;
	if (char_chip_count==12*char_wait){
	char_chip_count = 4;
	}
	*/
	if (frame_left_data == 5){

	if (char_chip_count_left == 12){
		char_chip_count_left = 5;
	}
	else
	{
		char_chip_count_left++;
	}

	//左右反転処理

	flag = 0;
	flag_stop = 0;
	}
	//フレーム処理
	frame_left_data = (frame_left % 5 + 1);
	frame_left++;

	if (frame_left >= 5)frame_left = 0;
}

//右移動
void rightMove(){
	if (frame_right_data==5){
	if (char_chip_count_right == 12){
		char_chip_count_right = 5;
	}
	else
	{
		char_chip_count_right++;
	}


	//左右反転処理

	flag = 1;
	flag_stop = 1;
	}
	
	//フレーム処理
	frame_right_data = (frame_right % 5 + 1);
	frame_right++;
	if (frame_right >= 5)frame_right = 0;
}

//停止処理
void stopPlayer(){

	if (frame_stop_data == 20){
		if (char_chip_count_stop == 2){
			char_chip_count_stop = 0;
		}
		else
		{
			char_chip_count_stop++;
		}

		flag = 2;
	}
	
	//フレーム処理
	frame_stop_data = (frame_stop % 20 + 1);
	frame_stop++;
	if (frame_stop >= 20)frame_stop = 0;
}

//ダッシュ
void dashPlayer(){
}
//効果音設定
void setSound(){
}
//mapSize
void mapSize(){
}
//コンフィグ状態を表示する
void drawConfig(){
	clsDx();

	//モーションを表示

	if (flag == 3){
		printfDx("キャラチップ番号 : %d\n", char_chip_count_jump);
		printfDx("キャラモーション : ジャンプ\n");
	}


	if (flag == 1){
		printfDx("キャラチップ番号 : %d\n", char_chip_count_right);
		printfDx("キャラモーション : 右移動\n");
	}
	else if(flag == 0){
		printfDx("キャラチップ番号 : %d\n", char_chip_count_left);
		printfDx("キャラモーション : 左移動\n");
	}else if (flag == 2){
		if (flag_stop == 1){
			printfDx("キャラチップ番号 : %d\n", char_chip_count_stop);
			printfDx("キャラモーション : 右停止\n");
		}else{
			printfDx("キャラチップ番号 : %d\n", char_chip_count_stop);
			printfDx("キャラモーション : 左停止\n");
		}
	}

	//X座標とＹ座標を表示
	printfDx("キャラ＿座標＿Ｘ : %d\n", p_x);
	printfDx("キャラ＿座標＿Ｙ : %d\n", p_y);

	//横幅と縦幅の表示
	printfDx("キャラサイズ＿Ｗ : %d\n",p_w);
	printfDx("キャラサイズ＿Ｈ : %d\n", p_h);

}

