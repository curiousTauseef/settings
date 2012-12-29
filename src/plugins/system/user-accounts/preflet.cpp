/****************************************************************************
 * This file is part of System Preferences.
 *
 * Copyright (C) 2011-2012 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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

#include "preflet.h"
#include "ui_preflet.h"

using namespace Hawaii::SystemPreferences;

Preflet::Preflet()
    : PreferencesModule()
    , ui(new Ui::Preflet)
{
    ui->setupUi(this);

    ui->addButton->setIcon(QIcon::fromTheme("list-add"));
    ui->removeButton->setIcon(QIcon::fromTheme("list-remove"));
    ui->pictureButton->setIcon(QIcon::fromTheme("list-add"));
}

Preflet::~Preflet()
{
    delete ui;
}

QString Preflet::name() const
{
    return tr("User Accounts");
}

QString Preflet::comment() const
{
    return tr("Create new users, change users' details such as real name and " \
              "icon, manage administrators and groups.");
}

QString Preflet::iconName() const
{
    return "preferences-desktop-user";
}

QStringList Preflet::keywords() const
{
    return tr("user;account;password;administrator;real name").split(";");
}

PreferencesModule::Category Preflet::category() const
{
    return PreferencesModule::SystemCategory;
}

#include "moc_preflet.cpp"
