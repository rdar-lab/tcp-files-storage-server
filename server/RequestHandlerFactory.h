/*
 * RequestHandlerFactory.h
 *
 *  Created on: 1 Jan 2021
 *      Author: Roy Dar
 */

#ifndef REQUESTHANDLERFACTORY_H_
#define REQUESTHANDLERFACTORY_H_

#include "Request.h"
#include <list>
#include "RequestHandler.h"

class RequestHandlerFactory
{
public:
	static RequestHandlerFactory* getInstance();
	virtual ~RequestHandlerFactory();

	RequestHandler* getHandlerForRequest(Request *req);
	void registerHandler(RequestHandler *handler);
private:
	RequestHandlerFactory();
	static RequestHandlerFactory *singleInstance;
	std::list<RequestHandler*> handlersList;
};

#endif /* REQUESTHANDLERFACTORY_H_ */
