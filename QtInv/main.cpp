#include "qtinv.h"
#include <QtWidgets/QApplication>

#include "qlayout.h"




int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	
	
	QtInv w;
	w.show();


	/*QWidget w;
	QVBoxLayout *vbox = new QVBoxLayout();


	QPushButton *button1 = new QPushButton("Button11");
	w.connect(button1, SIGNAL(clicked()), wid, SLOT(show()));

	QPushButton *button2 = new QPushButton("Button22");


	vbox->addWidget(button1);
	vbox->addWidget(button2);


	w.setLayout(vbox);
	w.show();*/

	//////////////////////////////////////////////
	
	/*QWidget wid;
	QVBoxLayout *vbox1 = new QVBoxLayout();


	CustomButton *button11 = new CustomButton("Button11");
	CustomButton *button22 = new CustomButton("Button22");


	vbox1->addWidget(button11);
	vbox1->addWidget(button22);


	wid.setLayout(vbox1);

	wid.show();*/

	
	return a.exec();
}
