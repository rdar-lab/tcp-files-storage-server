/*
 * Response.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef RESPONSE_H_
#define RESPONSE_H_

#include <string>
#include "ByteBuffer.h"

class Response
{
public:
	Response(unsigned short status);
	Response(unsigned short status, std::string fileName);
	Response(unsigned short status, std::string fileName, ByteBuffer *payload);
	virtual ~Response();
	unsigned short getVersion() const;
	unsigned short getStatus() const;
	std::string getFileName() const;
	ByteBuffer* getPayload() const;
	friend std::ostream& operator<<(std::ostream &os, const Response &resp);
private:
	unsigned int version = 0;
	unsigned int status = 0;
	std::string fileName = "";
	ByteBuffer *payload = NULL;

};
#endif /* RESPONSE_H_ */

