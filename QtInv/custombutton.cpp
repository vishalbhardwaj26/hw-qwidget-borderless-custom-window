#include "custombutton.h"

#include <QPainter>

CustomButton::CustomButton(ButtonType type, QWidget *parent ) : QAbstractButton(parent),
  m_Type   (type        ),
  m_State  (STATE_NORMAL),
  m_Normal (NULL        ),
  m_Hovered(NULL        ),
  m_Clicked(NULL        )
{
    this->resize(20, 20);


}

CustomButton::~CustomButton()
{
  delete m_Normal ;
  delete m_Hovered;
  delete m_Clicked;
}

void CustomButton::resizeEvent(QResizeEvent *event)
{
  Q_UNUSED(event);

  InitPixmaps();
}

void CustomButton::paintEvent(QPaintEvent  *event)
{
  Q_UNUSED(event);

  QPainter painter(this);

  if(isEnabled())
  {
    switch(m_State)
    {
    case STATE_NORMAL:
      if(m_Normal  != NULL) painter.drawPixmap(0, 0, *m_Normal );
      break;
    case STATE_HOVERED:
      if(m_Hovered != NULL) painter.drawPixmap(0, 0, *m_Hovered);
      break;
    case STATE_CLICKED:
      if(m_Clicked != NULL) painter.drawPixmap(0, 0, *m_Clicked);
      break;
    }
  }
  else
  {
    if(m_Normal != NULL) painter.drawPixmap(0, 0, *m_Normal);
  }
}

void CustomButton::InitPixmaps()
{
  // Delete previous button
  InitPixmap(&m_Normal );
  InitPixmap(&m_Hovered);
  InitPixmap(&m_Clicked);

  switch(m_Type)
  {
  case BUTTON_MINIMIZE:
    InitMinimize();
    break;
  case BUTTON_MAXIMIZE:
    InitMaximize();
    break;
  case BUTTON_CLOSE:
    InitClose();
    break;
  }
}

void CustomButton::InitPixmap(QPixmap **pixmap)
{
  delete *pixmap;

  *pixmap = new QPixmap(size());

  (*pixmap)->fill(Qt::transparent);
}

void CustomButton::InitMinimize()
{
  /********** Button's border **********/
  QPolygon border;

  border << QPoint(          0,            4)
         << QPoint(          4,            0)
         << QPoint(width() - 1,            0)
         << QPoint(width() - 1, height() - 1)
         << QPoint(          0, height() - 1);
  /*************************************/

  /********** Button's symbol **********/
  QPolygon symbol;

  symbol << QPoint(          4, height()/2)
         << QPoint(width() - 4, height()/2)
         << QPoint(width() - 4, height()/2 + 2)
         << QPoint(          4, height()/2 + 2);
  /*************************************/

  QColor gradientStart(  0,   0,   0,   0);
  QColor gradientEnd  (  0,   0,   0, 220);

  QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
  linearGrad.setColorAt(0, gradientStart);
  linearGrad.setColorAt(1, gradientEnd  );

  QLinearGradient invertlinearGrad(QPointF(0, 0), QPointF(0, height()));
  invertlinearGrad.setColorAt(0, gradientEnd  );
  invertlinearGrad.setColorAt(1, gradientStart);

  QPainter painter;

  /********** Normal **********/
  painter.begin(m_Normal);

//  painter.setPen  (QPen(Qt::black   ));
//  painter.setBrush(QBrush(linearGrad));

//  painter.drawPolygon(border);

  painter.setPen  (Qt::NoPen        );
  painter.setBrush(QBrush(Qt::white));

  painter.drawPolygon(symbol);

  painter.end();
  /****************************/

  /********** Hovered **********/
  painter.begin(m_Hovered);

  painter.setPen  (QPen  (Qt::black ));
  painter.setBrush(QBrush(linearGrad));

  painter.drawPolygon(border);

  painter.setPen  (Qt::NoPen        );
  painter.setBrush(QBrush(Qt::white));

  painter.drawPolygon(symbol);

  painter.end();
  /*****************************/

  /********** Clicked **********/
  painter.begin(m_Clicked);

  painter.setPen  (QPen  (Qt::black       ));
  painter.setBrush(QBrush(invertlinearGrad));

  painter.drawPolygon(border);

  painter.setPen  (Qt::NoPen        );
  painter.setBrush(QBrush(Qt::white));

  painter.drawPolygon(symbol);

  painter.end();
  /*****************************/
}

void CustomButton::InitMaximize()
{
  /********** Button's border **********/
  QPolygon border;

  border << QPoint(          0,            0)
         << QPoint(width() - 5,            0)
         << QPoint(width() - 1,            4)
         << QPoint(width() - 1, height() - 1)
         << QPoint(          0, height() - 1);
  /*************************************/

  /********** Button's symbol **********/
  QPolygon symbol1, symbol2;

  symbol1 << QPoint(          4, 4)
          << QPoint(width() - 4, 4)
          << QPoint(width() - 4, 8)
          << QPoint(          4, 8);

  symbol2 << QPoint(          4,            8)
          << QPoint(width() - 4,            8)
          << QPoint(width() - 4, height() - 4)
          << QPoint(          4, height() - 4);
  /*************************************/

  QColor gradientStart(  0,   0,   0,   0);
  QColor gradientEnd  (  0,   0,   0, 220);

  QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
  linearGrad.setColorAt(0, gradientStart);
  linearGrad.setColorAt(1, gradientEnd  );

  QLinearGradient invertlinearGrad(QPointF(0, 0), QPointF(0, height()));
  invertlinearGrad.setColorAt(0, gradientEnd  );
  invertlinearGrad.setColorAt(1, gradientStart);

  QPainter painter;

  /********** Normal **********/
  painter.begin(m_Normal);

  painter.setPen  (QPen(Qt::black   ));
  painter.setBrush(QBrush(linearGrad));

  painter.drawPolygon(border);

  painter.setPen  (QPen  (Qt::white));
  painter.setBrush(QBrush(Qt::white));

  painter.drawPolygon(symbol1);

  painter.setPen  (QPen(Qt::white));
  painter.setBrush(Qt::NoBrush    );

  painter.drawPolygon(symbol2);

  painter.end();
  /****************************/

  /********** Hovered **********/
  painter.begin(m_Hovered);

  painter.setPen  (QPen  (Qt::black       ));
  painter.setBrush(QBrush(linearGrad));

  painter.drawPolygon(border);

  painter.setPen  (QPen  (Qt::white));
  painter.setBrush(QBrush(Qt::white));

  painter.drawPolygon(symbol1);

  painter.setPen  (QPen(Qt::white));
  painter.setBrush(Qt::NoBrush    );

  painter.drawPolygon(symbol2);

  painter.end();
  /*****************************/

  /********** Clicked **********/
  painter.begin(m_Clicked);

  painter.setPen  (QPen  (Qt::black ));
  painter.setBrush(QBrush(invertlinearGrad));

  painter.drawPolygon(border);

  painter.setPen  (QPen  (Qt::white));
  painter.setBrush(QBrush(Qt::white));

  painter.drawPolygon(symbol1);

  painter.setPen  (QPen(Qt::white));
  painter.setBrush(Qt::NoBrush    );

  painter.drawPolygon(symbol2);

  painter.end();
  /*****************************/
}

void CustomButton::InitClose()
{
  /********** Button's border **********/
  QPolygon border;

  border << QPoint(          0,            4)
         << QPoint(          4,            0)
         << QPoint(width() - 5,            0)
         << QPoint(width() - 1,            4)
         << QPoint(width() - 1, height() - 5)
         << QPoint(width() - 5, height() - 1)
         << QPoint(          4, height() - 1)
         << QPoint(          0, height() - 5);
  /*************************************/

  /********** Button's symbol **********/
  QLine symbol1(QPoint(          4, 4), QPoint(width() - 5, height() - 5));
  QLine symbol2(QPoint(width() - 5, 4), QPoint(          4, height() - 5));
  /*************************************/

  QColor gradientStart(  0,   0,   0,   0);
  QColor gradientEnd  (  0,   0,   0, 220);

  QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
  linearGrad.setColorAt(0, gradientStart);
  linearGrad.setColorAt(1, gradientEnd  );

  QLinearGradient invertlinearGrad(QPointF(0, 0), QPointF(0, height()));
  invertlinearGrad.setColorAt(0, gradientEnd  );
  invertlinearGrad.setColorAt(1, gradientStart);

  QPainter painter;

  /********** Normal **********/
  painter.begin(m_Normal);

  //painter.setPen  (QPen(Qt::black   ));
  painter.setBrush(QBrush(linearGrad));

  //painter.drawPolygon(border);

  painter.setPen(QPen(QBrush(Qt::white), 2.0));

  painter.drawLine(symbol1);
  painter.drawLine(symbol2);

  painter.end();
  /****************************/

  /********** Hovered **********/
  painter.begin(m_Hovered);

  painter.setPen  (QPen  (Qt::black ));
  painter.setBrush(QBrush(linearGrad));

  painter.drawPolygon(border);

  painter.setPen(QPen(QBrush(Qt::white), 2.0));

  painter.drawLine(symbol1);
  painter.drawLine(symbol2);

  painter.end();
  /*****************************/

  /********** Clicked **********/
  painter.begin(m_Clicked);

  painter.setPen  (QPen  (Qt::black       ));
  painter.setBrush(QBrush(invertlinearGrad));

  painter.drawPolygon(border);

  painter.setPen(QPen(QBrush(Qt::white), 2.0));

  painter.drawLine(symbol1);
  painter.drawLine(symbol2);

  painter.end();
  /*****************************/
}
void CustomButton::enterEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_State = STATE_HOVERED;

  update();
}

void CustomButton::leaveEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_State = STATE_NORMAL;

  update();
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
  QAbstractButton::mousePressEvent(event);

  m_State = STATE_CLICKED;

  update();
}

void CustomButton::mouseReleaseEvent(QMouseEvent *event)
{
  QAbstractButton::mouseReleaseEvent(event);

  if(underMouse()) m_State = STATE_HOVERED;
  else             m_State = STATE_NORMAL;

  update();
}
