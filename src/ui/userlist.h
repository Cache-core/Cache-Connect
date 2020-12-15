#ifndef USERLIST_H
#define USERLIST_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>

namespace CacheConnect
{
class IClientManager;
class ClientInformation;

/**
 * @brief List of all available clients
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class UserList : public QAbstractListModel
{
	Q_OBJECT
public:
	enum UserInfo {
		Name = Qt::UserRole + 1,
		Id,
		Ip
	};

	explicit UserList(IClientManager* cm, QObject* parent = nullptr);
	~UserList();
	int rowCount(const QModelIndex & parent = QModelIndex()) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

public Q_SLOTS:
	/**
	 * @brief updates the list of clients
	 */
	void updateList();

protected:
	QHash<int, QByteArray> roleNames() const;
	IClientManager *m_cm;

private:
	QList<ClientInformation> m_users;

};

}

#endif
