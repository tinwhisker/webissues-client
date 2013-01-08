/**************************************************************************
* This file is part of the WebIssues Desktop Client program
* Copyright (C) 2006 Michał Męciński
* Copyright (C) 2007-2012 WebIssues Team
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
**************************************************************************/

#ifndef USERPROJECTSDIALOG_H
#define USERPROJECTSDIALOG_H

#include "dialogs/informationdialog.h"
#include "xmlui/client.h"

class UserProjectsModel;

class QTreeView;
class QModelIndex;

/**
* Dialog for managing user projects.
*/
class UserProjectsDialog : public InformationDialog, public XmlUi::Client
{
    Q_OBJECT
public:
    /**
    * Constructor.
    * @param userId Identifier of the user.
    * @param parent The parent widget.
    */
    UserProjectsDialog( int userId, QWidget* parent );

    /**
    * Destructor.
    */
    ~UserProjectsDialog();

private slots:
    void addProjects();
    void changeAccess();
    void removeProjects();

    void updateActions();

    void doubleClicked( const QModelIndex& index );
    void listContextMenu( const QPoint& pos );

private:
    int m_userId;

    QTreeView* m_list;
    UserProjectsModel* m_model;

    QList<int> m_selectedProjects;
};

#endif