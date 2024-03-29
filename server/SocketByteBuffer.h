/*
 * SocketByteBuffer.h
 *
 *  Created on: 2 Jan 2021
 *      Author: Roy Dar
 */

#ifndef SOCKETBYTEBUFFER_H_
#define SOCKETBYTEBUFFER_H_

#include "ByteBuffer.h"
#include <boost/asio.hpp>

/*
 * SocketByteBuffer
 * ----------------
 * An implementation of a byte buffer bounded to a socket and limited to a specific size
 */
class SocketByteBuffer: public ByteBuffer
{
public:
	/*
	 * Ctor
	 */
	SocketByteBuffer(boost::asio::ip::tcp::socket *socket,
			unsigned int dataLen);

	/*
	 * Dtor
	 */
	virtual ~SocketByteBuffer();

	/*
	 * Reads a chunk of data
	 */
	virtual unsigned short int readData(char *destinationBuffer,
			unsigned short int lenToRead) override;

	/*
	 * Returns the amount of data left to read
	 */
	virtual unsigned int getBytesLeft() override;

private:
	boost::asio::ip::tcp::socket *socket;
	unsigned int dataLen;
	unsigned int dataRead;
};

#endif /* SOCKETBYTEBUFFER_H_ */
