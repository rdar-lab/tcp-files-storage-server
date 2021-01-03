/*
 * DeleteFileHandler.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef DELETEFILEHANDLER_H_
#define DELETEFILEHANDLER_H_

#include "RequestHandler.h"

/*
 * DeleteFileHandler
 * -----------------
 * An handler to a request to delete a file
 */
class DeleteFileHandler: public RequestHandler
{
public:
	/*
	 * Ctor
	 */
	DeleteFileHandler();

	/*
	 * Dtor
	 */
	virtual ~DeleteFileHandler();

	/*
	 * Implementation of canHandle
	 * Will check that the req is for deletion
	 */
	virtual bool canHandle(Request *req) override;
protected:

	/*
	 * Handles the request
	 */
	virtual Response* handleInner(Request *req) override;
};
#endif /* DELETEFILEHANDLER_H_ */

