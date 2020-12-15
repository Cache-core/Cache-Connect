#include "messenger.h"

#include <interfaces/iclientmanager.h>

#include <QObject>
#include <QDebug>

namespace CacheConnect
{

Messenger::Messenger(IClientManager* cc) : m_cm(cc)
{
}

Messenger::~Messenger()
{
}

void Messenger::sendMessage(int id, QString msg)
{
	m_cm->sendMessage(id,msg);
}

}
