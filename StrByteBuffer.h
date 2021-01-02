/*
 * StrBytesBuffer.h
 *
 *  Created on: 2 Jan 2021
 *      Author: xmaster
 */

#ifndef STRBYTEBUFFER_H_
#define STRBYTEBUFFER_H_

#include "ByteBuffer.h"

class StrByteBuffer: public ByteBuffer {
public:
	StrByteBuffer(std::string str);
	virtual ~StrByteBuffer();
	virtual short int readData(char *destinationBuffer,
			unsigned short int lenToRead);
	virtual unsigned int getBytesLeft();
private:
	std::string str;
	unsigned int offset;
};

#endif /* STRBYTEBUFFER_H_ */
