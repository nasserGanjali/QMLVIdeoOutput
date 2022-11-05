import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtMultimedia 5.4
import com.yourcompany.FrameProvider 1.0

ApplicationWindow {
    objectName: "mainWindow"
    visible: true
    width: 640
    height: 480

    FrameProvider{
        objectName: "provider"
        id: provider
    }

    VideoOutput {
        id: display
        objectName: "display"
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: parent.width
        source: provider
    }
}
