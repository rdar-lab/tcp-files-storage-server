/*
 * CommunicationManager.h
 *
 *  Created on: 27 Dec 2020
 *      Author: Roy Dar
 */

#ifndef COMMUNICATIONMANAGER_H_
#define COMMUNICATIONMANAGER_H_

#include <boost/asio.hpp>
#include <atomic>

// typedef to allow a socket to be shared with a thread
typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

/*
 * CommunicationManager
 * --------------------
 * The communication manager is responsible for the TCP layer.
 * This is a singleton class.
 *
 */
class CommunicationManager
{
public:
	/*
	 * static method to get the single instance
	 */
	static CommunicationManager* getInstance();

	/*
	 * Dtor
	 */
	virtual ~CommunicationManager();

	/*
	 * Runs the TCP server using the network card designated by 'host' and the 'port'
	 */
	void runServer(std::string host, unsigned int port);
private:
	/*
	 * Ctor - private because this is a singleton
	 */
	CommunicationManager();

	/*
	 * Handler for a new client connection
	 */
	static void handleClient(socket_ptr socket);

	/*
	 * The current number of connections
	 */
	std::atomic<int> numOfConnections;

	/*
	 * The single instance
	 */
	static CommunicationManager *singleInstance;
};

#endif /* COMMUNICATIONMANAGER_H_ */
