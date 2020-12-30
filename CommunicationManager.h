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
	CommunicationManager(int port);
	virtual ~CommunicationManager();
	void startServer();
};

#endif /* COMMUNICATIONMANAGER_H_ */
