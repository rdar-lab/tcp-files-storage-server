/*
 * DownloadFileHandler.cpp
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#include "DownloadFileHandler.h"
#include "FilesRepository.h"
#include "FileNotFoundException.h"

#define DOWLOAD_FILE_OP 200
#define DOWLOAD_FILE_SUCCESS_STATUS 210
#define DOWLOAD_FILE_FAILURE_NOT_FOUND_STATUS 1001


DownloadFileHandler::DownloadFileHandler() {
}

DownloadFileHandler::~DownloadFileHandler() {
}

bool DownloadFileHandler::canHandle(Request* req) {
	return req->getOp() == DOWLOAD_FILE_OP;
}

Response* DownloadFileHandler::handleInner(Request* req) {
	try{
		ByteBuffer* buff = FilesRepository::getInstance()->getFile(req->getUserId(), req->getFileName());
		return new Response(DOWLOAD_FILE_SUCCESS_STATUS, req->getFileName(), buff);
	} catch (FileNotFoundException &exp){
		return new Response(DOWLOAD_FILE_FAILURE_NOT_FOUND_STATUS, req->getFileName());
	}
}
