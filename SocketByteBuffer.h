/*
 * SocketByteBuffer.h
 *
 *  Created on: 2 Jan 2021
 *      Author: xmaster
 */

#ifndef SOCKETBYTEBUFFER_H_
#define SOCKETBYTEBUFFER_H_

#include "ByteBuffer.h"
#include <boost/asio.hpp>


class SocketByteBuffer: public ByteBuffer {
public:
	SocketByteBuffer(boost::asio::ip::tcp::socket *socket, unsigned int dataLen);
	virtual ~SocketByteBuffer();
	virtual short int readData(char *destinationBuffer,
			unsigned short int lenToRead) override;
	virtual unsigned int getBytesLeft() override;

private:
	boost::asio::ip::tcp::socket *socket;
	unsigned int dataLen;
	unsigned int dataRead;
};

#endif /* SOCKETBYTEBUFFER_H_ */
