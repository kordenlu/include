/*
 * typedef.h
 *
 *  Created on: Mar 12, 2015
 *      Author: jimm
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

enum
{
	enmPhoneType_WindowsPhone	= 0x00,
	enmPhoneType_Android		= 0x01,
	enmPhoneType_IPhone			= 0x02,
	enmPhoneType_Unknown		= 0xff,
};


struct ConnInfo
{
	ConnInfo()
	{
		m_nUin = 0;
		m_nPhoneType = enmPhoneType_Unknown;
	}
	uint32_t			m_nUin;
	uint8_t				m_nPhoneType;
};

enum
{
	enmMaxInternetAddrLen		= 128,
};

#define MAX_MSG_SIZE		(64 * 1024 - 1)
#define MAX_CTLHEAD_SIZE	(255)

#endif /* TYPEDEF_H_ */
