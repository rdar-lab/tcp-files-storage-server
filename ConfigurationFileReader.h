/*
 * ConfigurationFileReader.h
 *
 *  Created on: 1 Jan 2021
 *      Author: xmaster
 */

#ifndef CONFIGURATIONFILEREADER_H_
#define CONFIGURATIONFILEREADER_H_
#include <string>

class ConfigurationFileReader {
public:
	ConfigurationFileReader(std::string configurationFileName);

	unsigned int getServerPort();

	virtual ~ConfigurationFileReader();
};

#endif /* CONFIGURATIONFILEREADER_H_ */
