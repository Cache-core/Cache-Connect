#include "iclient.h"

#include "iconnection.h"

#include <QObject>

namespace CacheConnect
{

IClient::IClient(QObject* parent) : QObject(parent)
{
}

IClient::~IClient(){}

}
