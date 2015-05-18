/*
 * sys_msg.h
 *
 *  Created on: May 14, 2015
 *      Author: jimm
 */

#ifndef SYS_MSG_H_
#define SYS_MSG_H_

#include "../common/common_codeengine.h"
#include "../frame/frame_impl.h"
#include "typedef.h"
#include <string>
#include <stdio.h>
using namespace std;
using namespace FRAME;

#define MSGID_UNREADMSGTIP_NOTI		501
class CUnreadMsgTipNoti : public IMsgBody
{
public:
	enum
	{
		enmUnreadMsgTipType_LookMe				= 0x00,
		enmUnreadMsgTipType_TopicOfFollower		= 0x01,
	};

	CUnreadMsgTipNoti()
	{
		m_nTipType = 0;
	}

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nTipType);
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
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nTipType=%d}", m_nTipType);
		offset += nLen;
	}

	uint8_t			m_nTipType;
};

#endif /* SYS_MSG_H_ */
