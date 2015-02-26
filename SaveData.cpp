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
         name[index] = "----";
		 score[index] = 0;
    }
}
void SaveData::readNameandScore()
{
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
}
void SaveData::addaNameandScore(char *pname, int scores)
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
	    name[index] = newname;
		score[index] = newscore;
		for (int i = 8; i <= index; i--)
		{
		    memmove(&name[i], &name[i+1], sizeof(name));
			memmove(&score[i], &score[i+1], sizeof(score));
		}
	}

	
}
void SaveData::saveNameandScore()
{
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
}

std::string SaveData::getName(int index)
{
    return name[index];
}
int SaveData::getScore(int index)
{
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