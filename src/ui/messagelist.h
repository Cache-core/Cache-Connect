#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include <messageinformation.h>

#include <QObject>
#include <QAbstractListModel>
#include <QList>

namespace CacheConnect
{
class IClientManager;

/**
 * @brief provides all Messages send or recieved for GUI
 */
class MessageList : public QAbstractListModel
{
	Q_OBJECT
public:
	enum UserInfo {
		Sent = Qt::UserRole + 1,
		User,
		Message
	};

	explicit MessageList(IClientManager* cm, QObject* parent = nullptr);
	~MessageList();
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public Q_SLOTS:
	/**
	 * @brief adds new message provided to the message list
	 * @param mi Message to add to list
	 */
	void updateList(MessageInformation mi);

Q_SIGNALS:
	/**
	 * @brief emitted when new message is added
	 */
	void messagesAdded(int);

protected:
	QHash<int, QByteArray> roleNames() const;
	IClientManager *m_cm;

private:
	QList<MessageInformation> m_messages;

};

}

#endif

