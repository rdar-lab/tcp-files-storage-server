/*
 * FileNotFoundException.h
 *
 *  Created on: 1 Jan 2021
 *      Author: xmaster
 */

#ifndef FILENOTFOUNDEXCEPTION_H_
#define FILENOTFOUNDEXCEPTION_H_

#include <stdexcept>

class FileNotFoundException: public std::runtime_error {
public:
	FileNotFoundException();
	virtual ~FileNotFoundException();
};

#endif /* FILENOTFOUNDEXCEPTION_H_ */
