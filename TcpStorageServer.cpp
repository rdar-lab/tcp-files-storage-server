//============================================================================
// Name        : tcp-storage-server.cpp
// Author      : 
// Version     :
// Copyright   : All copyrights to Roy Dar
// License     : MIT
// Description : TCP files storage server
//============================================================================

#include <iostream>
#include "ConfigurationFileReader.h"
#include "CommunicationManager.h"

#define CONFIGURATION_FILE_LOCATION "port.info"

int main() {
	ConfigurationFileReader reader(CONFIGURATION_FILE_LOCATION);
	unsigned int port = reader.getServerPort();

	std::cout << "String server at port " << port << std::endl;
	CommunicationManager::getInstance()->startServer(port);
	return 0;
}
