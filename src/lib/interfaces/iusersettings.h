#ifndef IUSERSETTINGS_H
#define IUSERSETTINGS_H

#include <QObject>

namespace CacheConnect
{
/**
 * Provides information about user and application
 * @author Shashwat Dixit <shashwatdixit124@gmail.com>
 */
class IUserSettings : public QObject
{
	Q_OBJECT

public:
	/**
	 * @brief returns our ip address
	 * @return ip address
	 */
	Q_INVOKABLE virtual QString ip() = 0;

	/**
	 * @brief if application is running first time on this machine
	 * @return true if running first time, false otherwise
	 */
	Q_INVOKABLE virtual bool runningFirstTime() = 0;

	/**
	 * @brief provides the username
	 * @return username
	 */
	Q_INVOKABLE virtual QString name() = 0;

	/**
	 * @brief provides the default download directory
	 * @return default download directory
	 */
	Q_INVOKABLE virtual QString downloadDir() = 0;

	/**
	 * @brief provides the color theme
	 * @return hex color string
	 */
	Q_INVOKABLE virtual QString theme() = 0;

	/**
	 * @brief updates the username with name provided
	 * @param name new username
	 */
	Q_INVOKABLE virtual void setName(QString name) = 0;

	/**
	 * @brief updates the download dir with dir provided
	 * @return ddir new Download Directory
	 */
	Q_INVOKABLE virtual void setDownloadDir(QString ddir) = 0;

	/**
	 * @brief updates the color theme with color provided
	 * @return color new hex color
	 */
	Q_INVOKABLE virtual void setTheme(QString color) = 0;

protected:
	/**
	 * @brief Constructor
	 */
	explicit IUserSettings();

	/**
	 * @brief Destructor
	 */
	~IUserSettings();

};

}

#endif
