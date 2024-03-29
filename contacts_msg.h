/*
 * contacts_msg.h
 *
 *  Created on: Mar 18, 2015
 *      Author: jimm
 */

#ifndef CONTACTS_MSG_H_
#define CONTACTS_MSG_H_

#include "../common/common_codeengine.h"
#include "../frame/frame_impl.h"
#include <string>
#include <stdio.h>
using namespace std;
using namespace FRAME;

#define MSGID_SETUSERINFO_REQ		104
class CSetUserInfoReq : public IMsgBody
{
public:
	enum
	{
		enmMaxUserInfoCount		= 32,
	};

	CSetUserInfoReq()
	{
		m_nCount = 0;
	}

	uint16_t				m_nCount;
	string					m_arrKey[enmMaxUserInfoCount];
	string					m_arrValue[enmMaxUserInfoCount];

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nCount);
		if(nRet != 0)
		{
			return nRet;
		}

		if(m_nCount > enmMaxUserInfoCount)
		{
			m_nCount = enmMaxUserInfoCount;
		}

		for(int32_t i = 0; i < m_nCount; ++i)
		{
			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_arrKey[i]);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_arrValue[i]);
			if(nRet != 0)
			{
				return nRet;
			}
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nCount=%d", m_nCount);
		offset += nLen;

		for(int32_t i = 0; i < m_nCount; ++i)
		{
			nLen = sprintf(buf + offset, "%s=%s, ", m_arrKey[i].c_str(), m_arrValue[i].c_str());
			offset += nLen;
		}

		nLen = sprintf(buf + offset, "}");
		offset += nLen;
	}
};

#define MSGID_SETUSERINFO_RESP		105
class CSetUserInfoResp : public IMsgBody
{
public:
	enum
	{
		enmResult_OK				= 0x00,
		enmResult_CanNotWrite	= 0x01,
		enmResult_Unknown			= 0xff,
	};

	CSetUserInfoResp()
	{
		m_nResult = 0;
		m_nVersion = 0;
	}

	uint8_t					m_nResult;
	string					m_strTips;
	uint32_t				m_nVersion;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nResult);
		if(nRet != 0)
		{
			return nRet;
		}

		if(m_nResult != 0)
		{
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strTips);
			if(nRet != 0)
			{
				return nRet;
			}
		}
		else
		{
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nVersion);
			if(nRet != 0)
			{
				return nRet;
			}
		}

		return nRet;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nResult=%d", m_nResult);
		offset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(buf + offset, ", m_strTips=%s", m_strTips.c_str());
			offset += nLen;
		}
		else
		{
			nLen = sprintf(buf + offset, ", m_nVersion=%u", m_nVersion);
			offset += nLen;
		}
		nLen = sprintf(buf + offset, "}");
		offset += nLen;
	}
};

#define MSGID_GETUSERINFO_REQ		107
class CGetUserInfoReq : public IMsgBody
{
public:
	CGetUserInfoReq()
	{
		m_nVersion = 0;
	}

	uint32_t				m_nVersion;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nVersion);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nVersion=%u}", m_nVersion);
		offset += nLen;
	}
};


#define MSGID_GETUSERINFO_RESP		108
class CGetUserInfoResp : public IMsgBody
{
public:
	enum
	{
		enmResult_OK				= 0x00,
		enmResult_DontNeedUpdate	= 0x01,
		enmResult_LessPrivilege		= 0x02,
		enmResult_Unknown			= 0xff,
	};

	CGetUserInfoResp()
	{
		m_nResult = 0;
		m_nVersion = 0;
		m_nIsFollow = 0;
		m_nUin = 0;
		m_nGender = 0;
		m_nAge = 0;
		m_nFollowersCount = 0;
		m_nFansCount = 0;
		m_nFriendsCount = 0;
		m_nLookMeCount = 0;
		m_nCreateTopicsCount = 0;
		m_nJoinTopicsCount = 0;
		m_nCreateTime = 0;
		m_nFollowBusLineCount = 0;
		m_nRadar = 0;
	}

	uint8_t					m_nResult;
	string					m_strTips;
	uint8_t					m_nIsFollow;
	uint32_t					m_nVersion;
	uint32_t					m_nUin;
	string					m_strAccountID;
	string					m_strNickName;
	string					m_strHeadImage;
	string					m_strOneselfWords;
	uint8_t					m_nGender;
	string					m_strSchool;
	string					m_strHometown;
	string					m_strBirthday;
	uint8_t					m_nAge;
	string					m_strLivePlace;
	string					m_strHeight;
	string					m_strWeight;
	string					m_strJob;
	uint32_t					m_nFollowersCount;
	uint32_t					m_nFansCount;
	uint32_t					m_nFriendsCount;
	uint32_t					m_nLookMeCount;
	uint32_t					m_nCreateTopicsCount;
	uint32_t					m_nJoinTopicsCount;
	string					m_strPhotoWall;
	int32_t					m_nCreateTime;
	uint8_t					m_nFollowBusLineCount;
	uint8_t					m_nRadar;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nResult);
		if(nRet != 0)
		{
			return nRet;
		}

		if(m_nResult == enmResult_OK)
		{
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nIsFollow);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nVersion);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nUin);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strAccountID);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strNickName);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strHeadImage);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strOneselfWords);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nGender);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strSchool);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strHometown);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strBirthday);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nAge);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strLivePlace);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strHeight);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strWeight);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strJob);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nFollowersCount);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nFansCount);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nFriendsCount);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nLookMeCount);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nCreateTopicsCount);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nJoinTopicsCount);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strPhotoWall);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nCreateTime);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nFollowBusLineCount);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nRadar);
			if(nRet != 0)
			{
				return nRet;
			}
		}
		else
		{
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strTips);
			if(nRet != 0)
			{
				return nRet;
			}

			if((m_nResult == enmResult_DontNeedUpdate) || (m_nResult == enmResult_LessPrivilege))
			{
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nIsFollow);
				if(nRet != 0)
				{
					return nRet;
				}

			}
		}

		return nRet;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nResult=%d", m_nResult);
		offset += nLen;

		if(m_nResult == enmResult_DontNeedUpdate)
		{
			nLen = sprintf(buf + offset, ", m_nVersion=%u", m_nVersion);
			offset += nLen;
		}
		else if(m_nResult == enmResult_OK)
		{
			nLen = sprintf(buf + offset, ", m_nVersion=%u, m_nIsFollow=%u, m_nUin=%u, m_strAccountID=%s, m_strNickName=%s, m_strHeadImage=%s, "
					"m_strOneselfWords=%s, m_nGender=%d, m_strSchool=%s, m_strHometown=%s, "
					"m_strBirthday=%s, m_nAge=%d, m_strLivePlace=%s, m_strHeight=%s, m_strWeight=%s, m_strJob=%s, m_nFollowersCount=%u, "
					"m_nFansCount=%u, m_nFriendsCount=%u, m_nLookMeCount=%u, m_nCreateTopicsCount=%u, m_nJoinTopicsCount=%u, m_strPhotoWall=%s, "
					"m_nCreateTime=%d, m_nFollowBusLineCount=%d, m_nRadar=%d",
					m_nVersion, m_nIsFollow, m_nUin, m_strAccountID.c_str(), m_strNickName.c_str(), m_strHeadImage.c_str(), m_strOneselfWords.c_str(),
					m_nGender, m_strSchool.c_str(), m_strHometown.c_str(), m_strBirthday.c_str(),
					m_nAge, m_strLivePlace.c_str(), m_strHeight.c_str(), m_strWeight.c_str(), m_strJob.c_str(), m_nFollowersCount,
					m_nFansCount, m_nFriendsCount, m_nLookMeCount, m_nCreateTopicsCount, m_nJoinTopicsCount, m_strPhotoWall.c_str(),
					m_nCreateTime, m_nFollowBusLineCount, m_nRadar);
			offset += nLen;
		}
		else
		{
			nLen = sprintf(buf + offset, ", m_strTips=%s", m_strTips.c_str());
			offset += nLen;
		}
		nLen = sprintf(buf + offset, "}");
		offset += nLen;
	}
};

#define MSGID_FOLLOWUSER_REQ		113
class CFollowUserReq : public IMsgBody
{
public:
	enum
	{
		enmFollowType_Add			= 0x00,
		enmFollowType_Cancel		= 0x01,
	};
	CFollowUserReq()
	{
		m_nFollowType = enmFollowType_Add;
	}

	uint8_t					m_nFollowType;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nFollowType);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nFollowType=%d}", m_nFollowType);
		offset += nLen;;
	}
};

#define MSGID_FOLLOWUSER_RESP		114
class CFollowUserResp : public IMsgBody
{
public:
	enum
	{
		enmResult_OK				= 0x00,
		enmResult_InBlackList		= 0x01,
		enmResult_Unknown			= 0xff,
	};

	CFollowUserResp()
	{
		m_nResult = enmResult_OK;
	}

	uint8_t					m_nResult;
	string					m_strTips;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nResult);
		if(nRet != 0)
		{
			return nRet;
		}

		if(m_nResult != 0)
		{
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strTips);
			if(nRet != 0)
			{
				return nRet;
			}
		}

		return nRet;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nResult=%d", m_nResult);
		offset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(buf + offset, ", m_strTips=%s", m_strTips.c_str());
			offset += nLen;
		}
		nLen = sprintf(buf + offset, "}");
		offset += nLen;
	}
};

#define MSGID_GETUIN_REQ		126
class CGetUinReq : public IMsgBody
{
public:
	CGetUinReq()
	{
	}

	string				m_strAccountID;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strAccountID);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_strAccountID=%s}", m_strAccountID.c_str());
		offset += nLen;;
	}
};

#define MSGID_GETUIN_RESP		127
class CGetUinResp : public IMsgBody
{
public:
	enum
	{
		enmResult_OK				= 0x00,
		enmResult_USERNOTEXIST		= 0x01,
		enmResult_Unknown			= 0xff,
	};

	CGetUinResp()
	{
		m_nResult = enmResult_OK;
		m_nUin = 0;
		m_nVersion = 0;
	}

	uint8_t					m_nResult;
	string					m_strTips;
	uint32_t				m_nUin;
	uint32_t				m_nVersion;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nResult);
		if(nRet != 0)
		{
			return nRet;
		}

		if(m_nResult != 0)
		{
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strTips);
			if(nRet != 0)
			{
				return nRet;
			}
		}
		else
		{
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nUin);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nVersion);
			if(nRet != 0)
			{
				return nRet;
			}
		}

		return nRet;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nResult=%d", m_nResult);
		offset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(buf + offset, ", m_strTips=%s}", m_strTips.c_str());
			offset += nLen;
		}
		else
		{
			nLen = sprintf(buf + offset, ", m_nUin=%u, m_nVersion=%u}", m_nUin, m_nVersion);
			offset += nLen;
		}
	}
};


#endif /* CONTACTS_MSG_H_ */
