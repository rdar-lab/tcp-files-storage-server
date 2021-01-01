/*
 * Response.h
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#ifndef RESPONSE_H_
#define RESPONSE_H_

#include <string>
#include "ByteBuffer.h"


class Response {
public:
	Response();
	Response(unsigned int status);
	Response(unsigned int status, std::string fileName);
	Response(unsigned int status, std::string fileName, ByteBuffer* payload);
	virtual ~Response();
	unsigned int getVersion();
	unsigned int getStatus();
	std::string getFileName();
	void setFileName(std::string fileName);
	ByteBuffer* getPayload();
	void setPayload(ByteBuffer* payload);
private:
	unsigned int version = 0;
	unsigned int status = 0;
	std::string fileName = "";
	ByteBuffer* payload = NULL;

};
#endif /* RESPONSE_H_ */

