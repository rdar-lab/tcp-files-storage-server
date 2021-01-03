/*
 * FileNotFoundException.h
 *
 *  Created on: 1 Jan 2021
 *      Author: Roy Dar
 */

#ifndef FILENOTFOUNDEXCEPTION_H_
#define FILENOTFOUNDEXCEPTION_H_

#include <stdexcept>

/*
 * FileNotFoundException
 * ---------------------
 * Exception that is thrown when the file is not found
 */
class FileNotFoundException: public std::exception
{
public:
	/*
	 * Ctor
	 */
	FileNotFoundException();

	/*
	 * Dtor
	 */
	virtual ~FileNotFoundException();
};

#endif /* FILENOTFOUNDEXCEPTION_H_ */
