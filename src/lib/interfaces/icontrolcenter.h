#ifndef ICONTROLCENTER_H
#define ICONTROLCENTER_H

#include <QObject>

namespace CacheConnect
{

class IServer;
class IClientManager;
class ICryptEngine;
class ITransferManager;
class IUserSettings;
/**
 * Allow access to instances of
 * @li @c MessageServer
 * @li @c TransferServer
 * @li @c ClientManager
 * @li @c CryptEngine
 * @li @c TransferManager
 * @li @c UserSettings
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class IControlCenter : public QObject
{
	Q_OBJECT

public:
	/**
	 * @brief static instance of ControlCenter
	 * @return IControlCenter
	 */
	static IControlCenter* instance();

	/**
	 * @brief access to instance of MessageServer
	 * @return IServer
	 */
	virtual IServer* messageServer() = 0;

	/**
	 * @brief access to instance of TransferServer
	 * @return IServer
	 */
	virtual IServer* transferServer() = 0;

	/**
	 * @brief access to instance of ClientManager
	 * @return IClientManager
	 */
	virtual IClientManager* clientManager() = 0;

	/**
	 * @brief access to instance of CryptEngine
	 * @return ICryptEngine
	 */
	virtual ICryptEngine* cryptEngine() = 0;

	/**
	 * @brief access to instance of Transfermanager
	 * @return ITransferManager
	 */
	virtual ITransferManager* transferManager() = 0;

	/**
	 * @brief access to instance of UserSettings
	 * @return IUserSettings
	 */
	virtual IUserSettings* userSettings() = 0;

protected:
	/**
	 * @brief static instance of IControlCenter for using from anywhere in the application
	 */
	static IControlCenter* m_instance;

	/**
	 * @brief Constructor
	 */
	explicit IControlCenter(QObject* parent = nullptr);

	/**
	 * @brief Destructor
	 */
	~IControlCenter();

};

}

#endif
