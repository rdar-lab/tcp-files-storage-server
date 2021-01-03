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

/*
 * FilesRepository
 * ---------------
 * The file repository implementation.
 * This is a singleton implementation that will implement the low level storage service.
 */
class FilesRepository
{
public:
	/*
	 * Returns the single instance
	 */
	static FilesRepository* getInstance();

	/*
	 * Dtor
	 */
	virtual ~FilesRepository();

	/*
	 * Saves a file to the repository
	 */
	std::string saveFile(unsigned int userId, std::string fileName,
			ByteBuffer *dataBuffer);

	/*
	 * Deletes a file from the repository
	 */
	void deleteFile(unsigned int userId, std::string fileName);

	/*
	 * Returns a file from the repository
	 */
	ByteBuffer* getFile(unsigned int userId, std::string fileName);

	/*
	 * Returns the list of files for the user
	 */
	std::list<std::string> getFileNames(unsigned int userId);
private:
	/*
	 * Ctor - private because this is a singleton
	 */
	FilesRepository();

	// The single instance
	static FilesRepository *singleInstance;
};
#endif /* FILESREPOSITORY_H_ */

