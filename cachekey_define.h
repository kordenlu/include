/*
 * cachechar_define.h
 *
 *  Created on: Mar 9, 2015
 *      Author: jimm
 */

#ifndef CACHEKEY_DEFINE_H_
#define CACHEKEY_DEFINE_H_

#include "../frame/frame_impl.h"
using namespace FRAME;

#define MAX_FIELD_SIZE		256

#define UNHANDLE_USER_LIST		"unhandle:userlist"
#define USER_UNREAD_LOCK		"user:unread:lock:"
#define ACCOUNT_POOL				"account:pool"
#define ACCOUNTID					"accountid:"


#define REGIST_PHONEINFO	"regist:phoneinfo:"
class RegistPhoneInfo : public IConfig
{
public:
	RegistPhoneInfo(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		strcpy(regist_count, "regist_count");
		strcpy(last_regist_date, "last_regist_date");
		strcpy(auth_code, "auth_code");
		strcpy(auth_code_expire_time, "auth_code_expire_time");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}

	char string[MAX_FIELD_SIZE];
	char regist_count[MAX_FIELD_SIZE];
	char last_regist_date[MAX_FIELD_SIZE];
	char auth_code[MAX_FIELD_SIZE];
	char auth_code_expire_time[MAX_FIELD_SIZE];
};

#define REGIST_ADDRINFO		"regist:addrinfo:"
class RegistAddrInfo : public IConfig
{
public:
	RegistAddrInfo(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		strcpy(regist_count, "regist_count");
		strcpy(last_regist_date, "last_regist_date");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}

	char string[MAX_FIELD_SIZE];
	char regist_count[MAX_FIELD_SIZE];
	char last_regist_date[MAX_FIELD_SIZE];
};

#define USER_BASEINFO		"user:baseinfo:"
class UserBaseInfo : public IConfig
{
public:
	UserBaseInfo(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}

	//初始化配置
	virtual int32_t Init()
	{
		strcpy(version, "version");
		strcpy(accountname, "accountname");
		strcpy(uin, "uin");
		strcpy(oneselfwords, "oneselfwords");
		strcpy(school, "school");
		strcpy(hometown, "hometown");
		strcpy(birthplace, "birthplace");
		strcpy(liveplace, "liveplace");
		strcpy(job, "job");
		strcpy(age, "age");
		strcpy(height, "height");
		strcpy(weight, "weight");
		strcpy(nickname, "nickname");
		strcpy(gender, "gender");
		strcpy(headimage, "headimage");
		strcpy(createtime, "createtime");
		strcpy(birthday, "birthday");
		strcpy(age, "age");
		strcpy(care_people_count, "care_people_count");
		strcpy(fans_count, "fans_count");
		strcpy(friends_count, "friends_count");
		strcpy(publishtopic_count, "publishtopic_count");
		strcpy(jointopic_count, "jointopic_count");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}

	char string[MAX_FIELD_SIZE];
	char version[MAX_FIELD_SIZE];
	char accountname[MAX_FIELD_SIZE];
	char uin[MAX_FIELD_SIZE];
	char nickname[MAX_FIELD_SIZE];
	char oneselfwords[MAX_FIELD_SIZE];
	char school[MAX_FIELD_SIZE];
	char hometown[MAX_FIELD_SIZE];
	char birthplace[MAX_FIELD_SIZE];
	char liveplace[MAX_FIELD_SIZE];
	char job[MAX_FIELD_SIZE];
	char height[MAX_FIELD_SIZE];
	char weight[MAX_FIELD_SIZE];
	char gender[MAX_FIELD_SIZE];
	char headimage[MAX_FIELD_SIZE];
	char createtime[MAX_FIELD_SIZE];
	char birthday[MAX_FIELD_SIZE];
	char age[MAX_FIELD_SIZE];
	char care_people_count[MAX_FIELD_SIZE];
	char fans_count[MAX_FIELD_SIZE];
	char friends_count[MAX_FIELD_SIZE];
	char publishtopic_count[MAX_FIELD_SIZE];
	char jointopic_count[MAX_FIELD_SIZE];
};

#define ACCOUNT_INFO			"accountinfo:"
class AccountInfo : public IConfig
{
public:
	AccountInfo(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		strcpy(accountname, "accountname");
		strcpy(uin, "uin");
		strcpy(accountid, "accountid");
		strcpy(password, "password");
		strcpy(status, "status");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}
	char string[MAX_FIELD_SIZE];
	char accountname[MAX_FIELD_SIZE];
	char uin[MAX_FIELD_SIZE];
	char accountid[MAX_FIELD_SIZE];
	char password[MAX_FIELD_SIZE];
	char status[MAX_FIELD_SIZE];
};

#define USER_BLACKLIST			"user:blacklist:"
class UserBlackList : public IConfig
{
public:
	UserBlackList(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		strcpy(uin, "uin");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}
	char string[MAX_FIELD_SIZE];
	char uin[MAX_FIELD_SIZE];
};

#define USER_SESSIONINFO			"user:sessioninfo:"
class UserSessionInfo : public IConfig
{
public:
	UserSessionInfo(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		strcpy(sessionid, "sessionid");
		strcpy(clientaddress, "clientaddress");
		strcpy(clientport, "clientport");
		strcpy(gateid, "gateid");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}
	char string[MAX_FIELD_SIZE];
	char sessionid[MAX_FIELD_SIZE];
	char clientaddress[MAX_FIELD_SIZE];
	char clientport[MAX_FIELD_SIZE];
	char gateid[MAX_FIELD_SIZE];
};

#define USER_UNREADMSGLIST			"user:unreadmsglist:"
class UserUnreadMsgList : public IConfig
{
public:
	UserUnreadMsgList(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		strcpy(timestamp, "timestamp");
		strcpy(unreadmsg, "unreadmsg");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}
	char string[MAX_FIELD_SIZE];
	char timestamp[MAX_FIELD_SIZE];
	char unreadmsg[MAX_FIELD_SIZE];
};

#endif /* CACHEKEY_DEFINE_H_ */
