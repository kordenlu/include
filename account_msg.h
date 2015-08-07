/*
 * account_msg.h
 *
 *  Created on: Mar 9, 2015
 *      Author: jimm
 */

#ifndef ACCOUNT_MSG_H_
#define ACCOUNT_MSG_H_

#include "../common/common_codeengine.h"
#include "../frame/frame_impl.h"
#include "typedef.h"
#include <string>
#include <stdio.h>
using namespace std;
using namespace FRAME;

#define MSGID_REQUESTAUTH_REQ		1
class CRequestAuthReq : public IMsgBody
{
public:
	CRequestAuthReq()
	{
	}

	string			m_strPhone;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strPhone);
		if(nRet != 0)
		{
			return nRet;
		}
		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_strPhone=%s}", m_strPhone.c_str());
		offset += nLen;
	}
};

#define MSGID_REQUESTAUTH_RESP		2
class CRequestAuthResp : public IMsgBody
{
public:
	CRequestAuthResp()
	{
		m_nResult = 0;
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_PhoneAuthLimit	= 0x01,
		enmResult_AccountExist		= 0x02,
		enmResult_AddrAuthLimit		= 0x03,
		enmResult_Unknown			= 0xff,
	};

	uint8_t			m_nResult;
	string			m_strTips;

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

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={m_nResult=%d", m_nResult);
		nOffset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(pBuf + nOffset, ", m_strTips=%s", m_strTips.c_str());
			nOffset += nLen;
		}

		nLen = sprintf(pBuf + nOffset, "}");
		nOffset += nLen;
	}
};

#define MSGID_VERIFYAUTHCODE_REQ		4
class CVerifyAuthCodeReq : public IMsgBody
{
public:
	CVerifyAuthCodeReq()
	{
		m_nPhoneType = 0;
		m_nAuthCode = 0;
	}

	uint8_t			m_nPhoneType;
	string			m_strPhone;
	string			m_strPassword;
	int32_t			m_nAuthCode;
	string			m_strOSVer;
	string			m_strPhoneStyle;
	string			m_strDeviceToken;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nPhoneType);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strPhone);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strPassword);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nAuthCode);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strOSVer);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strPhoneStyle);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nPhoneType=%d, m_strPhone=%s, m_strPassword=%s, m_nAuthCode=%d, "
				"m_strOSVer=%s, m_strPhoneStyle=%s}",
				m_nPhoneType, m_strPhone.c_str(), m_strPassword.c_str(), m_nAuthCode, m_strOSVer.c_str(), m_strPhoneStyle.c_str());
		offset += nLen;
	}
};

#define MSGID_VERIFYAUTHCODE_RESP		5
class CVerifyAuthCodeResp : public IMsgBody
{
public:
	CVerifyAuthCodeResp()
	{
		m_nResult = 0;
		m_nUin = 0;
		m_nServerTime = 0;
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_AuthCodeWrong		= 0x01,
		enmResult_AuthCodeExpire	= 0x02,
		enmResult_Unknown			= 0xff,
	};

	uint8_t			m_nResult;
	string			m_strTips;
	uint32_t			m_nUin;
	string			m_strAccountID;
	string			m_strTokenKey;
	string			m_strDataKey;
	string			m_strRC4Key;
	uint32_t		m_nServerTime;

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

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strAccountID);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strTokenKey);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strDataKey);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strRC4Key);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nServerTime);
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

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={m_nResult=%d", m_nResult);
		nOffset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(pBuf + nOffset, ", m_strTips=%s", m_strTips.c_str());
			nOffset += nLen;
		}
		else
		{
			nLen = sprintf(pBuf + nOffset, ", m_nUin=%u, m_strAccountID=%s, m_strTokenKey=%s, m_strDataKey=%s, m_strRC4Key=%s, "
					"m_nServerTime=%u",
					m_nUin, m_strAccountID.c_str(), m_strTokenKey.c_str(), m_strDataKey.c_str(), m_strRC4Key.c_str(), m_nServerTime);
			nOffset += nLen;
		}

		nLen = sprintf(pBuf + nOffset, "}");
		nOffset += nLen;
	}
};


#define MSGID_REGISTBASEINFO_REQ		7
class CRegistBaseInfoReq : public IMsgBody
{
public:
	CRegistBaseInfoReq()
	{
		m_nGender = 0;
	}

	string			m_strHeadImageAddr;
	uint8_t			m_nGender;
	string			m_strNickName;
	string			m_strBirthday;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strHeadImageAddr);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nGender);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strNickName);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strBirthday);
		if(nRet != 0)
		{
			return nRet;
		}
		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_strHeadImageAddr=%s, m_nGender=%d, m_strNickName=%s, m_strBirthday=%s}",
				m_strHeadImageAddr.c_str(), m_nGender, m_strNickName.c_str(), m_strBirthday.c_str());
		offset += nLen;
	}
};

#define MSGID_REGISTBASEINFO_RESP		8
class CRegistBaseInfoResp : public IMsgBody
{
public:
	CRegistBaseInfoResp()
	{
		m_nResult = 0;
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_RegistInfoWrong	= 0x01,
		enmResult_Unknown			= 0xff,
	};

	uint8_t			m_nResult;
	string			m_strTips;

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

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={m_nResult=%d", m_nResult);
		nOffset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(pBuf + nOffset, ", m_strTips=%s", m_strTips.c_str());
			nOffset += nLen;
		}

		nLen = sprintf(pBuf + nOffset, "}");
		nOffset += nLen;
	}
};

#define MSGID_USERLOGIN_REQ		10
class CUserLoginReq : public IMsgBody
{
public:
	CUserLoginReq()
	{
		m_nPhoneType = 0;
	}

	uint8_t			m_nPhoneType;
	string			m_strAccountName;
	string			m_strPassword;
	string			m_strOSVer;
	string			m_strPhoneStyle;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nPhoneType);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strAccountName);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strPassword);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strOSVer);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strPhoneStyle);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nPhoneType=%d, m_strAccountName=%s, m_strPassword=%s, m_strOSVer=%s, "
				"m_strPhoneStyle=%s}",
				m_nPhoneType, m_strAccountName.c_str(), m_strPassword.c_str(), m_strOSVer.c_str(), m_strPhoneStyle.c_str());
		offset += nLen;
	}
};

#define MSGID_USERLOGIN_RESP		11
class CUserLoginResp : public IMsgBody
{
public:
	CUserLoginResp()
	{
		m_nResult = 0;
		m_nUin = 0;
		m_nGender = 0;
		m_nSelfInfoVersion = 0;
		m_nFollowersCount = 0;
		m_nFansCount = 0;
		m_nFriendsCount = 0;
		m_nLookMeCount = 0;
		m_nCreateTopicsCount = 0;
		m_nJoinTopicsCount = 0;
		m_nFollowBuslineCount = 0;
		m_nServerTime = 0;
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_LoginWrong		= 0x01,
		enmResult_AccountLocked		= 0x02,
		enmResult_NotExist			= 0x03,
		enmResult_Unknown			= 0xff,
	};
	uint8_t			m_nResult;
	string			m_strTips;
	uint32_t			m_nUin;
	string			m_strAccountID;
	string			m_strNickName;
	uint8_t			m_nGender;
	string			m_strHeadImageAddr;
	uint32_t			m_nSelfInfoVersion;
	uint32_t		m_nFollowersCount;
	uint32_t		m_nFansCount;
	uint32_t		m_nFriendsCount;
	uint32_t		m_nLookMeCount;
	uint32_t		m_nCreateTopicsCount;
	uint32_t		m_nJoinTopicsCount;
	string			m_strTokenKey;
	string			m_strDataKey;
	uint8_t			m_nFollowBuslineCount;
	string			m_strRC4Key;
	uint32_t		m_nServerTime;

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

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nGender);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strHeadImageAddr);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nSelfInfoVersion);
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

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strTokenKey);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strDataKey);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nFollowBuslineCount);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strRC4Key);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nServerTime);
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

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={m_nResult=%d", m_nResult);
		nOffset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(pBuf + nOffset, ", m_strTips=%s", m_strTips.c_str());
			nOffset += nLen;
		}
		else
		{
			nLen = sprintf(pBuf + nOffset, ", m_nUin=%u, m_strAccountID=%s, m_strNickName=%s, m_nGender=%d, m_strHeadImageAddr=%s, "
					"m_nSelfInfoVersion=%u, m_nFollowersCount=%u, m_nFansCount=%u, m_nFriendsCount=%u, m_nLookMeCount=%u, "
					"m_nCreateTopicsCount=%u, m_nJoinTopicsCount=%u, m_strTokenKey=%s, m_strDataKey=%s, m_nFollowBuslineCount=%d, "
					"m_strRC4Key=%s, m_nServerTime=%u",
					m_nUin, m_strAccountID.c_str(), m_strNickName.c_str(), m_nGender, m_strHeadImageAddr.c_str(), m_nSelfInfoVersion,
					m_nFollowersCount, m_nFansCount, m_nFriendsCount, m_nLookMeCount, m_nCreateTopicsCount, m_nJoinTopicsCount,
					m_strTokenKey.c_str(), m_strDataKey.c_str(), m_nFollowBuslineCount, m_strRC4Key.c_str(), m_nServerTime);
			nOffset += nLen;
		}

		nLen = sprintf(pBuf + nOffset, "}");
		nOffset += nLen;
	}
};

#define MSGID_RESETPASSWORD_REQ		13
class CResetPasswordReq : public IMsgBody
{
public:
	CResetPasswordReq()
	{
	}

	string			m_strPhone;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strPhone);
		if(nRet != 0)
		{
			return nRet;
		}
		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_strPhone=%s}", m_strPhone.c_str());
		offset += nLen;
	}
};

#define MSGID_RESETPASSWORD_RESP		14
class CResetPasswordResp : public IMsgBody
{
public:
	CResetPasswordResp()
	{
		m_nResult = 0;
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_PhoneAuthLimit	= 0x01,
		enmResult_AccountNotExist	= 0x02,
		enmResult_Unknown			= 0xff,
	};

	uint8_t			m_nResult;
	string			m_strTips;

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

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={m_nResult=%d", m_nResult);
		nOffset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(pBuf + nOffset, ", m_strTips=%s", m_strTips.c_str());
			nOffset += nLen;
		}

		nLen = sprintf(pBuf + nOffset, "}");
		nOffset += nLen;
	}
};

#define MSGID_VERIFYRESETPW_REQ		16
class CVerifyResetPWReq : public IMsgBody
{
public:
	CVerifyResetPWReq()
	{
		m_nAuthCode = 0;
	}

	string			m_strPhone;
	string			m_strPassword;
	int32_t			m_nAuthCode;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strPhone);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strPassword);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nAuthCode);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_strPhone=%s, m_strPassword=%s, m_nAuthCode=%d}",
				m_strPhone.c_str(), m_strPassword.c_str(), m_nAuthCode);
		offset += nLen;
	}
};

#define MSGID_VERIFYRESETPW_RESP		17
class CVerifyResetPWResp : public IMsgBody
{
public:
	CVerifyResetPWResp()
	{
		m_nResult = 0;
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_AuthCodeWrong		= 0x01,
		enmResult_AuthCodeExpire	= 0x02,
		enmResult_Unknown			= 0xff,
	};

	uint8_t			m_nResult;
	string			m_strTips;

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

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={m_nResult=%d", m_nResult);
		nOffset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(pBuf + nOffset, ", m_strTips=%s", m_strTips.c_str());
			nOffset += nLen;
		}

		nLen = sprintf(pBuf + nOffset, "}");
		nOffset += nLen;
	}
};

#define MSGID_KICKUSER_NOTI		21
class CKickUserNoti : public IMsgBody
{
public:
	CKickUserNoti()
	{
	}

	string			m_strReason;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strReason);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={m_strReason=%s}", m_strReason.c_str());
		nOffset += nLen;
	}
};

#define MSGID_MODIFYPASSWORD_REQ		25
class CModifyPasswordReq : public IMsgBody
{
public:
	CModifyPasswordReq()
	{
	}

	string			m_strCurPassword;
	string			m_strNewPassword;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strCurPassword);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strNewPassword);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_strCurPassword=%s, m_strNewPassword=%s}",
				m_strCurPassword.c_str(), m_strNewPassword.c_str());
		offset += nLen;
	}
};

#define MSGID_MODIFYPASSWORD_RESP		26
class CModifyPasswordResp : public IMsgBody
{
public:
	CModifyPasswordResp()
	{
		m_nResult = 0;
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_CurPasswordWrong	= 0x01,
		enmResult_Unknown			= 0xff,
	};

	uint8_t			m_nResult;
	string			m_strTips;

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

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={m_nResult=%d", m_nResult);
		nOffset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(pBuf + nOffset, ", m_strTips=%s", m_strTips.c_str());
			nOffset += nLen;
		}

		nLen = sprintf(pBuf + nOffset, "}");
		nOffset += nLen;
	}
};


#define MSGID_UPDATEDEVICETOKEN_REQ		28
class CUpdateDeviceTokenReq : public IMsgBody
{
public:
	CUpdateDeviceTokenReq()
	{
	}

	string			m_strDeviceToken;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strDeviceToken);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={m_strDeviceToken=%s}", m_strDeviceToken.c_str());
		nOffset += nLen;
	}
};

#endif /* ACCOUNT_MSG_H_ */
