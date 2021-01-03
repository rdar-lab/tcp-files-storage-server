/*
 * CommunicationUtils.h
 *
 *  Created on: 2 Jan 2021
 *      Author: Roy Dar
 */

#ifndef COMMUNICATIONSERILIZATIONHELPER_H_
#define COMMUNICATIONSERILIZATIONHELPER_H_

#include <string>
#include "ByteBuffer.h"
#include <boost/asio.hpp>

class CommunicationSerilizationHelper
{
public:
	CommunicationSerilizationHelper(boost::asio::ip::tcp::socket *socket);
	virtual ~CommunicationSerilizationHelper();
	unsigned short readByte();
	void writeByte(unsigned short data);
	unsigned short readShort();
	void writeShort(unsigned short data);
	unsigned int readInt();
	void writeInt(unsigned int data);
	std::string readStr();
	void writeStr(std::string data);
	ByteBuffer* readBytes();
	void writeBytes(ByteBuffer *data);
private:
	boost::asio::ip::tcp::socket *socket;
};

#endif /* COMMUNICATIONSERILIZATIONHELPER_H_ */
