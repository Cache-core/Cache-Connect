#include "iclientmanager.h"

#include <QObject>

namespace CacheConnect
{

IClientManager::IClientManager(QObject* parent) : QObject(parent) {}

IClientManager::~IClientManager() {}

}
