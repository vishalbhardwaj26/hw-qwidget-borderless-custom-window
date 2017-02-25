#include "qtinv.h"
#include "customwindow.h"

QtInv::QtInv(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

QtInv::~QtInv()
{

}



void QtInv::on_pushButton_5_clicked()
{
	// use Qt designer to design and setup qss to create simple style around tabs and button
	CustomWindow *custWin = new CustomWindow;
	custWin->show();
}


