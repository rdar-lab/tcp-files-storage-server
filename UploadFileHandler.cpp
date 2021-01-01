/*
 * UploadFileHandler.cpp
 *
 *  Created on: 1 Jan 2021
 *      Author: xmaster
 */

#include "UploadFileHandler.h"
#include "FilesRepository.h"

#define UPLOAD_FILE_OP 202
#define UPLOAD_FILE_SUCCESS_STATUS 211


UploadFileHandler::UploadFileHandler() {
}

UploadFileHandler::~UploadFileHandler() {
}

bool UploadFileHandler::canHandle(Request* req) {
	return req->getOp() == UPLOAD_FILE_OP;
}

Response* UploadFileHandler::handleInner(Request* req) {
	std::string newFileName = FilesRepository::getInstance()->saveFile(req->getUserId(), req->getFileName(), req->getPayload());
	return new Response(UPLOAD_FILE_SUCCESS_STATUS, newFileName);
}
