#include "DxLib.h"

#ifndef DEF_SOUND_H

#define DEF_SOUND_H

class Sound{
	int SoundData;			//サウンドを記録したメモリのデータ
	int play_start_time;	//まだ使わない
	int play_stop_time;		//まだ使わない
	double volumeData;		//ボリュームの大きさ（0.00~1.00）
public:
	//サウンドの初期化
	Sound();

	//サウンドをセット
	void setSound(int sound);
	void setSound(char* sound);

	//サウンドボリュームをセット
	void setSoundVolume(int volume);

	//ノーマル再生
	void playSound_normal();
	void playSound_normal(int sound, int volume);
	void playSound_normal(char* sound, int volume);

	//バックグラウンド再生
	void playSound_back();
	void playSound_back(int sound, int volume);
	void playSound_back(char* sound, int volume);

	//ループ再生
	void playSound_loop();
	void playSound_loop(int sound, int volume);
	void playSound_loop(char* sound, int volume);

	//再生ストップ
	void stopSound();
};
#endif