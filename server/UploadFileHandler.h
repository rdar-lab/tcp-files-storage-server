/*
 * UploadFileHandler.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef UPLOADFILEHANDLER_H_
#define UPLOADFILEHANDLER_H_

#include "RequestHandler.h"

/*
 * UploadFileHandler
 * -----------------
 * An handler for a request to upload a file
 */
class UploadFileHandler: public RequestHandler
{
public:
	/*
	 * Ctor
	 */
	UploadFileHandler();

	/*
	 * Dtor
	 */
	virtual ~UploadFileHandler();

	/*
	 * Checks if the req is of upload file type
	 */
	virtual bool canHandle(Request *req) override;
protected:
	/*
	 * Handles the request to upload the file
	 */
	virtual Response* handleInner(Request *req) override;
};
#endif /* UPLOADFILEHANDLER_H_ */

