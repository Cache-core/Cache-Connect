#ifndef PENDINGTRANSFERS_H
#define PENDINGTRANSFERS_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>

namespace CacheConnect
{
class ITransferManager;
class File;

/**
 * @brief List of all Pending Transfers for GUI
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class PendingTransfers : public QAbstractListModel
{
	Q_OBJECT
public:
	enum UserInfo {
		Id  = Qt::UserRole + 1,
		FileName,
		FilePath,
		FileSize,
		Url,
		ClientName
	};

	explicit PendingTransfers(ITransferManager* tm, QObject* parent = nullptr);
	~PendingTransfers();
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public Q_SLOTS:
	/**
	 * @brief updates the list
	 */
	void updateList();

Q_SIGNALS:
	/**
	 * @brief emitted when a new pending Trasnfer is added
	 */
	void transfersAdded(int);

protected:
	QHash<int, QByteArray> roleNames() const;
	ITransferManager *m_tm;
	QList<File> m_transfers;

	/**
	 * @brief converts a no in bytes to a string in B/KB/MB/GB
	 * @param bytes to convert
	 * @return converted string
	 */
	QString bytesToString(quint64 bytes) const;

};

}

#endif

