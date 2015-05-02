/****************************************************************************
 * This file is part of System Preferences.
 *
 * Copyright (C) 2013-2015 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Author(s):
 *    Pier Luigi Fiorini
 *
 * $BEGIN_LICENSE:LGPL2.1+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

import QtQuick 2.0
import Hawaii.Themes 1.0 as Themes

Item {
    id: root

    property int minimumWidth: Themes.Units.dp(800)
    property int minimumHeight: Themes.Units.dp(600)

    Row {
        anchors {
            centerIn: parent
            margins: Themes.Units.largeSpacing
        }
        spacing: Themes.Units.largeSpacing

        Selector {
            type: "background"
            text: qsTr("Background")
        }

        Selector {
            type: "lockscreen"
            text: qsTr("Lock Screen")
        }
    }
}
