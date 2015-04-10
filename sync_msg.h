/*
 * sync_msg.h
 *
 *  Created on: 2015年3月31日
 *      Author: jimm
 */

#ifndef SYNC_MSG_H_
#define SYNC_MSG_H_

#include "../common/common_codeengine.h"
#include "../frame/frame_impl.h"
#include "typedef.h"
#include <string>
#include <stdio.h>
using namespace std;
using namespace FRAME;

#define MSGID_STATUSSYNC_NOTI		60200
class CStatusSyncNoti : public IMsgBody
{
public:
	CStatusSyncNoti()
	{
	}

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={}");
		offset += nLen;
	}
};

#define MSGID_MSGSYNC_REQ		60201
class CMsgSyncReq : public IMsgBody
{
public:
	CMsgSyncReq()
	{
		m_nSyncSeq = 0;
	}

	uint32_t				m_nSyncSeq;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nSyncSeq);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nSyncSeq=%u}", m_nSyncSeq);
		offset += nLen;
	}
};

#define MSGID_MSGPUSH_NOTI		60202
class CMsgPushNoti : public IMsgBody
{
public:
	CMsgPushNoti()
	{
		m_nSyncFlag = enmSyncFlag_Sync;
		m_nSyncSeq = 0;
		m_nMsgSize = 0;
	}

	enum
	{
		enmSyncFlag_Sync		= 0x00,
		enmSyncFlag_Fin		= 0x01,
	};

	typedef uint8_t SyncFlag;

	SyncFlag				m_nSyncFlag;
	uint32_t				m_nSyncSeq;
	uint16_t				m_nMsgSize;
	uint8_t				m_arrMsg[MAX_MSG_SIZE];

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nSyncFlag);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nSyncSeq);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nMsgSize);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrMsg, m_nMsgSize, m_nMsgSize);
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

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nSyncFlag=%d, m_nSyncSeq=%u, m_nMsgSize=%d}", m_nSyncFlag, m_nSyncSeq, m_nMsgSize);
		offset += nLen;
	}
};

#define MSGID_MSGFINACK_REQ		60203
class CMsgFinAckReq : public IMsgBody
{
public:
	CMsgFinAckReq()
	{
		m_nSyncCount = 0;
		m_nSyncSeq = 0;
	}

	int32_t				m_nSyncCount;
	uint32_t				m_nSyncSeq;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nSyncCount);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nSyncSeq);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nSyncCount=%d, m_nSyncSeq=%u}", m_nSyncCount, m_nSyncSeq);
		offset += nLen;
	}
};

#define MSGID_MSGFINACK_RESP		60204
class CMsgFinAckResp : public IMsgBody
{
public:
	CMsgFinAckResp()
	{
		m_nSyncSeq = 0;
	}

	uint32_t				m_nSyncSeq;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nSyncSeq);
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

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nSyncSeq=%u}", m_nSyncSeq);
		offset += nLen;
	}
};


#endif /* SYNC_MSG_H_ */
