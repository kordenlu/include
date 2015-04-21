/*
 * cachechar_define.h
 *
 *  Created on: Mar 9, 2015
 *      Author: jimm
 */

#ifndef CACHEKEY_DEFINE_H_
#define CACHEKEY_DEFINE_H_

#include <map>
#include <string>
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
	std::map<std::string, uint8_t>		m_stFieldPer;
public:
	UserBaseInfo(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}

	bool CanWrite(std::string strField)
	{
		std::map<std::string, uint8_t>::iterator it = m_stFieldPer.find(strField);
		if(it != m_stFieldPer.end())
		{
			if(it->second != 0)
			{
				return true;
			}
		}
		return false;
	}

	//初始化配置
	virtual int32_t Init()
	{
		strcpy(version, "version");
		m_stFieldPer[version] = 0;

		strcpy(accountname, "accountname");
		m_stFieldPer[accountname] = 0;

		strcpy(uin, "uin");
		m_stFieldPer[uin] = 0;

		strcpy(accountid, "accountid");
		m_stFieldPer[accountid] = 0;

		strcpy(oneselfwords, "oneselfwords");
		m_stFieldPer[oneselfwords] = 1;

		strcpy(gender, "gender");
		m_stFieldPer[gender] = 0;

		strcpy(school, "school");
		m_stFieldPer[school] = 1;

		strcpy(hometown, "hometown");
		m_stFieldPer[hometown] = 1;

		strcpy(birthplace, "birthplace");
		m_stFieldPer[birthplace] = 1;

		strcpy(liveplace, "liveplace");
		m_stFieldPer[liveplace] = 1;

		strcpy(job, "job");
		m_stFieldPer[job] = 1;

		strcpy(height, "height");
		m_stFieldPer[height] = 1;

		strcpy(weight, "weight");
		m_stFieldPer[weight] = 1;

		strcpy(nickname, "nickname");
		m_stFieldPer[nickname] = 1;

		strcpy(headimage, "headimage");
		m_stFieldPer[headimage] = 1;

		strcpy(photowall, "photowall");
		m_stFieldPer[photowall] = 1;

		strcpy(createtime, "createtime");
		m_stFieldPer[createtime] = 0;

		strcpy(birthday, "birthday");
		m_stFieldPer[birthday] = 1;

		strcpy(age, "age");
		m_stFieldPer[version] = 1;

		strcpy(follow_people_count, "follow_people_count");
		m_stFieldPer[follow_people_count] = 1;

		strcpy(fans_count, "fans_count");
		m_stFieldPer[fans_count] = 1;

		strcpy(friends_count, "friends_count");
		m_stFieldPer[friends_count] = 1;

		strcpy(publishtopic_count, "publishtopic_count");
		m_stFieldPer[publishtopic_count] = 1;

		strcpy(jointopic_count, "jointopic_count");
		m_stFieldPer[jointopic_count] = 1;

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
	char accountid[MAX_FIELD_SIZE];
	char nickname[MAX_FIELD_SIZE];
	char oneselfwords[MAX_FIELD_SIZE];
	char gender[MAX_FIELD_SIZE];
	char school[MAX_FIELD_SIZE];
	char hometown[MAX_FIELD_SIZE];
	char birthplace[MAX_FIELD_SIZE];
	char liveplace[MAX_FIELD_SIZE];
	char job[MAX_FIELD_SIZE];
	char height[MAX_FIELD_SIZE];
	char weight[MAX_FIELD_SIZE];
	char headimage[MAX_FIELD_SIZE];
	char photowall[MAX_FIELD_SIZE];
	char createtime[MAX_FIELD_SIZE];
	char birthday[MAX_FIELD_SIZE];
	char age[MAX_FIELD_SIZE];
	char follow_people_count[MAX_FIELD_SIZE];
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
