/*
 * topic_msg.h
 *
 *  Created on: Apr 26, 2015
 *      Author: jimm
 */

#ifndef TOPIC_MSG_H_
#define TOPIC_MSG_H_

#include "../common/common_codeengine.h"
#include "../frame/frame_impl.h"
#include <string>
#include <stdio.h>
using namespace std;
using namespace FRAME;

#define MSGID_COMMENTTOPIC_REQ		219
class CCommentTopicReq : public IMsgBody
{
public:
	enum
	{
		enmCommentType_Like		= 0x00,
		enmCommentType_Comment	= 0x01,
	};

	CCommentTopicReq()
	{
		m_nTopicID = 0;
		m_nCommentType = enmCommentType_Like;
		m_nDstFloorID = 0;
	}
	string				m_strSrcNickName;
	uint32_t			m_nTopicID;
	uint8_t				m_nCommentType;
	string				m_strComment;
	uint32_t			m_nDstFloorID;
	string				m_strDstAccountID;
	string				m_strDstComment;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strSrcNickName);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nTopicID);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nCommentType);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strComment);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nDstFloorID);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strDstAccountID);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strDstComment);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_strSrcNickName=%s, m_nTopicID=%u, m_nCommentType=%d, m_strComment=%s, "
				"m_nDstFloorID=%u, m_strDstAccountID=%s, m_strDstNickName=%s, m_strDstComment=%s}",
				m_strSrcNickName.c_str(), m_nTopicID, m_nCommentType, m_strComment.c_str(), m_nDstFloorID, m_strDstAccountID.c_str(),
				m_strDstComment.c_str());
		offset += nLen;
	}
};

#define MSGID_COMMENTTOPIC_RESP		220
class CCommentTopicResp : public IMsgBody
{
public:
	CCommentTopicResp()
	{
		m_nResult = 0;
		m_nFloorID = 0;
	}

	enum
	{
		enmResult_OK				= 0x00,
		enmResult_CanNotComment		= 0x01,
		enmResult_Unknown			= 0xff,
	};

	uint8_t			m_nResult;
	string			m_strTips;
	uint32_t		m_nFloorID;

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
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nFloorID);
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
			nLen = sprintf(pBuf + nOffset, ", m_nFloorID=%u", m_nFloorID);
			nOffset += nLen;
		}

		nLen = sprintf(pBuf + nOffset, "}");
		nOffset += nLen;
	}
};


#endif /* TOPIC_MSG_H_ */
