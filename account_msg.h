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
		uint32_t nLen = sprintf(buf, ", msgbody={m_strPhone=%s}\n", m_strPhone.c_str());
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
		enmResult_Unknown			= 0x04,
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
		uint32_t nLen = sprintf(pBuf, ", msgbody={m_nResult=%d\n", m_nResult);
		nOffset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(pBuf, ", m_strTips=%s", m_strTips.c_str());
			nOffset += nLen;
		}

		nLen = sprintf(pBuf, "}\n");
		nOffset += nLen;
	}
};

#define MSGID_VERIFYAUTHCODE_REQ		4
class CVerifyAuthCodeReq : public IMsgBody
{
public:
	CVerifyAuthCodeReq()
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
		uint32_t nLen = sprintf(buf, ", msgbody={m_strPhone=%s, m_strPassword=%s, m_nAuthCode=%d}\n",
				m_strPhone.c_str(), m_strPassword.c_str(), m_nAuthCode);
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
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_AuthCodeWrong		= 0x01,
		enmResult_AuthCodeExpire	= 0x02,
		enmResult_Unknown			= 0x04,
	};

	uint8_t			m_nResult;
	string			m_strTips;
	uint32_t		m_nUin;

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
		}
		return nRet;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf, ", msgbody={m_nResult=%d\n", m_nResult);
		nOffset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(pBuf, ", m_strTips=%s", m_strTips.c_str());
			nOffset += nLen;
		}
		else
		{
			nLen = sprintf(pBuf, ", m_nUin=%u", m_nUin);
			nOffset += nLen;
		}

		nLen = sprintf(pBuf, "}\n");
		nOffset += nLen;
	}
};


#define MSGID_REGISTBASEINFO_REQ		7
class CRegistBaseInfoReq : public IMsgBody
{
public:
	CRegistBaseInfoReq()
	{
		m_nSex = 0;
	}

	string			m_strHeadImageAddr;
	uint8_t			m_nSex;
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

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nSex);
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
		uint32_t nLen = sprintf(buf, ", msgbody={m_strHeadImageAddr=%s, m_nSex=%d, m_strNickName=%s, m_strBirthday=%s}\n",
				m_strHeadImageAddr.c_str(), m_nSex, m_strNickName.c_str(), m_strBirthday.c_str());
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
		enmResult_Unknown			= 0x04,
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
		uint32_t nLen = sprintf(pBuf, ", msgbody={m_nResult=%d\n", m_nResult);
		nOffset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(pBuf, ", m_strTips=%s", m_strTips.c_str());
			nOffset += nLen;
		}

		nLen = sprintf(pBuf, "}\n");
		nOffset += nLen;
	}
};


#endif /* ACCOUNT_MSG_H_ */
