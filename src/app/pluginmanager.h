/****************************************************************************
 * This file is part of System Preferences.
 *
 * Copyright (C) 2013 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Author(s):
 *    Pier Luigi Fiorini
 *
 * $BEGIN_LICENSE:GPL2+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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

#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QAbstractItemModel>
#include <QtQml/QQmlParserStatus>

#include "prefletsproxymodel.h"

class Plugin;
class PluginManagerPrivate;

typedef QMap<QString, Plugin *> PluginMap;
typedef QMap<QString, PluginMap> PluginsCollection;
typedef QList<Plugin *> PluginsList;
typedef QHash<QString, PrefletsProxyModel *> ModelHash;

class PluginManager : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
public:
    explicit PluginManager(QObject *parent = 0);
    ~PluginManager();

    PluginMap plugins(const QString &category) const;

    Q_INVOKABLE QAbstractItemModel *itemModel(const QString &category);
    Q_INVOKABLE QObject *getByName(const QString &name) const;

    void classBegin();
    void componentComplete();

private:
    Q_DECLARE_PRIVATE(PluginManager);
    PluginManagerPrivate *const d_ptr;
};

#endif // PLUGINMANAGER_H
