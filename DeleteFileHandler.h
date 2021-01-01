/*
 * DeleteFileHandler.h
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#ifndef DELETEFILEHANDLER_H_
#define DELETEFILEHANDLER_H_

#include "RequestHandler.h"

class DeleteFileHandler : public RequestHandler {
public:
	DeleteFileHandler();
	virtual ~DeleteFileHandler();
	virtual bool canHandle(Request* req) override;
	virtual Response* handleInner(Request* req) override;
};
#endif /* DELETEFILEHANDLER_H_ */

