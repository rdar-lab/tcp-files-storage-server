/*
 * ResponseWriter.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef RESPONSEWRITER_H_
#define RESPONSEWRITER_H_

#include "Response.h"
#include <boost/asio.hpp>

class ResponseWriter
{
public:
	ResponseWriter(boost::asio::ip::tcp::socket *socket);
	void writeResponse(Response *resp);
	virtual ~ResponseWriter();
private:
	boost::asio::ip::tcp::socket *socket;
};

#endif /* RESPONSEWRITER_H_ */
