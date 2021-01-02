/*
 * FileByteBuffer.h
 *
 *  Created on: 2 Jan 2021
 *      Author: xmaster
 */

#ifndef FILEBYTEBUFFER_H_
#define FILEBYTEBUFFER_H_

#include <string>
#include <iostream>
#include "ByteBuffer.h"
#include <fstream>

class FileByteBuffer: public ByteBuffer {
public:
	FileByteBuffer(std::string filePath);
	virtual ~FileByteBuffer();
	virtual short int readData(char *destinationBuffer,
			unsigned short int lenToRead);
	virtual unsigned int getBytesLeft();
private:
	unsigned int fileSize;
	unsigned int sizeRead;
	std::ifstream fileStream;
};

#endif /* FILEBYTEBUFFER_H_ */
