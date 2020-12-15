#include "messagelist.h"

#include <interfaces/iclientmanager.h>
#include <messageinformation.h>

#include <QObject>
#include <QAbstractListModel>
#include <QList>

namespace CacheConnect
{

MessageList::MessageList(IClientManager* cm, QObject* parent) : QAbstractListModel(parent) , m_cm(cm)
{
	connect(cm,&IClientManager::messageAdded,this,&MessageList::updateList);
	QList<MessageInformation> miList = cm->messages();
	beginInsertRows(QModelIndex(), 0, miList.count()-1);
	m_messages = miList;
	endInsertRows();
}

MessageList::~MessageList()
{
}

int MessageList::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return m_messages.count();
}

QVariant MessageList::data(const QModelIndex& index, int role) const
{
	if (index.row() < 0 || index.row() >= m_messages.count())
		return QVariant();

	const MessageInformation &msg = m_messages[index.row()];
	if (role == Sent)
		return msg.sent();
	else if (role == User)
		return msg.user();
	else if (role == Message)
		return msg.msg();
	return QVariant();
}

void MessageList::updateList(MessageInformation mi)
{
	beginInsertRows(QModelIndex(), rowCount(), rowCount());
	m_messages.append(mi);
	endInsertRows();
	emit messagesAdded(1);
}

QHash<int, QByteArray> MessageList::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[Sent] = "sent";
	roles[User] = "user";
	roles[Message] = "message";
	return roles;
}

}

