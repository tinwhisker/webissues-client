/*
 * Borrowed from
 * https://stackoverflow.com/questions/36446246/how-to-emulate-linkclickedqurl-signal-in-qwebengineview
 */

#ifndef WIWEBENGINEPAGE_H
#define WIWEBENGINEPAGE_H

#include <QWebEnginePage>

class WIWebEnginePage : public QWebEnginePage
{
    Q_OBJECT
public:
    WIWebEnginePage(QObject* parent = 0) : QWebEnginePage(parent){}

    bool acceptNavigationRequest(const QUrl & url, QWebEnginePage::NavigationType type, bool)
    {
        if (type == QWebEnginePage::NavigationTypeLinkClicked)
        {
            emit linkClicked(url);
            return false;
        }
        return true;
    }

signals:
    void linkClicked(const QUrl&);
};

#endif // WIWEBENGINEPAGE_H
