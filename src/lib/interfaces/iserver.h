#ifndef ISERVER_H
#define ISERVER_H

#include <QObject>
#include <QTcpServer>

namespace CacheConnect
{

class IConnection;

/**
 * Represents a Server to accept Connections
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class IServer : public QTcpServer
{
	Q_OBJECT

public:
	/**
	 * @brief starts the server
	 * Server starts listening when this method is called
	 */
	virtual void start() = 0;

Q_SIGNALS:
	/**
	 * @brief emitted when a new Connection is available
	 */
	void gotConnection(IConnection*);

protected:
	/**
	 * @brief Constructor
	 */
	explicit IServer(QObject* parent);

	/**
	 * @brief Destructor
	 */
	~IServer();

};

}

#endif
