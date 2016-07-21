/****************************************************************************
 * This file is part of System Preferences.
 *
 * Copyright (C) 2016 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 * Copyright (C) 2015 Michael Spencer <sonrisesoftware@gmail.com>
 *
 * $BEGIN_LICENSE:GPL3+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

import QtQuick 2.4
import QtQuick.Controls 2.0
import Hawaii.Settings 1.0
import Fluid.Controls 1.0

Item {
    property int developerClickCount: 0
    readonly property int developerTotalClicks: 7
    readonly property int developerClickRemaining: developerTotalClicks - developerClickCount

    Settings {
        id: systemSettings
        schema.id: "org.hawaiios.system"
        schema.path: "/org/hawaiios/system/"
    }

    Column {
        id: column
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -40
        spacing: 8

        Image {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 128
            height: width

            source: Qt.resolvedUrl("logo.png")

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (systemSettings.developerMode)
                        return

                    developerClickCount++

                    print(developerClickCount, developerClickRemaining)

                    if (developerClickRemaining == 0) {
                        snackbar.open("You are now a developer!")
                        systemSettings.developerMode = true
                    } else if (developerClickRemaining <= 3) {
                        snackbar.open(("You are now %1 steps from becoming a " +
                                      "developer").arg(developerClickRemaining))
                    }
                }
            }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            Label {
                font.pixelSize: 40
                font.weight: Font.Light
                text: "qml"
            }

            Label {
                font.pixelSize: 40
                text: "OS"
            }
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 20
            text: "Version 0.0.0"
        }
    }

    Item {
        anchors {
            left: parent.left
            right: parent.right
            top: column.bottom
            bottom: parent.bottom
        }

        Row {
            anchors.centerIn: parent
            spacing: 16

            Button {
                text: "Website"
                onClicked: Qt.openUrlExternally("https://github.com/qmlos")
            }

            Button {
                text: "Report a bug"
                onClicked: Qt.openUrlExternally("https://github.com/qmlos/qmlos/issues")
            }

            Button {
                text: "Credits"
            }
        }
    }

/*
    Snackbar {
        id: snackbar
    }
*/
    Pane {
        id: snackbar
        anchors {
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        height: 48
        visible: false

        Label {
            id: label
        }

        Timer {
            id: timer
            interval: 2500
            onTriggered: snackbar.visible = false
        }

        function open(string) {
            label.text = string;
            snackbar.visible = true;
            timer.start();
        }
    }
}
