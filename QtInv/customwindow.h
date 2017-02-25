
#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QtGui>
#include <QGridLayout>
#include <QSizeGrip>
#include "customtitlebar.h"


class CustomWindow : public QWidget
{
    Q_OBJECT

public:
    CustomWindow(QWidget *parent = 0);
    ~CustomWindow();

signals:
    void WindowTitleChanged();

protected:
    void showEvent(QShowEvent *event);
    void resizeEvent(QResizeEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
private:
    void CenterOnScreen();
    void paintEvent(QPaintEvent *event);

    void setWindowTitle(const QString &title);
    QGridLayout m_MainLayout;
    CustomTitleBar m_TitleBar;
    QSizeGrip m_SizeGrip;
    QPixmap *m_Cache;
    QPixmap *m_CacheHover;
    boolean m_hover;


};

#endif

