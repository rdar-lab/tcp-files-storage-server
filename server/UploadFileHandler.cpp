/*
 * UploadFileHandler.cpp
 *
 *  Created on: 1 Jan 2021
 *      Author: Roy Dar
 */

#include "UploadFileHandler.h"
#include "FilesRepository.h"
#include "Constants.h"

UploadFileHandler::UploadFileHandler()
{
}

UploadFileHandler::~UploadFileHandler()
{
}

bool UploadFileHandler::canHandle(Request *req)
{
	return req->getOp() == UPLOAD_FILE_OP;
}

Response* UploadFileHandler::handleInner(Request *req)
{
	std::string newFileName = FilesRepository::getInstance()->saveFile(
			req->getUserId(), req->getFileName(), req->getPayload());
	return new Response(UPLOAD_FILE_SUCCESS_STATUS, newFileName);
}
