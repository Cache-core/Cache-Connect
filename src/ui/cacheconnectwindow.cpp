#include "cacheconnectwindow.h"

#include <interfaces/icontrolcenter.h>
#include <interfaces/iusersettings.h>
#include "uimanager.h"
#include "messenger.h"

#include <QObject>
#include <QQmlApplicationEngine>
#include <QAbstractListModel>
#include <QQmlContext>

namespace CacheConnect
{

CacheConnectWindow::CacheConnectWindow()
{
	qmlRegisterSingletonType<UiManager>("api.ui.cacheconnect",1,0,"CacheConnect",UiManager::uimanager_singleton);
}

CacheConnectWindow::~CacheConnectWindow()
{
}

void CacheConnectWindow::show()
{
	m_engine.load(QUrl("qrc:/resources/MainWindow.qml"));
}

}
