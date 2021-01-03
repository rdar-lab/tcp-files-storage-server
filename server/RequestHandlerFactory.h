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

/*
 * RequestHandlerFactory
 * ---------------------
 * A factory that will give back for each request the handler which should be used to handle it.
 * This class is a singleton
 */
class RequestHandlerFactory
{
public:
	/*
	 * Returns the single instance
	 */
	static RequestHandlerFactory* getInstance();

	/*
	 * Dtor
	 */
	virtual ~RequestHandlerFactory();

	/*
	 * Returns the handler for the req, or NULL if no handler can handle this request
	 */
	RequestHandler* getHandlerForRequest(Request *req);

	/*
	 * register the input handler
	 */
	void registerHandler(RequestHandler *handler);
private:
	/*
	 * Ctor - private because this is a singleton
	 */
	RequestHandlerFactory();

	// The single instance
	static RequestHandlerFactory *singleInstance;

	// The list of handlers
	std::list<RequestHandler*> handlersList;
};

#endif /* REQUESTHANDLERFACTORY_H_ */
