/*
 * typedef.h
 *
 *  Created on: Mar 12, 2015
 *      Author: jimm
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

struct ConnInfo
{
	ConnInfo()
	{
		m_nUin = 0;
	}
	uint32_t			m_nUin;
};

enum
{
	enmMaxInternetAddrLen		= 128,
};

#define MAX_MSG_SIZE		(64 * 1024 - 1)
#define MAX_CTLHEAD_SIZE	(255)

#endif /* TYPEDEF_H_ */
