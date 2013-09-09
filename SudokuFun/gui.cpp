#include "gui.h"
#include "requestdialog.h"
#include "Grid.h"
#include "qmessagebox.h"
#include "qtimer.h"

gui::gui(QWidget *parent)
	: QMainWindow(parent)
{
	
	RequestDialog request;
	const int gridSize = request.ask(RequestDialog::REQUESTINGGRIDSIZE);
	const int sudokuSize = request.ask(RequestDialog::REQUESTINGSUDOKUSIZE);
	
	ui.setupUi(this);
	model = new sudokuModel(sudokuSize);
	ui.sudokuArea->setModel(model);
	ui.sudokuArea->setEditTriggers(QAbstractItemView::DoubleClicked);
	adjustAreaSize();

	curTime = 0;
	timer = new QTimer(this);
	timer->start(1000);
	ui.timer->display("00:00");
	
	

	QObject::connect(ui.resetButton,SIGNAL(clicked()),model,SLOT(resetModel()));
	QObject::connect(ui.regenerateButton,SIGNAL(clicked()),model,SLOT(generateNew()));
	QObject::connect(ui.resetButton,SIGNAL(clicked()),this,SLOT(timerReset()));
	QObject::connect(ui.regenerateButton,SIGNAL(clicked()),this,SLOT(timerReset()));
	QObject::connect(ui.autoButton,SIGNAL(clicked()),model,SLOT(autoComplete()));
	QObject::connect(model,SIGNAL(invokeMessageBox(sudokuModel::MSGTYPE)),this,SLOT(displayMessageBox(sudokuModel::MSGTYPE)));
	QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
}

gui::~gui()
{

}

void gui::adjustAreaSize()
{
	ui.sudokuArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.sudokuArea->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.sudokuArea->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.sudokuArea->resizeColumnsToContents();
	ui.sudokuArea->resizeRowsToContents();

	//rect.setWidth(2+ ui.sudokuArea->verticalHeader()->width() + ui.sudokuArea->columnWidth(0) * ui.sudokuArea->model()->columnCount());
	//ui.sudokuArea->setGeometry(rect);

}

/*
	Initializes bold borders for sudoku grids
*/
void gui::initializeBoldBorders()
{
	int gridDim= model->getGridDimensions();
	int sudokuDim = model->getGridDimensions();

}

void gui::resetAndUpdate()
{
	model->resetModel();
}

void gui::displayMessageBox(sudokuModel::MSGTYPE msgtype){
	QMessageBox msgbox(this);
	switch (msgtype){
	case sudokuModel::OUTOFRANGE:{
		msgbox.setText("You have entered a number that is out of this sudoku puzzle range. "
						"Please enter a valid one");
		msgbox.exec();
					}break;
	case sudokuModel::AUTOCOMPLETEFAILED:{
		msgbox.setText("Auto complete failed. Your current setup does not lead to any valid solutions.");
		msgbox.exec();
										 }break;
	case sudokuModel::SUDOKUCOMPLETED:{
		timer->stop();
		msgbox.setText("Sudoku Completed!");
		msgbox.exec();
									  }

										 


	}

}

void gui::timerUpdate(){
	curTime++;
	int minutes = curTime/60;
	QString dismin = minutes < 10? "0" + QString::number(minutes) : QString::number(minutes);
	int seconds = curTime%60;
	QString dissec = seconds < 10? "0" + QString::number(seconds) : QString::number(seconds);

	ui.timer->display(dismin + ":" + dissec);
}

void gui::timerReset(){
	curTime = 0;
	timer->start(1000);
	ui.timer->display("00:00");
}

