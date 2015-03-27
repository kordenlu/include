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

#define REGIST_PHONE_INFO	"regist_phone_info_"
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

#define REGIST_ADDR_INFO		"regist_addr_info_"
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

#define GLOBAL_UIN		"gobal_uin"
class GlobalUin : public IConfig
{
public:
	GlobalUin(const char *pConfigName)
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

#define USER_BASE_INFO		"user_base_info_"
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
		strcpy(mytopic_count, "mytopic_count");
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
	char mytopic_count[MAX_FIELD_SIZE];
	char jointopic_count[MAX_FIELD_SIZE];
};

#define ACCOUNT_INFO			"account_info_"
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
		strcpy(string, "account_info_");
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

#endif /* CACHEKEY_DEFINE_H_ */
