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
	enum
	{
		enmChatMsgType_Text		= 0x00,
		enmChatMsgType_Bottle	= 0x01,
		enmChatMsgType_Voice	= 0x02,
		enmChatMsgType_Pic		= 0x03,
	};
	CChatToOneReq()
	{
		m_nChatMsgType = enmChatMsgType_Text;
		m_nCurTime = 0;
	}

	string				m_strSrcHeadImage;
	string				m_strSrcNickName;
	uint8_t				m_nChatMsgType;
	string				m_strChatMsg;
	int32_t				m_nCurTime;

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

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nChatMsgType);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strChatMsg);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nCurTime);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_strSrcHeadImage=%s, m_strSrcNickName=%s, m_nChatMsgType=%d, "
				"m_strChatMsg=%s, m_nCurTime=%ld}",
				m_strSrcHeadImage.c_str(), m_strSrcNickName.c_str(), m_nChatMsgType, m_strChatMsg.c_str(), m_nCurTime);
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

	CChatReadReq()
	{
		m_nReadCount = 0;
	}

	uint16_t					m_nReadCount;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nReadCount);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nReadCount=%d}", m_nReadCount);
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
