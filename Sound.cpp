#include "Sound.h"
#include "DxLib.h"



//初期化
Sound::Sound(){//初期化代わりにコンストラクタを使用
	SoundData = NULL;
	play_start_time = 0;
	play_stop_time = 0;
	volumeData = 1;
};



//サウンドデータをセット
void Sound::setSound(int sound){//サウンドデータをセット
	SoundData = sound;
}
void Sound::setSound(char* sound){//場所を指定してサウンドデータをセット
	SoundData = LoadSoundMem(sound);
}


void Sound::setSoundVolume(int v){//ボリュームをセット
	if (v > 100)v = 100;
	if (v < 0)v = 0;
	volumeData = v * 0.01;
};




//ノーマルでサウンドプレイ

void Sound::playSound_normal(){//既にセットしてあるものをノーマルで再生
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_NORMAL, TRUE);
}
void Sound::playSound_normal(int sound, int volume){//メモリにセットしてあるものを、ボリュームを変えてノーマルで再生
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volume, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_NORMAL, TRUE);
}
void Sound::playSound_normal(char* sound, int volume){//直接読み込み場所とボリュームを設定し、ノーマルで再生
	int SoundData = LoadSoundMem(sound);
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_NORMAL, TRUE);
}




//バックグラウンドでサウンドプレイ


void Sound::playSound_back(){//既にセットしてあるものをバックグラウンドで再生
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_BACK, TRUE);
}
void Sound::playSound_back(int sound, int volume){//メモリにセットしてあるものを、ボリュームを変えてバックグラウンドで再生
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volume, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_BACK, TRUE);
}
void Sound::playSound_back(char* sound, int volume){//直接読み込み場所とボリュームを設定し、バックグラウンドで再生
	int SoundData = LoadSoundMem(sound);
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_BACK, TRUE);
}




//ループでサウンドプレイ

void Sound::playSound_loop(){//既にセットしてあるものをループで再生
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_LOOP, TRUE);
}
void Sound::playSound_loop(int sound, int volume){//メモリにセットしてあるものを、ボリュームを変えてループで再生
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volume, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP, TRUE);
}
void Sound::playSound_loop(char* sound, int volume){//直接読み込み場所とボリュームを設定し、ループで再生
	int SoundData = LoadSoundMem(sound);
	setSoundVolume(volume);
	ChangeVolumeSoundMem(255 * volumeData, SoundData);
	PlaySoundMem(SoundData, DX_PLAYTYPE_LOOP, TRUE);
}




//サウンドストップ
void Sound::stopSound(){//サウンドストップ
	StopSoundMem(SoundData);
}