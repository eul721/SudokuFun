#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QMainWindow>
#include "ui_gui.h"

class gui : public QMainWindow
{
	Q_OBJECT

public:
	gui(QWidget *parent = 0);
	~gui();

private:
	Ui::guiClass ui;
	void adjustAreaSize();
};

#endif // GUI_H
