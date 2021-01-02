/*
 * RequestReader.cpp
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#include <string>
#include "Constants.h"
#include "RequestReader.h"
#include "CommunicationSerilizationHelper.h"
#include "GeneralException.h"

RequestReader::RequestReader(boost::asio::ip::tcp::socket *socket) {
	this->socket = socket;
}

RequestReader::~RequestReader() {
}

Request* RequestReader::readRequest() {
	CommunicationSerilizationHelper helper(this->socket);
	unsigned int userId = helper.readInt();
	unsigned short version = helper.readByte();
	unsigned short op = helper.readByte();
	std::string fileName = "";
	if (op < 202){
		unsigned short nameLen = helper.readShort();
		if (nameLen > MAX_FILE_NAME_LENGTH)
		{
			throw GeneralException("Name is over the maximum length");
		}
		fileName = helper.readStr(nameLen);
	}

	ByteBuffer* payload = NULL;
	if (op == 100)
	{
		unsigned int payloadLen = helper.readInt();
		if (payloadLen > MAX_PAYLOAD_SIZE_BYTES){
			throw GeneralException("Payload is over the maximum length");
		}
		payload = helper.readBytes(payloadLen);
	}

	return new Request(version, userId, op, fileName, payload);

}
