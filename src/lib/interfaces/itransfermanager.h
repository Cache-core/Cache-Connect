#ifndef ITRANSFERMANAGER_H
#define ITRANSFERMANAGER_H

#include <QObject>
#include <QList>

namespace CacheConnect
{

class IConnection;
class File;

/**
 * Allows access to information of all Registered Transfers.
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class ITransferManager : public QObject
{
	Q_OBJECT

public:
	/**
	 * @brief initiates a shutdown
	 */
	virtual void shutdown() = 0;

	/**
	 * @brief provides list of pending transfers
	 * i.e. transfers that are waiting to get accepted or rejected
	 * @return List of File
	 */
	virtual QList<File> pendingTransfers() = 0;

	/**
	 * @brief provides list of active transfers
	 * i.e. transfers that are running and sending (or recieveing) data
	 * @return List of File
	 */
	virtual QList<File> runningTransfers() = 0;

	/**
	 * @brief creates a Transfer to send the File provided
	 * @param file File Information to send
	 */
	virtual void sendFile(File file) = 0;

	/**
	 * @brief accepts a Transfer
	 * @param id is id of transfer to accept
	 */
	virtual void acceptTransfer(qint16 id) = 0;

	/**
	 * @brief rejects a Transfer
	 * @param id is id of transfer to reject
	 */
	virtual void rejectTransfer(qint16 id) = 0;

	/**
	 * @brief stops running Transfer
	 * @param id is id of transfer to stop
	 */
	virtual void stopTransfer(qint16 id) = 0;
	
	/**
	 * @brief adds a connection to create a Transfer
	 * @param connection
	 */
	Q_INVOKABLE virtual void addConnection(IConnection*) = 0;

Q_SIGNALS:
	/**
	 * @brief emitted when new transfer is created
	 */
	void pendingTransfersUpdated();

	/**
	 * @brief emitted when new transfer is accepted
	 */
	void runningTransfersUpdated();

	/**
	 * @brief emitted every second for every running transfer
	 * @param id is id of transfer whose progress is updated
	 * @param progress transfer completed in percentage
	 * @param transfered total file transfered
	 * @param rate transfer rate at which recieving data
	 */
	void transferProgressed(qint16 id,int progress,quint64 transfered,int rate);

protected:
	/**
	 * @brief Constructor
	 */
	explicit ITransferManager(QObject* parent = nullptr);

	/**
	 * @brief Destructor
	 */
	~ITransferManager();
};

}

#endif
