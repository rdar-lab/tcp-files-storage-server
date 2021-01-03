/*
 * FileNotFoundException.h
 *
 *  Created on: 1 Jan 2021
 *      Author: Roy Dar
 */

#ifndef FILENOTFOUNDEXCEPTION_H_
#define FILENOTFOUNDEXCEPTION_H_

#include <stdexcept>

class FileNotFoundException: public std::exception
{
public:
	FileNotFoundException();
	virtual ~FileNotFoundException();
};

#endif /* FILENOTFOUNDEXCEPTION_H_ */
