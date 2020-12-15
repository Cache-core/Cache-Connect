#ifndef TRANSFERSERVER_H
#define TRANSFERSERVER_H

#include "interfaces/iserver.h"

#include <QObject>

namespace CacheConnect
{

/**
 * @brief Server that handles all connection related to Transfers.
 * server listens on port 2423
 *
 * @see IServer
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class TransferServer : public IServer
{
	Q_OBJECT

public:
	/**
	 * @brief CTOR
	 */
	explicit TransferServer(QObject* parent);

	/**
	 * @brief DTOR
	 */
	~TransferServer();

	/**
	 * @brief start the server
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
 

