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

/*
 * Response
 * --------
 * An object representation of a response in our system
 */
class Response
{
public:
	/*
	 * Ctor with status
	 */
	Response(unsigned short status);

	/*
	 * Ctor with status and filename
	 */
	Response(unsigned short status, std::string fileName);

	/*
	 * Ctor with status, fileName and data payload
	 */
	Response(unsigned short status, std::string fileName, ByteBuffer *payload);

	/*
	 * Dtor
	 */
	virtual ~Response();

	/*
	 * Returns the version
	 */
	unsigned short getVersion() const;

	/*
	 * Returns the status
	 */
	unsigned short getStatus() const;

	/*
	 * Returns the file name
	 */
	std::string getFileName() const;

	/*
	 * Returns the data payload
	 */
	ByteBuffer* getPayload() const;

	/*
	 * Implementation of << operator
	 */
	friend std::ostream& operator<<(std::ostream &os, const Response &resp);
private:
	unsigned int version = 0;
	unsigned int status = 0;
	std::string fileName = "";
	ByteBuffer *payload = NULL;

};
#endif /* RESPONSE_H_ */

