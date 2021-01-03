/*
 * ByteBuffer.h
 *
 *  Created on: 1 Jan 2021
 *      Author: Roy Dar
 */

#ifndef BYTEBUFFER_H_
#define BYTEBUFFER_H_

#include <iostream>

class ByteBuffer
{
public:
	virtual ~ByteBuffer();
	virtual unsigned int getBytesLeft() = 0;
	virtual short readData(char *destinationBuffer,
			unsigned short lenToRead) = 0;
	void sendToStream(std::ostream &os);
protected:
	ByteBuffer();
};

#endif /* BYTEBUFFER_H_ */
