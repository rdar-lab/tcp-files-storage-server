/*
 * StrBytesBuffer.h
 *
 *  Created on: 2 Jan 2021
 *      Author: Roy Dar
 */

#ifndef STRBYTEBUFFER_H_
#define STRBYTEBUFFER_H_

#include "ByteBuffer.h"

/*
 * StrByteBuffer
 * -------------
 * A byte buffer based on an STR. Although the interface is the same, using this implementation,
 * the entire STR is held in memory
 */
class StrByteBuffer: public ByteBuffer
{
public:
	/*
	 * Ctor
	 */
	StrByteBuffer(std::string str);

	/*
	 * Dtor
	 */
	virtual ~StrByteBuffer();

	/*
	 * Reads data from the Str
	 */
	virtual unsigned short int readData(char *destinationBuffer,
			unsigned short int lenToRead);

	/*
	 * Returns the amount left to read
	 */
	virtual unsigned int getBytesLeft();
private:
	std::string str;
	unsigned int offset;
};

#endif /* STRBYTEBUFFER_H_ */
