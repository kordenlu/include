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
#include <string>

using namespace std;
using namespace FRAME;

typedef uint8_t		ControlCode;
enum
{
	enmControlCode_Trans		= 0x00,
	enmControlCode_Close		= 0x01,
};

typedef uint8_t		IdentifyType;
enum
{
	enmIdentifyType_Phone		= 0x00,
	enmIdentifyType_Uin			= 0x01,
};

class ControlHead : public ICtlHead
{
public:
	ControlHead()
	{
		m_nTotalSize = 0;
		m_nHeadSize = GetSize();
		m_nControlCode = enmControlCode_Trans;
		m_nIdentifyType = enmIdentifyType_Phone;
		m_nUin = 0;
		m_nSessionID = 0;
		m_nClientAddress = 0;
		m_nClientPort = 0;
	}

	virtual int32_t GetSize()
	{
		return (sizeof(m_nTotalSize) + sizeof(m_nHeadSize) + sizeof(m_nControlCode) + sizeof(m_nIdentifyType) +
				sizeof(m_nUin) + sizeof(m_nSessionID) + sizeof(m_nClientAddress) + sizeof(m_nClientPort));
	}

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nTotalSize);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nHeadSize);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nControlCode);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nIdentifyType);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nUin);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nSessionID);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nClientAddress);
		CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nClientPort);

		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nTotalSize);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nHeadSize);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nControlCode);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nIdentifyType);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nUin);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nSessionID);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nClientAddress);
		CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nClientPort);

		return 0;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf, "controlhead={m_nTotalSize=%d, m_nHeadSize=%d, m_nControlCode=%d, m_nIdentifyType=%d, m_nUin=%u, "
				"m_nSessionID=%u, m_nClientAddress=%s, m_nClientPort=%d}\n", m_nTotalSize, m_nHeadSize, m_nControlCode,
				m_nIdentifyType, m_nUin, m_nSessionID, inet_ntoa_f(m_nClientAddress), m_nClientPort);
		offset += nLen;
	}

	uint16_t			m_nTotalSize;
	uint8_t				m_nHeadSize;
	ControlCode			m_nControlCode;
	IdentifyType		m_nIdentifyType;
	uint32_t			m_nUin;
	SessionID			m_nSessionID;
	uint32_t			m_nClientAddress;
	uint16_t			m_nClientPort;
};


#endif /* CONTROL_HEAD_H_ */
