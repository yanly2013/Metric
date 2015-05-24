#include "savedata.h"
#include "cocos2d.h"
USING_NS_CC;
SaveData* SaveData::m_SaveDataInst = 0;

SaveData* SaveData::getInstant()
{
    if (m_SaveDataInst == 0)
    {
        m_SaveDataInst = new SaveData();
    }
	return m_SaveDataInst;
}
SaveData::SaveData()
{
    for (int index = 0; index< 10; index++)
    {
         name[index] = "unkownnameunkownnameunkownnameunkownnameunkownnam";
		 score[index] = 0;
         nametimemode[index] = "unkownnameunkownnameunkownnameunkownnameunkownnam";
		 scoretimemode[index] = 0;
		 namecrazymode[index] = "unkownnameunkownnameunkownnameunkownnameunkownnam";
		 scorecrazymode[index] = 0;
    }
	
	if (!CCUserDefault::sharedUserDefault()->getBoolForKey("FirstWrite"))
	{
		saveNameandScore();
			
	    CCUserDefault::sharedUserDefault()->setBoolForKey("FirstWrite",true);
	    CCUserDefault::sharedUserDefault()->flush();//
	}
	m_gamemode = 0;

}
void SaveData::readNameandScore()
{
	switch (m_gamemode)
	{
	case 0:
    name[0] = CCUserDefault::sharedUserDefault()->getStringForKey("firstname");
    name[1] = CCUserDefault::sharedUserDefault()->getStringForKey("secondname");
    name[2] = CCUserDefault::sharedUserDefault()->getStringForKey("thirdname");
    name[3] = CCUserDefault::sharedUserDefault()->getStringForKey("forthname");
    name[4] = CCUserDefault::sharedUserDefault()->getStringForKey("fifthname");
    name[5] = CCUserDefault::sharedUserDefault()->getStringForKey("sixthname");
    name[6] = CCUserDefault::sharedUserDefault()->getStringForKey("seventhname");
    name[7] = CCUserDefault::sharedUserDefault()->getStringForKey("eighthname");
    name[8] = CCUserDefault::sharedUserDefault()->getStringForKey("ninthname");
    name[9] = CCUserDefault::sharedUserDefault()->getStringForKey("tenthname");

	score[0] = CCUserDefault::sharedUserDefault()->getIntegerForKey("firstscore");
	score[1] = CCUserDefault::sharedUserDefault()->getIntegerForKey("secondscore");
	score[2] = CCUserDefault::sharedUserDefault()->getIntegerForKey("thirdscore");
	score[3] = CCUserDefault::sharedUserDefault()->getIntegerForKey("forthscore");
	score[4] = CCUserDefault::sharedUserDefault()->getIntegerForKey("fifthscore");
	score[5] = CCUserDefault::sharedUserDefault()->getIntegerForKey("sixthscore");
	score[6] = CCUserDefault::sharedUserDefault()->getIntegerForKey("seventhscore");
	score[7] = CCUserDefault::sharedUserDefault()->getIntegerForKey("eighthscore");
	score[8] = CCUserDefault::sharedUserDefault()->getIntegerForKey("ninthscore");
	score[9] = CCUserDefault::sharedUserDefault()->getIntegerForKey("tenthscore");
	break;
	case 1:
    nametimemode[0] = CCUserDefault::sharedUserDefault()->getStringForKey("firstnametimemode");
    nametimemode[1] = CCUserDefault::sharedUserDefault()->getStringForKey("secondnametimemode");
    nametimemode[2] = CCUserDefault::sharedUserDefault()->getStringForKey("thirdnametimemode");
    nametimemode[3] = CCUserDefault::sharedUserDefault()->getStringForKey("forthnametimemode");
    nametimemode[4] = CCUserDefault::sharedUserDefault()->getStringForKey("fifthnametimemode");
    nametimemode[5] = CCUserDefault::sharedUserDefault()->getStringForKey("sixthnametimemode");
    nametimemode[6] = CCUserDefault::sharedUserDefault()->getStringForKey("seventhnametimemode");
    nametimemode[7] = CCUserDefault::sharedUserDefault()->getStringForKey("eighthnametimemode");
    nametimemode[8] = CCUserDefault::sharedUserDefault()->getStringForKey("ninthnametimemode");
    nametimemode[9] = CCUserDefault::sharedUserDefault()->getStringForKey("tenthnametimemode");

	scoretimemode[0] = CCUserDefault::sharedUserDefault()->getIntegerForKey("firstscoretimemode");
	scoretimemode[1] = CCUserDefault::sharedUserDefault()->getIntegerForKey("secondscoretimemode");
	scoretimemode[2] = CCUserDefault::sharedUserDefault()->getIntegerForKey("thirdscoretimemode");
	scoretimemode[3] = CCUserDefault::sharedUserDefault()->getIntegerForKey("forthscoretimemode");
	scoretimemode[4] = CCUserDefault::sharedUserDefault()->getIntegerForKey("fifthscoretimemode");
	scoretimemode[5] = CCUserDefault::sharedUserDefault()->getIntegerForKey("sixthscoretimemode");
	scoretimemode[6] = CCUserDefault::sharedUserDefault()->getIntegerForKey("seventhscoretimemode");
	scoretimemode[7] = CCUserDefault::sharedUserDefault()->getIntegerForKey("eighthscoretimemode");
	scoretimemode[8] = CCUserDefault::sharedUserDefault()->getIntegerForKey("ninthscoretimemode");
	scoretimemode[9] = CCUserDefault::sharedUserDefault()->getIntegerForKey("tenthscoretimemode");
	break;
	case 2:
    namecrazymode[0] = CCUserDefault::sharedUserDefault()->getStringForKey("firstnamecrazymode");
    namecrazymode[1] = CCUserDefault::sharedUserDefault()->getStringForKey("secondnamecrazymode");
    namecrazymode[2] = CCUserDefault::sharedUserDefault()->getStringForKey("thirdnamecrazymode");
    namecrazymode[3] = CCUserDefault::sharedUserDefault()->getStringForKey("forthnamecrazymode");
    namecrazymode[4] = CCUserDefault::sharedUserDefault()->getStringForKey("fifthnamecrazymode");
    namecrazymode[5] = CCUserDefault::sharedUserDefault()->getStringForKey("sixthnamecrazymode");
    namecrazymode[6] = CCUserDefault::sharedUserDefault()->getStringForKey("seventhnamecrazymode");
    namecrazymode[7] = CCUserDefault::sharedUserDefault()->getStringForKey("eighthnamecrazymode");
    namecrazymode[8] = CCUserDefault::sharedUserDefault()->getStringForKey("ninthnamecrazymode");
    namecrazymode[9] = CCUserDefault::sharedUserDefault()->getStringForKey("tenthnamecrazymode");

	scorecrazymode[0] = CCUserDefault::sharedUserDefault()->getIntegerForKey("firstscorecrazymode");
	scorecrazymode[1] = CCUserDefault::sharedUserDefault()->getIntegerForKey("secondscorecrazymode");
	scorecrazymode[2] = CCUserDefault::sharedUserDefault()->getIntegerForKey("thirdscorecrazymode");
	scorecrazymode[3] = CCUserDefault::sharedUserDefault()->getIntegerForKey("forthscorecrazymode");
	scorecrazymode[4] = CCUserDefault::sharedUserDefault()->getIntegerForKey("fifthscorecrazymode");
	scorecrazymode[5] = CCUserDefault::sharedUserDefault()->getIntegerForKey("sixthscorecrazymode");
	scorecrazymode[6] = CCUserDefault::sharedUserDefault()->getIntegerForKey("seventhscorecrazymode");
	scorecrazymode[7] = CCUserDefault::sharedUserDefault()->getIntegerForKey("eighthscorecrazymode");
	scorecrazymode[8] = CCUserDefault::sharedUserDefault()->getIntegerForKey("ninthscorecrazymode");
	scorecrazymode[9] = CCUserDefault::sharedUserDefault()->getIntegerForKey("tenthscorecrazymode");
	break;
	}
}
void SaveData::addaNameandScore(char *pname, int scores)
{
	switch (m_gamemode)
	{
	case 0:
		addnameandscoreLeisuremode(pname, scores);
		break;
	case 1:
		addnameandscoreTimemode(pname, scores);
		break;
	case 2:
		addnameandscoreCrazymode(pname, scores);
		break;
	}

}
void SaveData::addnameandscoreLeisuremode(char *pname, int scores)
{
    std::string newname = pname;
	int newscore = scores;
    int index = 0;
    for (index = 0; index< 10; index++)
    {
        if (newscore > score[index])
        {
            break;
        }
    }
	if (index != 10)
	{
		for (int i = 8; i >= index; i--)
		{
			memmove(&score[i+1], &score[i], sizeof(int));
		    name[i+1]=name[i];

		}
        name[index] = newname;
		score[index] = newscore;
	}

}
void SaveData::addnameandscoreTimemode(char *pname, int scores)
{
    std::string newname = pname;
	int newscore = scores;
    int index = 0;
    for (index = 0; index< 10; index++)
    {
        if (newscore > scoretimemode[index])
        {
            break;
        }
    }
	if (index != 10)
	{
		for (int i = 8; i >= index; i--)
		{
			memmove(&scoretimemode[i+1], &scoretimemode[i], sizeof(int));
		    nametimemode[i+1]=nametimemode[i];

		}
        nametimemode[index] = newname;
		scoretimemode[index] = newscore;
	}

}

void SaveData::addnameandscoreCrazymode(char *pname, int scores)
{
    std::string newname = pname;
	int newscore = scores;
    int index = 0;
    for (index = 0; index< 10; index++)
    {
        if (newscore > scorecrazymode[index])
        {
            break;
        }
    }
	if (index != 10)
	{
		for (int i = 8; i >= index; i--)
		{
			memmove(&scorecrazymode[i+1], &scorecrazymode[i], sizeof(int));
		    namecrazymode[i+1]=namecrazymode[i];

		}
        namecrazymode[index] = newname;
		scorecrazymode[index] = newscore;
	}

}
void SaveData::saveNameandScore()
{
	switch (m_gamemode)
	{
	case 0:
    CCUserDefault::sharedUserDefault()->setStringForKey("firstname", name[0]);
    CCUserDefault::sharedUserDefault()->setStringForKey("secondname", name[1]);
    CCUserDefault::sharedUserDefault()->setStringForKey("thirdname", name[2]);
    CCUserDefault::sharedUserDefault()->setStringForKey("forthname", name[3]);
	CCUserDefault::sharedUserDefault()->setStringForKey("fifthname", name[4]);
	CCUserDefault::sharedUserDefault()->setStringForKey("sixthname", name[5]);
    CCUserDefault::sharedUserDefault()->setStringForKey("seventhname", name[6]);
    CCUserDefault::sharedUserDefault()->setStringForKey("eighthname", name[7]);
    CCUserDefault::sharedUserDefault()->setStringForKey("ninthname", name[8]);
    CCUserDefault::sharedUserDefault()->setStringForKey("tenthname", name[9]);

	CCUserDefault::sharedUserDefault()->setIntegerForKey("firstscore", score[0]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("secondscore", score[1]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("thirdscore", score[2]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("forthscore", score[3]);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("fifthscore", score[4]);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("sixthscore", score[5]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("seventhscore", score[6]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("eighthscore", score[7]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("ninthscore", score[8]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("tenthscore", score[9]);
	break;
	case 1:
    CCUserDefault::sharedUserDefault()->setStringForKey("firstnametimemode", nametimemode[0]);
    CCUserDefault::sharedUserDefault()->setStringForKey("secondnametimemode", nametimemode[1]);
    CCUserDefault::sharedUserDefault()->setStringForKey("thirdnametimemode", nametimemode[2]);
    CCUserDefault::sharedUserDefault()->setStringForKey("forthnametimemode", nametimemode[3]);
	CCUserDefault::sharedUserDefault()->setStringForKey("fifthnametimemode", nametimemode[4]);
	CCUserDefault::sharedUserDefault()->setStringForKey("sixthnametimemode", nametimemode[5]);
    CCUserDefault::sharedUserDefault()->setStringForKey("seventhnametimemode", nametimemode[6]);
    CCUserDefault::sharedUserDefault()->setStringForKey("eighthnametimemode", nametimemode[7]);
    CCUserDefault::sharedUserDefault()->setStringForKey("ninthnametimemode", nametimemode[8]);
    CCUserDefault::sharedUserDefault()->setStringForKey("tenthnametimemode", nametimemode[9]);

	CCUserDefault::sharedUserDefault()->setIntegerForKey("firstscoretimemode", scoretimemode[0]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("secondscoretimemode", scoretimemode[1]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("thirdscoretimemode", scoretimemode[2]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("forthscoretimemode", scoretimemode[3]);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("fifthscoretimemode", scoretimemode[4]);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("sixthscoretimemode", scoretimemode[5]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("seventhscoretimemode", scoretimemode[6]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("eighthscoretimemode", scoretimemode[7]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("ninthscoretimemode", scoretimemode[8]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("tenthscoretimemode", scoretimemode[9]);
	break;
	case 2:
    CCUserDefault::sharedUserDefault()->setStringForKey("firstnamecrazymode", namecrazymode[0]);
    CCUserDefault::sharedUserDefault()->setStringForKey("secondnamecrazymode", namecrazymode[1]);
    CCUserDefault::sharedUserDefault()->setStringForKey("thirdnamecrazymode", namecrazymode[2]);
    CCUserDefault::sharedUserDefault()->setStringForKey("forthnamecrazymode", namecrazymode[3]);
	CCUserDefault::sharedUserDefault()->setStringForKey("fifthnamecrazymode", namecrazymode[4]);
	CCUserDefault::sharedUserDefault()->setStringForKey("sixthnamecrazymode", namecrazymode[5]);
    CCUserDefault::sharedUserDefault()->setStringForKey("seventhnamecrazymode", namecrazymode[6]);
    CCUserDefault::sharedUserDefault()->setStringForKey("eighthnamecrazymode", namecrazymode[7]);
    CCUserDefault::sharedUserDefault()->setStringForKey("ninthnamecrazymode", namecrazymode[8]);
    CCUserDefault::sharedUserDefault()->setStringForKey("tenthnamecrazymode", namecrazymode[9]);

	CCUserDefault::sharedUserDefault()->setIntegerForKey("firstscorecrazymode", scorecrazymode[0]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("secondscorecrazymode", scorecrazymode[1]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("thirdscorecrazymode", scorecrazymode[2]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("forthscorecrazymode", scorecrazymode[3]);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("fifthscorecrazymode", scorecrazymode[4]);
	CCUserDefault::sharedUserDefault()->setIntegerForKey("sixthscorecrazymode", scorecrazymode[5]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("seventhscorecrazymode", scorecrazymode[6]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("eighthscorecrazymode", scorecrazymode[7]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("ninthscorecrazymode", scorecrazymode[8]);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("tenthscorecrazymode", scorecrazymode[9]);
	break;

	}
	CCUserDefault::sharedUserDefault()->flush();//
}
void SaveData::saveGamemode(int gamemode)
{
	m_gamemode = gamemode;
}
int SaveData::getGamemode()
{
	return m_gamemode;
}
std::string SaveData::getName(int index)
{
	switch  (m_gamemode)
	{
	case 0:
         return name[index];
	case 1:
		return nametimemode[index];
	case 2:
		return namecrazymode[index];
	}
	return name[index];
}
int SaveData::getScore(int index)
{
	switch (m_gamemode)
	{
	case 0:
        return score[index];
	case 1:
		return scoretimemode[index];
	case 2:
		return scorecrazymode[index];
	}
	return score[index];
}
void SaveData::readSetting()
{
	isMusic = CCUserDefault::sharedUserDefault()->getBoolForKey("music");
	isSound = CCUserDefault::sharedUserDefault()->getBoolForKey("sound");	
	isVibrate = CCUserDefault::sharedUserDefault()->getBoolForKey("vibrate");
}
void SaveData::saveSetting(bool music, bool sound, bool vibrate)
{
    isMusic = music;
	isSound = sound;
	isVibrate = vibrate;
    CCUserDefault::sharedUserDefault()->setBoolForKey("music", music);
    CCUserDefault::sharedUserDefault()->setBoolForKey("sound", sound);
    CCUserDefault::sharedUserDefault()->setBoolForKey("vibrate", vibrate);
	CCUserDefault::sharedUserDefault()->flush();//
}
bool SaveData::IsMusic()
{
    return isMusic;
}
bool SaveData::IsSound()
{
    return isSound;
}
bool SaveData::IsVibrate()
{
    return isVibrate;
}