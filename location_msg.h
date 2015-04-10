/*
 * location_msg.h
 *
 *  Created on: Mar 19, 2015
 *      Author: jimm
 */

#ifndef LOCATION_MSG_H_
#define LOCATION_MSG_H_

#include "../common/common_codeengine.h"
#include "../frame/frame_impl.h"
#include <string>
#include <stdio.h>
using namespace std;
using namespace FRAME;

#define MSGID_GETNEARSTATION_REQ		401
class CGetNearStationReq : public IMsgBody
{
public:

	CGetNearStationReq()
	{
		m_nLongitude = 0;
		m_nLatitude = 0;
	}

	int64_t				m_nLongitude;
	int64_t				m_nLatitude;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nLongitude);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nLatitude);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nLongitude=%ld, m_nLatitude=%ld}", m_nLongitude, m_nLatitude);
		offset += nLen;
	}
};

#define MSGID_GETNEARSTATION_RESP		402
class CGetNearStationResp : public IMsgBody
{
public:
	enum
	{
		enmResult_OK				= 0x00,
		enmResult_Unknown			= 0xff,
	};

	class BusLineBaseInfo
	{
	public:
		string				m_strBusLineName;
		string				m_strStartStation;
		string				m_strEndStation;
		string				m_strBusLineID;
	};

	enum
	{
		enmMaxStationCount		= 100,
		enmMaxBusLineCount		= 100,
	};

	class StationInfo
	{
	public:
		string				m_strStationName;
		uint8_t				m_nBusLineCount;
		BusLineBaseInfo		m_arrBusInfo[enmMaxBusLineCount];
	};

	CGetNearStationResp()
	{
		m_nResult = 0;
		m_nStationCount = 0;
	}

	uint8_t					m_nResult;
	string					m_strTips;
	uint8_t					m_nStationCount;
	StationInfo				m_arrStationInfo[enmMaxStationCount];

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
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nStationCount);
			if(nRet != 0)
			{
				return nRet;
			}

			for(int32_t i = 0; i < m_nStationCount; ++i)
			{
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrStationInfo[i].m_strStationName);
				if(nRet != 0)
				{
					return nRet;
				}

				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrStationInfo[i].m_nBusLineCount);
				if(nRet != 0)
				{
					return nRet;
				}

				for(int32_t j = 0; j < m_arrStationInfo[i].m_nBusLineCount; ++j)
				{
					nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrStationInfo[i].m_arrBusInfo[j].m_strBusLineName);
					if(nRet != 0)
					{
						return nRet;
					}

					nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrStationInfo[i].m_arrBusInfo[j].m_strStartStation);
					if(nRet != 0)
					{
						return nRet;
					}

					nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrStationInfo[i].m_arrBusInfo[j].m_strEndStation);
					if(nRet != 0)
					{
						return nRet;
					}

					nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrStationInfo[i].m_arrBusInfo[j].m_strBusLineID);
					if(nRet != 0)
					{
						return nRet;
					}
				}
			}
		}

		return nRet;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nResult=%d", m_nResult);
		offset += nLen;

		if(m_nResult != 0)
		{
			nLen = sprintf(buf + offset, ", m_strTips=%s", m_strTips.c_str());
			offset += nLen;
		}
		else
		{
			nLen = sprintf(buf + offset, ", {m_nStationCount=%d", m_nStationCount);
			offset += nLen;

			for(int32_t i = 0; i < m_arrStationInfo[i].m_nBusLineCount; ++i)
			{
				nLen = sprintf(buf + offset, ", m_arrStationInfo[%d].m_strStationName=%s, m_arrStationInfo[%d].m_nBusLineCount=%d, {",
						i, m_arrStationInfo[i].m_strStationName.c_str(), i, m_arrStationInfo[i].m_nBusLineCount);
				offset += nLen;

				for(int32_t j = 0; j < m_arrStationInfo[i].m_nBusLineCount; ++j)
				{
					nLen = sprintf(buf + offset, "m_strBusLineName[%d]=%s, m_strStartStation[%d]=%s, m_strEndStation[%d]=%s, "
							"m_strBusLineID[%d]=%s, ",
							j, m_arrStationInfo[i].m_arrBusInfo[j].m_strBusLineName.c_str(), j, m_arrStationInfo[i].m_arrBusInfo[j].m_strStartStation.c_str(),
							j, m_arrStationInfo[i].m_arrBusInfo[j].m_strEndStation.c_str(), j, m_arrStationInfo[i].m_arrBusInfo[j].m_strBusLineID.c_str());
					offset += nLen;
				}

				nLen = sprintf(buf + offset, "}");
				offset += nLen;
			}

			nLen = sprintf(buf + offset, "}");
			offset += nLen;
		}
		nLen = sprintf(buf + offset, "}");
		offset += nLen;
	}
};

#define MSGID_GETSTATIONUSERLIST_REQ		404
class CGetStationUserListReq : public IMsgBody
{
public:

	CGetStationUserListReq()
	{
		m_nMinDistance = 0;
		m_nReqCount = 0;
	}

	string			m_strBusLineID;
	string			m_strStationName;
	uint32_t			m_nMinDistance;
	uint8_t			m_nReqCount;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strBusLineID);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_strStationName);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nMinDistance);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nReqCount);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_strBusLineID=%s, m_strStationName=%s, m_nMinDistance=%u, m_nReqCount=%d}",
				m_strBusLineID.c_str(), m_strStationName.c_str(), m_nMinDistance, m_nReqCount);
		offset += nLen;
	}
};

#define MSGID_GETSTATIONUSERLIST_RESP		405
class CGetStationUserListResp : public IMsgBody
{
public:
	enum
	{
		enmResult_OK				= 0x00,
		enmResult_Unknown			= 0xff,
	};

	enum
	{
		enmMaxUserCount			= 100,
	};

	class UserSimpleInfo
	{
	public:
		UserSimpleInfo()
		{
			m_nUin = 0;
			m_nAge = 0;
			m_nGender = 0;
			m_nDistance = 0;
		}

		uint32_t				m_nUin;
		string				m_strNickName;
		uint8_t				m_nAge;
		uint8_t				m_nGender;
		string				m_strHeadImageAddr;
		string				m_strOneselfWords;
		int32_t				m_nDistance;
	};

	CGetStationUserListResp()
	{
		m_nResult = 0;
		m_nUserCount = 0;
		m_nNearUserCount = 0;
	}

	uint8_t					m_nResult;
	string					m_strTips;
	string					m_strPrevStation;
	string					m_strNextStation;
	uint16_t					m_nUserCount;
	UserSimpleInfo			m_arrUserSimpleInfo[enmMaxUserCount];
	uint16_t					m_nNearUserCount;
	UserSimpleInfo			m_arrNearUserSimpleInfo[enmMaxUserCount];

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nResult);
		if(nRet != 0)
		{
			return nRet;
		}

		if(m_nResult != enmResult_OK)
		{
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strTips);
			if(nRet != 0)
			{
				return nRet;
			}
		}
		else
		{
			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strPrevStation);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_strNextStation);
			if(nRet != 0)
			{
				return nRet;
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nUserCount);
			if(nRet != 0)
			{
				return nRet;
			}

			if(m_nUserCount > enmMaxUserCount)
			{
				m_nUserCount = enmMaxUserCount;
			}

			for(int32_t i = 0; i < m_nUserCount; ++i)
			{
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrUserSimpleInfo[i].m_nUin);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrUserSimpleInfo[i].m_strNickName);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrUserSimpleInfo[i].m_nGender);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrUserSimpleInfo[i].m_nAge);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrUserSimpleInfo[i].m_strHeadImageAddr);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrUserSimpleInfo[i].m_strOneselfWords);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrUserSimpleInfo[i].m_nDistance);
				if(nRet != 0)
				{
					return nRet;
				}
			}

			nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_nNearUserCount);
			if(nRet != 0)
			{
				return nRet;
			}

			if(m_nNearUserCount > enmMaxUserCount)
			{
				m_nNearUserCount = enmMaxUserCount;
			}

			for(int32_t i = 0; i < m_nNearUserCount; ++i)
			{
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrNearUserSimpleInfo[i].m_nUin);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrNearUserSimpleInfo[i].m_strNickName);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrNearUserSimpleInfo[i].m_nGender);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrNearUserSimpleInfo[i].m_nAge);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrNearUserSimpleInfo[i].m_strHeadImageAddr);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrNearUserSimpleInfo[i].m_strOneselfWords);
				if(nRet != 0)
				{
					return nRet;
				}
				nRet = CCodeEngine::Encode(pBuf, nBufSize, nOffset, m_arrNearUserSimpleInfo[i].m_nDistance);
				if(nRet != 0)
				{
					return nRet;
				}
			}
		}

		return nRet;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nResult=%d", m_nResult);
		offset += nLen;

		if(m_nResult != enmResult_OK)
		{
			nLen = sprintf(buf + offset, ", m_strTips=%s}", m_strTips.c_str());
			offset += nLen;
		}
		else
		{
			nLen = sprintf(buf + offset, ", m_strPrevStation=%s, m_strNextStation=%s, m_nUserCount=%d, usersimpleinfo={",
					m_strPrevStation.c_str(), m_strNextStation.c_str(), m_nUserCount);
			offset += nLen;

			for(int32_t i = 0; i < m_nUserCount; ++i)
			{
				nLen = sprintf(buf + offset, "[index=%d]{m_nUin=%u, m_strNickName=%s, m_nGender=%d, m_nAge=%d, m_strHeadImageAddr=%s, "
						"m_strOneselfWords=%s, m_nDistance=%d}, ", i, m_arrUserSimpleInfo[i].m_nUin, m_arrUserSimpleInfo[i].m_strNickName.c_str(),
						m_arrUserSimpleInfo[i].m_nGender, m_arrUserSimpleInfo[i].m_nAge, m_arrUserSimpleInfo[i].m_strHeadImageAddr.c_str(),
						m_arrUserSimpleInfo[i].m_strOneselfWords.c_str(), m_arrUserSimpleInfo[i].m_nDistance);
				offset += nLen;
			}

			nLen = sprintf(buf + offset, "}, m_nNearUserCount=%d, nearusersimpleinfo={", m_nNearUserCount);
			offset += nLen;

			for(int32_t i = 0; i < m_nNearUserCount; ++i)
			{
				nLen = sprintf(buf + offset, "[index=%d]{m_nUin=%u, m_strNickName=%s, m_nGender=%d, m_nAge=%d, m_strHeadImageAddr=%s,"
						"m_strOneselfWords=%s, m_nDistance=%d}, ", i, m_arrNearUserSimpleInfo[i].m_nUin, m_arrNearUserSimpleInfo[i].m_strNickName.c_str(),
						m_arrNearUserSimpleInfo[i].m_nGender, m_arrNearUserSimpleInfo[i].m_nAge, m_arrNearUserSimpleInfo[i].m_strHeadImageAddr.c_str(),
						m_arrNearUserSimpleInfo[i].m_strOneselfWords.c_str(), m_arrNearUserSimpleInfo[i].m_nDistance);
				offset += nLen;
			}

			nLen = sprintf(buf + offset, "}}");
			offset += nLen;
		}
	}
};

#define MSGID_UPDATECOORD_REQ		416
class CUpdateCoordReq : public IMsgBody
{
public:

	CUpdateCoordReq()
	{
		m_nLongtitude = 0;
		m_nLatitude = 0;
	}

	int64_t				m_nLongtitude;
	int64_t				m_nLatitude;

	virtual int32_t Encode(uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		return 0;
	}

	virtual int32_t Decode(const uint8_t *pBuf, const int32_t nBufSize, uint32_t &nOffset)
	{
		int32_t nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nLongtitude);
		if(nRet != 0)
		{
			return nRet;
		}

		nRet = CCodeEngine::Decode(pBuf, nBufSize, nOffset, m_nLatitude);
		if(nRet != 0)
		{
			return nRet;
		}

		return nRet;
	}

	virtual void Dump(char* buf, const uint32_t size, uint32_t& offset)
	{
		uint32_t nLen = sprintf(buf + offset, ", msgbody={m_nLongtitude=%ld, m_nLatitude=%ld}", m_nLongtitude, m_nLatitude);
		offset += nLen;
	}
};


#endif /* LOCATION_MSG_H_ */
