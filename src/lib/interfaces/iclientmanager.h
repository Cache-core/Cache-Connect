#ifndef ICLIENTMANAGER_H
#define ICLIENTMANAGER_H

#include <QObject>
#include <QList>

namespace CacheConnect
{

class IConnection;
class ClientInformation;
class MessageInformation;

/**
 * Allows access to information of all Registered Clients.
 * Works as an Interface for interacting with a client like sending message.
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class IClientManager : public QObject
{
	Q_OBJECT

public:
	/**
	 * @brief initiates a shutdown
	 */
	virtual void shutdown() = 0;

	/**
	 * @brief provides list of information of all the clients
	 * @return List of ClientInformation
	 */
	virtual QList<ClientInformation> clients() = 0;

	/**
	 * @brief provide information for a specific Client
	 * @param id id of a client whose information is needed
	 * @return ClientInformation
	 */
	virtual ClientInformation clientInfo(qint16 id) = 0;

	/**
	 * @brief provides the messages sent-to or recieved-from all the clients
	 * @return List of MessageInformation
	 */
	virtual QList<MessageInformation> messages() = 0;

	/**
	 * @brief sends a message to a Client
	 * @param id id of a client to send message to
	 * @param msg a text message
	 */
	virtual void sendMessage(qint16 id,QString msg) = 0;

	/**
	 * @brief connects to a url specified
	 * @param url an ip address to connect to
	 */
	virtual void connectManualy(QString url) = 0;

	/**
	 * @brief adds a connection to create a Client
	 * @param connection
	 */
	Q_INVOKABLE virtual void addConnection(IConnection* connection) = 0;

Q_SIGNALS:
	/**
	 * @brief will be emitted if new Client is added
	 */
	void userListUpdated();

	/**
	 * @brief will be emitted if new message is sent or recieved
	 * @param mi Information about the message
	 */
	void messageAdded(MessageInformation mi);

	/**
	 * @brief will be emitted if a manual connection is failed
	 * @param url ip address cannot connect to
	 */
	void manualConnectionFailed(QString url);

protected:
	/**
	 * @brief Constructor
	 */
	explicit IClientManager(QObject* parent = nullptr);

	/**
	 * @brief Destructor
	 */
	~IClientManager();

};

}

#endif
