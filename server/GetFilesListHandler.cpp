/*
 * GetFilesListHandler.cpp
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#include <iostream>
#include <ctime>
#include <unistd.h>

#include "GetFilesListHandler.h"
#include "FilesRepository.h"
#include "Constants.h"
#include "StrByteBuffer.h"

std::string gen_random(const int len)
{

	std::string tmp_s;
	static const char alphanum[] = "0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";

	srand((unsigned) time(NULL) * getpid());

	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

	return tmp_s;

}

GetFilesListHandler::GetFilesListHandler()
{
}

GetFilesListHandler::~GetFilesListHandler()
{
}

bool GetFilesListHandler::canHandle(Request *req)
{
	return req->getOp() == GET_FILE_NAMES_OP;
}

std::string generateRandomFilename()
{
	return gen_random(32);
}

ByteBuffer* generateFileNamesFileResponse(std::list<std::string> fileNames)
{
	std::string fullResult = "";
	for (std::list<std::string>::iterator names_it = fileNames.begin();
			names_it != fileNames.end(); ++names_it)
	{
		fullResult = fullResult + (*names_it) + "\n";
	}

	return new StrByteBuffer(fullResult);
}

Response* GetFilesListHandler::handleInner(Request *req)
{
	std::list<std::string> fileNames =
			FilesRepository::getInstance()->getFileNames(req->getUserId());

	if (fileNames.size() == 0)
	{
		return new Response(GET_FILE_NAMES_FAILURE_NO_FILES_FOR_USER);
	}
	else
	{
		return new Response(GET_FILE_NAMES_SUCCESS_STATUS,
				generateRandomFilename(),
				generateFileNamesFileResponse(fileNames));
	}
}
