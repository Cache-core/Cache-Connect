#ifndef MESSAGESERVER_H
#define MESSAGESERVER_H

#include "interfaces/iserver.h"

#include <QObject>

namespace CacheConnect
{

/**
 * @brief Server that handles all connection related to Clients.
 * server listens on port 2424
 *
 * @see IServer
 */
class MessageServer : public IServer
{
	Q_OBJECT

public:
	/**
	 * @brief CTOR
	 */
	explicit MessageServer(QObject* parent);

	/**
	 * @brief DTOR
	 */
	~MessageServer();

	/**
	 * @brief starts the server
	 */
	void start() override;

	/**
	 * @brief closes the server
	 */
	void shutdown();

protected:
	QTcpServer m_server;

	/**
	 * @brief creates a new IConnection when connection availale
	 * @param handle socket descriptor
	 */
	void incomingConnection(qintptr handle) override;

};

}

#endif
 
