/*
 * ConfigurationFileReader.h
 *
 *  Created on: 1 Jan 2021
 *      Author: Roy Dar
 */

#ifndef CONFIGURATIONFILEREADER_H_
#define CONFIGURATIONFILEREADER_H_
#include <string>

class ConfigurationFileReader
{
public:
	ConfigurationFileReader(std::string configurationFileName);

	unsigned short getServerPort();
	std::string getServerHost();

	virtual ~ConfigurationFileReader();
private:
	unsigned int serverPort;
	std::string serverHost;
};

#endif /* CONFIGURATIONFILEREADER_H_ */
