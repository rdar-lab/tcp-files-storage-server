/*
 * CommunicationManager.h
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#ifndef COMMUNICATIONMANAGER_H_
#define COMMUNICATIONMANAGER_H_

class CommunicationManager {
public:
	static CommunicationManager* getInstance();
	virtual ~CommunicationManager();
	void startServer(unsigned int port);
	void stopServer();
private:
	CommunicationManager();
};

#endif /* COMMUNICATIONMANAGER_H_ */
