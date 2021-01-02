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
	Request(unsigned short version,
			unsigned int userId,
			unsigned short op,
			std::string fileName,
			ByteBuffer* payload
	);
	virtual ~Request();

	unsigned short getVersion() const;
	unsigned int getUserId() const;
	unsigned short getOp() const;
	std::string getFileName() const;
	ByteBuffer* getPayload() const;
	friend std::ostream& operator<<(std::ostream& os, const Request& req);
private:
	unsigned int version = 0;
	unsigned int userId = 0;
	unsigned int op = 0;
	std::string fileName = "";
	ByteBuffer* payload = NULL;
};
#endif /* REQUEST_H_ */

