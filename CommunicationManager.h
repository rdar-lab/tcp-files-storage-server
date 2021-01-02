/*
 * CommunicationManager.h
 *
 *  Created on: 27 Dec 2020
 *      Author: xmaster
 */

#ifndef COMMUNICATIONMANAGER_H_
#define COMMUNICATIONMANAGER_H_

#include <boost/asio.hpp>
#include <atomic>

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;


class CommunicationManager {
public:
	static CommunicationManager* getInstance();
	virtual ~CommunicationManager();
	void runServer(std::string host, unsigned int port);
private:
	CommunicationManager();
	static void handleClient(socket_ptr socket);
	std::atomic<int> numOfConnections;
	static CommunicationManager *singleInstance;
};

#endif /* COMMUNICATIONMANAGER_H_ */
