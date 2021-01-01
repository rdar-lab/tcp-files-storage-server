/*
 * GetFilesListHandler.cpp
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#include "GetFilesListHandler.h"
#include "FilesRepository.h"

#define GET_FILE_NAMES_OP 202
#define GET_FILE_NAMES_SUCCESS_STATUS 211
#define GET_FILE_NAMES_FAILURE_NO_FILES_FOR_USER 1002


GetFilesListHandler::GetFilesListHandler() {
}

GetFilesListHandler::~GetFilesListHandler() {
}

bool GetFilesListHandler::canHandle(Request* req) {
	return req->getOp() == GET_FILE_NAMES_OP;
}

std::string generateRandomFilename(){

}

ByteBuffer* generateFileNamesFileResponse(std::list<std::string> fileNames){

}

Response* GetFilesListHandler::handleInner(Request* req) {
	std::list<std::string> fileNames = FilesRepository::getInstance()->getFileNames(req->getUserId());

	if (fileNames.size() == 0){
		return new Response(GET_FILE_NAMES_FAILURE_NO_FILES_FOR_USER);
	} else {
		return new Response(GET_FILE_NAMES_SUCCESS_STATUS,
							generateRandomFilename(),
							generateFileNamesFileResponse(fileNames));
	}
}
