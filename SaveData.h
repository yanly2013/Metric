#ifndef __SAVEDATA_H__
#define __SAVEDATA_H__
#include <string>
class SaveData
{
public:
    static SaveData* getInstant();
	void readNameandScore();
    void addaNameandScore(char *pname, int score);
    void saveNameandScore();
	void readSetting();
	void saveSetting(bool music, bool sound, bool vibrate);
	bool IsMusic();
	bool IsSound();
	bool IsVibrate();


private:
	void SortwithScore();
	std::string name[10];
	int  score[10];
    bool isMusic;
	bool isSound;
	bool isVibrate;
	
    static SaveData* m_SaveDataInst;
};


#endif