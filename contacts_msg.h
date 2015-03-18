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
		enmResult_Unknown			= 0xff,
	};

	CSetUserInfoResp()
	{
		m_nResult = 0;
	}

	uint8_t					m_nResult;
	string					m_strTips;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nResult);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
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
		enmResult_LessPrivilege		= 0x01,
		enmResult_Unknown			= 0xff,
	};

	CGetUserInfoResp()
	{
		m_nResult = 0;
		m_nVersion = 0;
		m_nAge = 0;
		m_nHeight = 0;
		m_nWeight = 0;
	}

	uint8_t					m_nResult;
	string					m_strTips;
	uint32_t				m_nVersion;
	string					m_strOneselfWords;
	string					m_strSchool;
	string					m_strHometown;
	string					m_strBirthPlace;
	string					m_strLivePlace;
	string					m_strJob;
	uint8_t					m_nAge;
	uint8_t					m_nHeight;
	uint8_t					m_nWeight;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nResult);
		if(nRet != 0)
		{
			return nRet;
		}

		if(m_nResult != enmResult_OK)
		{
			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strTips);
			if(nRet != 0)
			{
				return nRet;
			}
		}
		else
		{
			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strOneselfWords);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strSchool);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strHometown);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strBirthPlace);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nAge);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strLivePlace);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nHeight);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nWeight);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strJob);
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
			nLen = sprintf(buf + offset, ", m_strOneselfWords=%s, m_strSchool=%s, m_strHometown=%s, m_strBirthPlace=%s, "
					"m_nAge=%d, m_strLivePlace=%s, m_nHeight=%d, m_nWeight=%d, m_strJob=%s",
					m_strOneselfWords.c_str(), m_strSchool.c_str(), m_strHometown.c_str(), m_strBirthPlace.c_str(),
					m_nAge, m_strLivePlace.c_str(), m_nHeight, m_nWeight, m_strJob.c_str());
			offset += nLen;
		}
		nLen = sprintf(buf + offset, "}");
		offset += nLen;
	}
};

#endif /* CONTACTS_MSG_H_ */
