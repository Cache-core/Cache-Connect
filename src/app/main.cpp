#include "controlcenter.h"
#include "cacheconnectwindow.h"

#include <iostream>
#include <QApplication>
#include <QLoggingCategory>
#include <QIcon>

using namespace CacheConnect;

int main(int argc, char* argv[])
{
	QApplication a(argc,argv);
	a.setApplicationName("CacheConnect");
	a.setOrganizationName("CacheConnect");
	a.setOrganizationDomain("https://cxche.org");
	a.setApplicationVersion("1.0");

	QLoggingCategory::setFilterRules(QStringLiteral("cacheconnect.transferrigor=false\n"));

	ControlCenter::init();
	QObject::connect(&a,&QApplication::aboutToQuit,ControlCenter::instance(),&ControlCenter::shutdown);
	CacheConnectWindow w;
	w.show();

	a.exec();
	ControlCenter::quit();
	return 0;
}
