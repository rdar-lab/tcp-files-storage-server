/*
 * GetFilesListHandler.h
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#ifndef GETFILESLISTHANDLER_H_
#define GETFILESLISTHANDLER_H_

#include "RequestHandler.h"

class GetFilesListHandler : public RequestHandler  {
public:
	GetFilesListHandler();
	virtual ~GetFilesListHandler();
	virtual bool canHandle(Request* req) override;
protected:
	virtual Response* handleInner(Request* req) override;
};
#endif /* GETFILESLISTHANDLER_H_ */

