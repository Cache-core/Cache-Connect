#ifndef ICONNECTION_H
#define ICONNECTION_H

#include <QTcpSocket>

namespace CacheConnect
{
/**
 * Represents a connection on network.
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class IConnection : public QTcpSocket
{
	Q_OBJECT

public:
	/**
	 * @brief provides the data comming to the socket
	 * @param size amount of data to be read
	 * @return data if size available otherwise returns empty QByteArray
	 */
	virtual QByteArray data(quint32 size = 0) = 0;

	/**
	 * @brief same as data method but doesn't removes the read data from stored memory (i.e. can read same data again)
	 * @param size amount of data to seek
	 * @return data if size available otherwise returns empty QByteArray
	 */
	virtual QByteArray seek(quint32 size) = 0;

	/**
	 * @brief if any data is ready for reading or not
	 * @return true if has data , false if doesn't have any data
	 */
	virtual bool hasUnreadData() = 0;

	/**
	 * @brief amount of data available for reading
	 * @return size of available data
	 */
	virtual quint32 availableSize() = 0;
	
Q_SIGNALS:
	/**
	 * @brief emitted if new data is ready for reading
	 */
	void dataAvailable();

	/**
	 * @brief emitted if some error in socket
	 */
	void errorOccurred();

	/**
	 * @brief emitted if no host is found on connection
	 */
	void hostNotFound();

protected:
	/**
	 * @brief Constructor
	 */
	explicit IConnection();

	/**
	 * @brief Destructor
	 */
	~IConnection();

};

}

#endif
