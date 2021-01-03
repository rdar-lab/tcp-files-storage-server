/*
 * Request.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include <string>
#include "ByteBuffer.h"

/*
 * Request
 * -------
 * An object implementation of the request in our system
 */
class Request
{
public:
	/*
	 * Ctor
	 */
	Request(unsigned short version, unsigned int userId, unsigned short op,
			std::string fileName, ByteBuffer *payload);

	/*
	 * Dtor
	 */
	virtual ~Request();

	/*
	 * Returns the version - FFU
	 */
	unsigned short getVersion() const;

	/*
	 * Returns the userId
	 */
	unsigned int getUserId() const;

	/*
	 * Returns the OP
	 */
	unsigned short getOp() const;

	/*
	 * Returns the file name
	 */
	std::string getFileName() const;

	/*
	 * Returns the file payload
	 */
	ByteBuffer* getPayload() const;

	/*
	 * << operator implementation
	 */
	friend std::ostream& operator<<(std::ostream &os, const Request &req);
private:
	unsigned int version = 0;
	unsigned int userId = 0;
	unsigned int op = 0;
	std::string fileName = "";
	ByteBuffer *payload = NULL;
};
#endif /* REQUEST_H_ */

