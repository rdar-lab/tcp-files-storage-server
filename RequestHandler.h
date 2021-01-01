/*
 * RequestHandler.h
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#ifndef REQUESTHANDLER_H_
#define REQUESTHANDLER_H_

#include "Request.h";
#include "Response.h";

class RequestHandler {
public:
	RequestHandler();
	virtual ~RequestHandler();

	virtual bool canHandle(Request* req) = 0;
	Response* handle(Request* req);
	virtual Response* handleInner(Request* req) = 0;
};
#endif /* REQUESTHANDLER_H_ */

