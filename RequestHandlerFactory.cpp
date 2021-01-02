/*
 * RequestHandlerFactory.cpp
 *
 *  Created on: 1 Jan 2021
 *      Author: Roy Dar
 */

#include "RequestHandlerFactory.h"

RequestHandlerFactory *RequestHandlerFactory::singleInstance = NULL;

RequestHandlerFactory* RequestHandlerFactory::getInstance()
{
	if (RequestHandlerFactory::singleInstance == NULL)
	{
		RequestHandlerFactory::singleInstance = new RequestHandlerFactory();
	}
	return RequestHandlerFactory::singleInstance;
}

RequestHandler* RequestHandlerFactory::getHandlerForRequest(Request *req)
{
	for (std::list<RequestHandler*>::iterator handlers_it =
			this->handlersList.begin(); handlers_it != this->handlersList.end();
			++handlers_it)
	{
		if ((*handlers_it)->canHandle(req))
		{
			return (*handlers_it);
		}
	}
	return NULL;
}

void RequestHandlerFactory::registerHandler(RequestHandler *handler)
{
	this->handlersList.push_back(handler);
}

RequestHandlerFactory::RequestHandlerFactory()
{
}

RequestHandlerFactory::~RequestHandlerFactory()
{
	for (std::list<RequestHandler*>::iterator handlers_it =
			this->handlersList.begin(); handlers_it != this->handlersList.end();
			++handlers_it)
	{
		delete (*handlers_it);
	}
}

