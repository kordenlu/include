/*
 * gate_msg.h
 *
 *  Created on: May 22, 2015
 *      Author: jimm
 */

#ifndef GATE_MSG_H_
#define GATE_MSG_H_

#include "../common/common_codeengine.h"
#include "../frame/frame_impl.h"
#include "typedef.h"
#include <string>
#include <stdio.h>
using namespace std;
using namespace FRAME;

#define MSGID_PING			60101
class CMsgPing : public IMsgBody
{
public:
	CMsgPing()
	{
		m_nUin = 0;
	}

	uint32_t		m_nUin;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nUin);
		if(nRet != 0)
		{
			return nRet;
		}
		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nUin=%u}", m_nUin);
		offset += nLen;
	}
};

#define MSGID_PONG			60102
class CMsgPong : public IMsgBody
{
public:
	CMsgPong()
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

	virtual void Dump(char* pBuf, const uint32_t nBufSize, uint32_t& nOffset)
	{
		uint32_t nLen = sprintf(pBuf + nOffset, ", msgbody={}");
		nOffset += nLen;
	}
};



#endif /* GATE_MSG_H_ */
