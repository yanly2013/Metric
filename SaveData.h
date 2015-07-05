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
	std::string getName(int index);
	int getScore(int index);
	void readSetting();
	void saveSetting(bool music, bool sound, bool vibrate, bool tool);
	bool IsMusic();
	bool IsSound();
	bool IsVibrate();
	bool IsTool();
	void saveGamemode(int gamemode);
	int getGamemode();


private:
	SaveData();
	void addnameandscoreLeisuremode(char *pname, int scores);
	void addnameandscoreTimemode(char *pname, int scores);
	void addnameandscoreCrazymode(char *pname, int scores);
	void SortwithScore();
	std::string name[10];
	int  score[10];
    std::string nametimemode[10];
	int  scoretimemode[10];
	std::string namecrazymode[10];
	int  scorecrazymode[10];
    bool isMusic;
	bool isSound;
	bool isVibrate;
	bool isTool;
	
	int m_gamemode;
	
    static SaveData* m_SaveDataInst;
};


#endif