/*
 * msg_head.h
 *
 *  Created on: 2015��02��06��
 *      Author: jimm
 */

#ifndef MSG_HEAD_H_
#define MSG_HEAD_H_

#include "../common/common_typedef.h"
#include "../common/common_codeengine.h"
#include "../frame/frame_impl.h"
#include <stdio.h>

using namespace FRAME;

class MsgHeadCS : public IMsgHead
{
public:
	virtual int32_t GetSize()
	{
		return (sizeof(m_nTotalSize) + sizeof(m_nMsgID) + sizeof(m_nSeq) + sizeof(m_nSrcUin) + sizeof(m_nDstUin));
	}

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nTotalSize);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nMsgID);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nSeq);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nSrcUin);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nDstUin);

		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nTotalSize);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nMsgID);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nSeq);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nSrcUin);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nDstUin);

		return 0;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, "msgheadcs={m_nTotalSize=%d, m_nMsgID=%d, m_nSeq=%u, m_nSrcUin=%u, m_nDstUin=%u}",
				m_nTotalSize, m_nMsgID, m_nSeq, m_nSrcUin, m_nDstUin);
		offset += nLen;
	}

public:
	uint16_t		m_nTotalSize;
	uint16_t		m_nMsgID;
	uint32_t		m_nSeq;
	uint32_t		m_nSrcUin;
	uint32_t		m_nDstUin;
};


#endif /* MSG_HEAD_H_ */
