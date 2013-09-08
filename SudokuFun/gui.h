#ifndef GUI_H
#define GUI_H

#include <QtWidgets/QMainWindow>
#include "ui_gui.h"
#include "sudokumodel.h"


class gui : public QMainWindow
{
	Q_OBJECT



public:
	gui(QWidget *parent = 0);
	~gui();



private:
	

	Ui::guiClass ui;
	sudokuModel* model;
	void adjustAreaSize();
	void initializeBoldBorders();
	
private slots:
	void resetAndUpdate();
	void displayMessageBox(sudokuModel::MSGTYPE);
	
	
};

#endif // GUI_H
