/*
 * cachechar_define.h
 *
 *  Created on: Mar 9, 2015
 *      Author: jimm
 */

#ifndef CACHEKEY_DEFINE_H_
#define CACHEKEY_DEFINE_H_

#include <string.h>
#include <map>
#include <string>
#include "../frame/frame_impl.h"
using namespace FRAME;

#define MAX_FIELD_SIZE		256

//list
#define CLIENT_RESP				"client:resp"
//list
#define UNHANDLE_USER_LIST		"unhandle:userlist"
//string
#define USER_UNREAD_LOCK		"user:unread:lock:"
//list
#define ACCOUNT_POOL				"account:pool"
//string
#define ACCOUNTID					"accountid:"

//sortedset
#define TOPICS_RECOMMEND			"topics:recommend"
//list
#define TOPICS_LAST					"topics:last"
//list
#define USER_CREATETOPICS			"user:createtopics:"
//list
#define TOPIC_COMMENTS				"topic:comments:"

//hash
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

//hash
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

//hash
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

		strcpy(followers_count, "followers_count");
		m_stFieldPer[followers_count] = 1;

		strcpy(fans_count, "fans_count");
		m_stFieldPer[fans_count] = 1;

		strcpy(friends_count, "friends_count");
		m_stFieldPer[friends_count] = 1;

		strcpy(createtopic_count, "createtopic_count");
		m_stFieldPer[createtopic_count] = 1;

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
	char followers_count[MAX_FIELD_SIZE];
	char fans_count[MAX_FIELD_SIZE];
	char friends_count[MAX_FIELD_SIZE];
	char createtopic_count[MAX_FIELD_SIZE];
	char jointopic_count[MAX_FIELD_SIZE];
};

//hash
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

//hash
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

//hash
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

//list
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

//sortedset
#define USER_FANS				"user:fans:"
class UserFans : public IConfig
{
public:
	UserFans(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		strcpy(uin, "uin");
		strcpy(addtime, "addtime");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}

	char string[MAX_FIELD_SIZE];
	char uin[MAX_FIELD_SIZE];
	char addtime[MAX_FIELD_SIZE];
};

//sortedset
#define USER_FOLLOWERS				"user:followers:"
class UserFollowers : public IConfig
{
public:
	UserFollowers(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		strcpy(uin, "uin");
		strcpy(addtime, "addtime");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}

	char string[MAX_FIELD_SIZE];
	char uin[MAX_FIELD_SIZE];
	char addtime[MAX_FIELD_SIZE];
};

//hash
#define TOPIC_INFO				"topic:info:"
class TopicInfo : public IConfig
{
public:
	TopicInfo(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		strcpy(uin, "uin");
		strcpy(createtime, "createtime");
		strcpy(bgurl, "bgurl");
		strcpy(content, "content");
		strcpy(likecount, "likecount");
		strcpy(floorcount, "floorcount");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}

	char string[MAX_FIELD_SIZE];
	char uin[MAX_FIELD_SIZE];
	char createtime[MAX_FIELD_SIZE];
	char bgurl[MAX_FIELD_SIZE];
	char content[MAX_FIELD_SIZE];
	char likecount[MAX_FIELD_SIZE];
	char floorcount[MAX_FIELD_SIZE];
};

////list
//#define USER_TOPIC_FLOOR			"user:topicfloor:"
//class UserTopicFloor : public IConfig
//{
//public:
//	UserTopicFloor(const char *pConfigName)
//	{
//		strcpy(string, pConfigName);
//	}
//	//初始化配置
//	virtual int32_t Init()
//	{
//		strcpy(uin, "uin");
//
//		strcpy(userdata, "userdata");
//		strcpy(accountid, "accountid");
//		strcpy(nickname, "nickname");
//		strcpy(headimage, "headimage");
//		strcpy(gender, "gender");
//
//		strcpy(commentdata, "commentdata");
//		strcpy(comment, "comment");
//		strcpy(commenttime, "commenttime");
//		strcpy(quotefloorid, "quotefloorid");
//		strcpy(quotenickname, "quotenickname");
//		strcpy(quotefloor, "quotefloor");
//		return 0;
//	}
//	//卸载配置
//	virtual int32_t Uninit()
//	{
//		return 0;
//	}
//
//	char string[MAX_FIELD_SIZE];
//	char uin[MAX_FIELD_SIZE];
//
//	char userdata[MAX_FIELD_SIZE];
//	char accountid[MAX_FIELD_SIZE];
//	char nickname[MAX_FIELD_SIZE];
//	char headimage[MAX_FIELD_SIZE];
//	char gender[MAX_FIELD_SIZE];
//
//	char commentdata[MAX_FIELD_SIZE];
//	char comment[MAX_FIELD_SIZE];
//	char commenttime[MAX_FIELD_SIZE];
//	char quotefloorid[MAX_FIELD_SIZE];
//	char quotenickname[MAX_FIELD_SIZE];
//	char quotefloor[MAX_FIELD_SIZE];
//};

//list
#define USER_JOINTOPICS			"user:jointopics:"
class UserJoinTopics : public IConfig
{
public:
	UserJoinTopics(const char *pConfigName)
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

	char string[MAX_FIELD_SIZE];
};

//list
#define USER_RECVCOMMENTS			"user:recvcomments:"
class UserRecvComments : public IConfig
{
public:
	UserRecvComments(const char *pConfigName)
	{
		strcpy(string, pConfigName);
	}
	//初始化配置
	virtual int32_t Init()
	{
		strcpy(uin, "uin");
		strcpy(topicid, "topicid");			//topicid
		strcpy(type, "type");
		strcpy(comment, "comment");
		return 0;
	}
	//卸载配置
	virtual int32_t Uninit()
	{
		return 0;
	}

	char string[MAX_FIELD_SIZE];
	char uin[MAX_FIELD_SIZE];
	char topicid[MAX_FIELD_SIZE];
	char type[MAX_FIELD_SIZE];
	char comment[MAX_FIELD_SIZE];
};

#endif /* CACHEKEY_DEFINE_H_ */
