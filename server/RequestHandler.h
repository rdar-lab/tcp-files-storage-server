/*
 * RequestHandler.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef REQUESTHANDLER_H_
#define REQUESTHANDLER_H_

#include "Request.h"
#include "Response.h"

/*
 * RequestHandler
 * --------------
 * The abstract base class for a request handler
 */
class RequestHandler
{
public:
	/*
	 * Dtor
	 */
	virtual ~RequestHandler();

	/*
	 * Should return true if this handler can handle the request
	 */
	virtual bool canHandle(Request *req) = 0;

	/*
	 * An implementation of handle, will validate with canHandle the request can be used
	 * and will call the handleInner
	 */
	Response* handle(Request *req);
protected:
	/*
	 * Ctor - protected since this is an abstract class
	 */
	RequestHandler();

	/*
	 * The implementation of the request handling
	 */
	virtual Response* handleInner(Request *req) = 0;
};
#endif /* REQUESTHANDLER_H_ */

