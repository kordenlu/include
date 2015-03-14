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

#define MSGID_AUTHREGISTPHONE_REQ		1
class CAuthRegistPhoneReq : public IMsgBody
{
public:
	CAuthRegistPhoneReq()
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

#define MSGID_AUTHREGISTPHONE_RESP		2
class CAuthRegistPhoneResp : public IMsgBody
{
public:
	CAuthRegistPhoneResp()
	{
		m_nResult = 0;
	}

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
