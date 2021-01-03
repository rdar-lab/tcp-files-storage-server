/*
 * DownloadFileHandler.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef DOWNLOADFILEHANDLER_H_
#define DOWNLOADFILEHANDLER_H_

#include "RequestHandler.h"

/*
 * DownloadFileHandler
 * -------------------
 * An handler to a download file request
 */
class DownloadFileHandler: public RequestHandler
{
public:
	/*
	 * Ctor
	 */
	DownloadFileHandler();

	/*
	 * Dtor
	 */
	virtual ~DownloadFileHandler();

	/*
	 * canHandle implementation.
	 * Will make sure that the req is for file download
	 */
	virtual bool canHandle(Request *req) override;
protected:
	/*
	 * handle the download request
	 */
	virtual Response* handleInner(Request *req) override;
};
#endif /* DOWNLOADFILEHANDLER_H_ */

