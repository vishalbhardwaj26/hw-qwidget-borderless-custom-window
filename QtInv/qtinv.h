#ifndef QTINV_H
#define QTINV_H

#include <QtWidgets/QMainWindow>
#include "ui_qtinv.h"

class QtInv : public QMainWindow
{
	Q_OBJECT

public:
	QtInv(QWidget *parent = 0);
	~QtInv();


private:
	Ui::QtInvClass ui;

private slots:
	void on_pushButton_5_clicked();	
};

#endif // QTINV_H
