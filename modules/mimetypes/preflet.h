/****************************************************************************
 * This file is part of Settings.
 *
 * Copyright (C) 2011-2016 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
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

#ifndef PREFLET_H
#define PREFLET_H

#include <Hawaii/Settings/PreferencesModule>

class QTranslator;

namespace Ui
{
    class MimeTypesPreflet;
}

class TypesModel;

namespace Hawaii
{
    namespace Settings
    {
        class Preflet : public PreferencesModule
        {
            Q_OBJECT
        public:
            explicit Preflet();
            ~Preflet();

            virtual QString name() const;
            virtual QString comment() const;
            virtual QString iconName() const;
            virtual QStringList keywords() const;
            virtual PreferencesModule::Category category() const;

        protected:
            void changeEvent(QEvent *event);

        private:
            Ui::MimeTypesPreflet *ui;
            QTranslator *m_translator;
            TypesModel *m_model;

            void loadTranslations();
        };
    }
}

#endif // PREFLET_H
