/*
 * Request.h
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include <string>
#include "ByteBuffer.h"

class Request {
public:
	Request();
	virtual ~Request();

	unsigned int getVersion();
	void setVersion(unsigned int version);
	unsigned int getUserId();
	void setUserId(unsigned int userId);
	unsigned int getOp();
	void setOp(unsigned int op);
	std::string getFileName();
	void setFileName(std::string fileName);
	ByteBuffer* getPayload();
	void setPayload(ByteBuffer* buffer);
private:
	unsigned int version = 0;
	unsigned int userId = 0;
	unsigned int op = 0;
	std::string fileName = "";
	ByteBuffer* payload = NULL;
};
#endif /* REQUEST_H_ */

