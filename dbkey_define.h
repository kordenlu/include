/*
 * dbkey_define.h
 *
 *  Created on: 2015年3月29日
 *      Author: jimm
 */

#ifndef DBKEY_DEFINE_H_
#define DBKEY_DEFINE_H_

#include "../frame/frame_impl.h"
using namespace FRAME;

#define MAX_FIELD_SIZE		256

#define DB_LOCATION		"location"
class DB_Location : public IConfig
{
public:
	DB_Location(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}

	class TB_UserCoord
	{
	public:
		TB_UserCoord()
		{
			strcpy(string, "user_coord");
			strcpy(uin, "uin");
			strcpy(position, "position");
			strcpy(nickname, "nickname");
			strcpy(headimageaddr, "headimageaddr");
			strcpy(gender, "gender");
			strcpy(age, "age");
			strcpy(oneselfwords, "oneselfwords");
			strcpy(updatetime, "updatetime");
		}

		char 			string[MAX_FIELD_SIZE];
		char		 	uin[MAX_FIELD_SIZE];
		char	 		position[MAX_FIELD_SIZE];
		char			nickname[MAX_FIELD_SIZE];
		char			headimageaddr[MAX_FIELD_SIZE];
		char			gender[MAX_FIELD_SIZE];
		char			age[MAX_FIELD_SIZE];
		char			oneselfwords[MAX_FIELD_SIZE];
		char	 		updatetime[MAX_FIELD_SIZE];
	};

	char 					string[MAX_FIELD_SIZE];
	TB_UserCoord		user_coord;
};


#endif /* DBKEY_DEFINE_H_ */
