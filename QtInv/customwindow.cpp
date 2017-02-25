
#include "customwindow.h"

#include <QDesktopWidget>

CustomWindow::CustomWindow(QWidget *parent)
    : QWidget(parent) , m_TitleBar(this) , m_SizeGrip(this)
{
    m_hover = false;
    m_Cache = NULL;
    m_CacheHover = NULL;
    connect(this       , SIGNAL(WindowTitleChanged()),
        &m_TitleBar, SLOT  (UpdateWindowTitle ()));

    setMinimumSize(350,330);
    resize(512, 512);
    setWindowTitle(tr("Qt CustomWindow"));
    setWindowFlags(Qt::FramelessWindowHint);

    m_MainLayout.setMargin(0);  // No space between window's element and the border
    m_MainLayout.setSpacing(0); // No space between window's element
    setLayout(&m_MainLayout);

    m_MainLayout.addWidget(&m_TitleBar, 0, 0, 1, 1);

    m_MainLayout.setRowStretch(1, 1); // Put the title bar at the top of the window

    m_SizeGrip.setStyleSheet("image: none");

    setAttribute(Qt::WA_TranslucentBackground);
}

CustomWindow::~CustomWindow()
{

}

void CustomWindow::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    CenterOnScreen();
}

void CustomWindow::CenterOnScreen()
{
    QDesktopWidget screen;

    QRect screenGeom = screen.screenGeometry(this);

    int screenCenterX = screenGeom.center().x();
    int screenCenterY = screenGeom.center().y();

    move(screenCenterX - width () / 2,
        screenCenterY - height() / 2);
}

void CustomWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    if(m_hover == true && m_CacheHover != NULL)
    {
        QPainter painter(this);

        painter.drawPixmap(0, 0, *m_CacheHover);
    }

    if(m_hover == false && m_Cache != NULL)
    {
        QPainter painter(this);

        painter.drawPixmap(0, 0, *m_Cache);
    }
}

void CustomWindow::setWindowTitle(const QString &title)
{
    QWidget::setWindowTitle(title);

    emit WindowTitleChanged();
}

void CustomWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    delete m_Cache;
    delete m_CacheHover;

    m_Cache = new QPixmap(size());
    m_CacheHover = new QPixmap(size());

    m_Cache->fill(Qt::transparent);
    m_CacheHover->fill(Qt::transparent);




    /********** Window's frame **********/
    QPolygon frame;

    frame << QPoint(           4,            4)
        << QPoint(width() -  4,             4)
        << QPoint(width() -  4, height()-4)
           << QPoint(4, height()-4);

     QPainter painter(m_Cache);
    painter.setPen  (QPen(QColor("#FF949199"),2));
    painter.setBrush(QColor("#FF25252B"));
    painter.drawPolygon(frame);


    /***********BLUE border on highlight**************************/
     QPainter painter1(m_CacheHover);
     painter1.setPen  (QPen(QColor("#FF4C8EFF"),2));
     painter1.setBrush(QColor("#FF25252B"));
     painter1.drawPolygon(frame);
    /*****************************************/

    m_SizeGrip.move  (width() - 32, height() - 49);
    m_SizeGrip.resize(          32,            32);
}

void CustomWindow::enterEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_hover = true;

  update();
}

void CustomWindow::leaveEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_hover = false;

  update();
}


