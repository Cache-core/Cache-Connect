import QtQuick 2.5
import QtQuick.Controls 2.1
import api.ui.cacheconnect 1.0

Item { id:item
	property string textColor
	property string bgColor
	property SideBar sideBar

	Connections{
		target: sideBar
		onMessengerClicked: {
			messenger.visible = true
			transferManager.visible = false
			appSettings.visible = false
		}
		onTransferManagerClicked: {
			messenger.visible = false
			transferManager.visible = true
			appSettings.visible = false
		}
		onSettingsClicked: {
			messenger.visible = false
			transferManager.visible = false
			appSettings.visible = true
		}
		onQuickConnectClicked: {
			quickConnect.open()
		}
		onFileTransferClicked: {
			fileTransfer.open()
		}
	}

	Messenger { id: messenger
		anchors.margins: 40
		anchors.fill: parent
		textColor: item.textColor
		bgColor: item.bgColor
	}

	TransferManager { id: transferManager
		anchors.margins: 40
		anchors.fill: parent
		textColor: item.textColor
		bgColor: item.bgColor
		visible: false
	}

	AppSettings { id: appSettings
		anchors.margins: 40
		anchors.fill: parent
		textColor: item.textColor
		bgColor: item.bgColor
		visible: false
	}

	QuickConnect{ id: quickConnect }

	FileTransfer{ id: fileTransfer }

	Notification { id: notification
		text: CacheConnect.notificationMsg
		status: CacheConnect.notificationStatus
	}
}
