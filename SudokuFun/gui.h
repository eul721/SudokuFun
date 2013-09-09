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
	QTimer *timer;
	int curTime;
	
private slots:
	void resetAndUpdate();
	void displayMessageBox(sudokuModel::MSGTYPE);
	void timerUpdate();
	void timerReset();
	
	
};

#endif // GUI_H
