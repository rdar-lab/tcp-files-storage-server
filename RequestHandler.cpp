/*
 * RequestHandler.cpp
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#include "RequestHandler.h"
#include "GeneralException.h"

RequestHandler::RequestHandler()
{
}

RequestHandler::~RequestHandler()
{
}

Response* RequestHandler::handle(Request *req)
{
	if (!this->canHandle(req))
	{
		throw GeneralException(
				"This request handler cannot handle this request");
	}

	return this->handleInner(req);
}
