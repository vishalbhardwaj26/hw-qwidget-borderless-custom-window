#ifndef CUSTOMTITLEBAR_H
#define CUSTOMTITLEBAR_H

#include <QObject>
#include "QWidget"
#include "QPixmap"
#include "custombutton.h"
#include <QLabel>

class CustomTitleBar : public QWidget
{
    Q_OBJECT
public:

    explicit CustomTitleBar(QWidget *parent = 0);
      ~CustomTitleBar();
protected:
  void resizeEvent(QResizeEvent *event);
  void paintEvent (QPaintEvent  *event);
  void mouseMoveEvent(QMouseEvent* event);
      void mousePressEvent(QMouseEvent* event);
      void mouseReleaseEvent(QMouseEvent* event);
signals:

public slots:
  void UpdateWindowTitle();
  void Minimized();
  void Maximized();
  void Quit     ();


private:
    bool mMoving;
    QPoint mLastMousePosition;
  QLabel m_Title;
  QPixmap *m_Cache;

  CustomButton m_Minimize;
  CustomButton m_Maximize;
  CustomButton m_Close;

};

#endif // CUSTOMTITLEBAR_H
