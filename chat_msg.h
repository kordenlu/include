/*
 * chat_msg.h
 *
 *  Created on: 2015年3月30日
 *      Author: jimm
 */

#ifndef CHAT_MSG_H_
#define CHAT_MSG_H_

#include "../common/common_codeengine.h"
#include "../frame/frame_impl.h"
#include <string>
#include <stdio.h>
using namespace std;
using namespace FRAME;

#define MSGID_CHATTOONE_REQ		601
class CChatToOneReq : public IMsgBody
{
public:
	CChatToOneReq()
	{
	}

	string				m_strSrcHeadImage;
	string				m_strSrcNickName;
	string				m_strChatMsg;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strSrcHeadImage);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strSrcNickName);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strChatMsg);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_strSrcHeadImage=%s, m_strSrcNickName=%s, m_strChatMsg=%s}",
				m_strSrcHeadImage.c_str(), m_strSrcNickName.c_str(), m_strChatMsg.c_str());
		offset += nLen;
	}
};

#define MSGID_CHATTOONE_RESP		602
class CChatToOneResp : public IMsgBody
{
public:
	CChatToOneResp()
	{
		m_nResult = 0;
		m_nAckID = 0;
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_Unknown			= 0xff,
	};

	uint8_t			m_nResult;
	string			m_strTips;
	uint32_t			m_nAckID;

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
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nAckID);
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
			nLen = sprintf(pBuf + nOffset, ", m_nAckID=%u", m_nAckID);
			nOffset += nLen;
		}

		nLen = sprintf(pBuf + nOffset, "}");
		nOffset += nLen;
	}
};

#define MSGID_CHATREAD_REQ		604
class CChatReadReq : public IMsgBody
{
public:
	enum
	{
		enmMaxCount			= 100,
	};

	CChatReadReq()
	{
		m_nAckCount = 0;
	}

	uint16_t					m_nAckCount;
	uint32_t					m_arrAckID[enmMaxCount];

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nAckCount);
		if(nRet != 0)
		{
			return nRet;
		}

		if(m_nAckCount > enmMaxCount)
		{
			m_nAckCount = enmMaxCount;
		}

		for(int32_t i = 0; i < m_nAckCount; ++i)
		{
			nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_arrAckID[i]);
			if(nRet != 0)
			{
				return nRet;
			}
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nAckCount=%d, m_arrAckID={", m_nAckCount);
		offset += nLen;

		for(int32_t i = 0; i < m_nAckCount; ++i)
		{
			nLen = sprintf(buf + offset, "%u, ", m_arrAckID[i]);
			offset += nLen;
		}

		nLen = sprintf(buf + offset, "}");
		offset += nLen;
	}
};

#define MSGID_CHATREAD_RESP		605
class CChatReadResp : public IMsgBody
{
public:
	CChatReadResp()
	{
		m_nResult = 0;
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_Unknown			= 0xff,
	};

	uint8_t			m_nResult;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nResult);
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
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={m_nResult=%d}", m_nResult);
		nOffset += nLen;
	}
};


#endif /* CHAT_MSG_H_ */
