/*
 * DownloadFileHandler.h
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#ifndef DOWNLOADFILEHANDLER_H_
#define DOWNLOADFILEHANDLER_H_

#include "RequestHandler.h"

class DownloadFileHandler : public RequestHandler {
public:
	DownloadFileHandler();
	virtual ~DownloadFileHandler();
	virtual bool canHandle(Request* req) override;
protected:
	virtual Response* handleInner(Request* req) override;
};
#endif /* DOWNLOADFILEHANDLER_H_ */

