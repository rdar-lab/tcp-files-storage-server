/*
 * StrBytesBuffer.cpp
 *
 *  Created on: 2 Jan 2021
 *      Author: xmaster
 */

#include "StrByteBuffer.h"

#include <algorithm>
#include <iterator>


StrByteBuffer::StrByteBuffer(std::string str) {
	this->str = str;
	this->offset = 0;
}


StrByteBuffer::~StrByteBuffer() {
}

short int StrByteBuffer::readData(char *destinationBuffer,
		unsigned short int lenToReadInput) {
	unsigned short amountToRead = getBytesLeft();
	if (amountToRead > lenToReadInput){
		amountToRead = lenToReadInput;
	}
	const char* subStr = this->str.substr(this->offset, this->offset + amountToRead).c_str();

	std::copy(subStr, subStr + (amountToRead), destinationBuffer);

	this->offset = this->offset + amountToRead;
	return amountToRead;
}

unsigned int StrByteBuffer::getBytesLeft() {
	return this->str.length() - this->offset;
}
