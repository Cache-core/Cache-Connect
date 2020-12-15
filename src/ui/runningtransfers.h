#ifndef RUNNINGTRANSFERS_H
#define RUNNINGTRANSFERS_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>

namespace CacheConnect
{
class ITransferManager;
class File;

/**
 * @brief List of all Running Transfers for GUI
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class RunningTransfers : public QAbstractListModel
{
	Q_OBJECT
public:
	enum UserInfo {
		Id  = Qt::UserRole + 1,
		FileName,
		FilePath,
		FileSize,
		Url,
		ClientName,
		Progress,
		Transfered,
		Rate,
		TimeRemaining
	};

	explicit RunningTransfers(ITransferManager* tm, QObject* parent = nullptr);
	~RunningTransfers();
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public Q_SLOTS:
	/**
	 * @brief updates the list
	 */
	void updateList();
	/**
	 * @brief update a specific transfer
	 * @param id of a transfer to update
	 * @param prog percentage of trasnfer completed
	 * @param transfered total transfer completed
	 * @param rate rate of recieving data
	 */
	void updateProgress(qint16,int,quint64,int);

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

	/**
	 * @brief converts time remaining for a file from integer in sec to min in string
	 * @param f file to convert time for
	 * @return converted string
	 */
	QString timeForFile(File f) const;

};

}

#endif

