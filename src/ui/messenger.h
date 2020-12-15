#ifndef MESSENGER_H
#define MESSENGER_H

#include <QObject>

namespace CacheConnect
{
class IClientManager;

/**
 * @brief Messanger to send messages to clients
 */
class Messenger : public QObject
{
	Q_OBJECT
public:
	explicit Messenger(IClientManager *cm);
	~Messenger();

	/**
	 * @brief sends a text message to a client
	 * @param id of client to send message to
	 * @param msg msg to sent to the client
	 */
	void sendMessage(int id, QString msg);

protected:
	IClientManager* m_cm;

};

}

#endif
