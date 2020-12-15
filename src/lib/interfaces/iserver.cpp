#include "iserver.h"

#include <QTcpServer>

namespace CacheConnect
{

IServer::IServer(QObject *parent) : QTcpServer(parent){}

IServer::~IServer(){}

}
