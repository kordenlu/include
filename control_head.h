/*
 * control_head.h
 *
 *  Created on: Mar 11, 2015
 *      Author: jimm
 */

#ifndef CONTROL_HEAD_H_
#define CONTROL_HEAD_H_

#include "../common/common_typedef.h"
#include "../common/common_codeengine.h"
#include "../common/common_api.h"
#include "../frame/frame_impl.h"
#include "../netevent/net_typedef.h"
#include "typedef.h"
#include <string>

using namespace std;
using namespace FRAME;

typedef uint8_t		ControlCode;
enum
{
	enmControlCode_Trans		= 0x00,
	enmControlCode_Close		= 0x01,
};


class ControlHead : public ICtlHead
{
public:
	ControlHead()
	{
		m_nTotalSize = 0;
		m_nHeadSize = GetSize();
		m_nControlCode = enmControlCode_Trans;
		m_nUin = 0;
		m_nSessionID = 0;
		m_nClientAddress = 0;
		m_nClientPort = 0;
		m_nGateID = 0;
		m_nTimeStamp = 0;
		m_nPhoneType = 0;
		m_nGateRedisAddress = 0;
		m_nGateRedisPort = 0;
	}

	virtual int32_t GetSize()
	{
		return (sizeof(m_nTotalSize) + sizeof(m_nHeadSize) + sizeof(m_nControlCode) +
				sizeof(m_nUin) + sizeof(m_nSessionID) + sizeof(m_nClientAddress) + sizeof(m_nClientPort) +
				sizeof(m_nGateID) + sizeof(m_nTimeStamp) + sizeof(m_nPhoneType) + sizeof(m_nGateRedisAddress) + sizeof(m_nGateRedisPort));
	}

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nTotalSize);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nHeadSize);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nControlCode);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nUin);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nSessionID);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nClientAddress);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nClientPort);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nGateID);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nTimeStamp);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nPhoneType);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nGateRedisAddress);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nGateRedisPort);

		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nTotalSize);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nHeadSize);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nControlCode);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nUin);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nSessionID);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nClientAddress);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nClientPort);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nGateID);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nTimeStamp);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nPhoneType);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nGateRedisAddress);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nGateRedisPort);

		return 0;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, "controlhead={m_nTotalSize=%d, m_nHeadSize=%d, m_nControlCode=%d, m_nUin=%u, "
				"m_nSessionID=%u, m_nClientAddress=%s, m_nClientPort=%d, m_nGateID=%d, m_nTimeStamp=%ld, m_nPhoneType=%d, ", m_nTotalSize,
				m_nHeadSize, m_nControlCode, m_nUin, m_nSessionID, inet_ntoa_f(m_nClientAddress), m_nClientPort, m_nGateID, m_nTimeStamp,
				m_nPhoneType);
		offset += nLen;

		nLen = sprintf(buf + offset, "m_nGateRedisAddress=%s, m_nGateRedisPort=%d}", inet_ntoa_f(m_nGateRedisAddress), m_nGateRedisPort);
		offset += nLen;
	}

	uint16_t			m_nTotalSize;
	uint8_t				m_nHeadSize;
	ControlCode			m_nControlCode;
	uint32_t			m_nUin;
	SessionID			m_nSessionID;
	uint32_t			m_nClientAddress;
	uint16_t			m_nClientPort;
	uint16_t			m_nGateID;
	int64_t				m_nTimeStamp;
	uint8_t				m_nPhoneType;
	uint32_t			m_nGateRedisAddress;
	uint16_t			m_nGateRedisPort;
};


#endif /* CONTROL_HEAD_H_ */
