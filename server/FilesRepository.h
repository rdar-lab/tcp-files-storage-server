/*
 * FilesRepository.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef FILESREPOSITORY_H_
#define FILESREPOSITORY_H_

#include <string>
#include <list>
#include "ByteBuffer.h"

class FilesRepository
{
public:
	static FilesRepository* getInstance();
	virtual ~FilesRepository();

	std::string saveFile(unsigned int userId, std::string fileName,
			ByteBuffer *dataBuffer);
	void deleteFile(unsigned int userId, std::string fileName);
	ByteBuffer* getFile(unsigned int userId, std::string fileName);
	std::list<std::string> getFileNames(unsigned int userId);
private:
	FilesRepository();
	static FilesRepository *singleInstance;
};
#endif /* FILESREPOSITORY_H_ */

