#ifndef ICLIENT_H
#define ICLIENT_H

#include <QObject>

namespace CacheConnect
{

class IConnection;
class ClientInformation;
/**
 * Allows to access a Client information
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class IClient : public QObject
{
	Q_OBJECT

public:
	/**
	 * @brief Returns the connection of the client
	 * @return IConnection
	 */
	virtual IConnection* connection() = 0;

	/**
	 * @brief provides the information of a client
	 * @return ClientInformation
	 */
	virtual ClientInformation info() = 0;

	/**
	 * @brief sends a text message to the client
	 * @param msg message to send to the client
	 */
	virtual void sendMessage(QString msg) = 0;

protected:
	/**
	 * @brief Constructor
	 */
	IClient(QObject* parent = nullptr);

	/**
	 * @brief Destructor
	 */
	~IClient();

};

}

#endif
