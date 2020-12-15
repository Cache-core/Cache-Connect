#ifndef CACHECONNECTWINDOW_H
#define CACHECONNECTWINDOW_H

#include <QQmlApplicationEngine>

namespace CacheConnect
{
class IControlCenter;
class UiManager;

/**
 * @brief Window for CacheConnect GUI
 */
class CacheConnectWindow
{

public:
	explicit CacheConnectWindow();
	~CacheConnectWindow();

	/**
	 * @brief loads the gui pages
	 */
	void show();

protected:
	QQmlApplicationEngine m_engine;
};

}

#endif
