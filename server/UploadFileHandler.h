/*
 * UploadFileHandler.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef UPLOADFILEHANDLER_H_
#define UPLOADFILEHANDLER_H_

#include "RequestHandler.h"

class UploadFileHandler: public RequestHandler
{
public:
	UploadFileHandler();
	virtual ~UploadFileHandler();
	virtual bool canHandle(Request *req) override;
protected:
	virtual Response* handleInner(Request *req) override;
};
#endif /* UPLOADFILEHANDLER_H_ */

