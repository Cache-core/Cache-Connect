#ifndef CONTROLCENTERPRIVATE_H
#define CONTROLCENTERPRIVATE_H

namespace CacheConnect
{

class MessageServer;
class ClientManager;
class CryptEngine;
class TransferManager;
class TransferServer;
class UserSettings;
class ControlCenter;

/**
 * @brief Container for all instances provided by IControlCenter
 */
class ControlCenterPrivate
{
public:
	/**
	 * @brief CTOR
	 */
	explicit ControlCenterPrivate(ControlCenter* parent = nullptr);

	/**
	 * @brief DTOR
	 */
	~ControlCenterPrivate();

	/**
	 * @brief creates all instances
	 */
	void init();

	/**
	 * @brief deletes all instances
	 */
	void shutdown();

	MessageServer* m_messageServer;
	TransferServer* m_transferServer;
	ClientManager* m_clientManager;
	CryptEngine* m_cryptEngine;
	TransferManager* m_transferManager;
	UserSettings* m_userSettings;

	ControlCenter* m_cc;
};

}

#endif
