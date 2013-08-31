#include "gui.h"
#include "requestdialog.h"
#include <QtWidgets/qapplication.h>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	gui w;
	w.show();
	return a.exec();
}
