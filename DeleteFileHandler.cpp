/*
 * DeleteFileHandler.cpp
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#include "DeleteFileHandler.h"
#include "GeneralException.h"
#include "FilesRepository.h";
#include "FileNotFoundException.h"

#define DELETE_FILE_OP 201
#define DELETE_FILE_SUCCESS_STATUS 212
#define DELETE_FILE_FAILURE_NOT_FOUND_STATUS 1001

DeleteFileHandler::DeleteFileHandler() {
}

DeleteFileHandler::~DeleteFileHandler() {
}

bool DeleteFileHandler::canHandle(Request* req) {
	return req->getOp()==DELETE_FILE_OP;
}

Response* DeleteFileHandler::handleInner(Request* req) {
	try{
		FilesRepository::getInstance()->deleteFile(req->getUserId(), req->getFileName());
		return new Response(DELETE_FILE_SUCCESS_STATUS, req->getFileName());
	} catch (FileNotFoundException &exp){
		return new Response(DELETE_FILE_FAILURE_NOT_FOUND_STATUS, req->getFileName());
	}
}
