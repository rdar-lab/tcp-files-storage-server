/*
 * RequestReader.h
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#ifndef REQUESTREADER_H_
#define REQUESTREADER_H_

#include "Request.h"
#include <boost/asio.hpp>


class RequestReader {
public:
	RequestReader(boost::asio::ip::tcp::socket *socket);
	Request* readRequest();
	virtual ~RequestReader();
private:
	boost::asio::ip::tcp::socket *socket;
};
#endif /* REQUESTREADER_H_ */

