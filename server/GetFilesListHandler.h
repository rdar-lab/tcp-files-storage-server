/*
 * GetFilesListHandler.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef GETFILESLISTHANDLER_H_
#define GETFILESLISTHANDLER_H_

#include "RequestHandler.h"

/*
 * GetFilesListHandler
 * -------------------
 * Handler for the get files list operation
 */
class GetFilesListHandler: public RequestHandler
{
public:
	/*
	 * Ctor
	 */
	GetFilesListHandler();

	/*
	 * Dtor
	 */
	virtual ~GetFilesListHandler();

	/*
	 * Checks that the req is of type get files list
	 */
	virtual bool canHandle(Request *req) override;
protected:
	/*
	 * Handles the request
	 */
	virtual Response* handleInner(Request *req) override;
};
#endif /* GETFILESLISTHANDLER_H_ */

