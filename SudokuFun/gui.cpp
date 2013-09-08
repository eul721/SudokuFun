#include "gui.h"
#include "requestdialog.h"
#include "Grid.h"
#include "qmessagebox.h"

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
	QObject::connect(ui.resetButton,SIGNAL(clicked()),model,SLOT(resetModel()));
	QObject::connect(ui.regenerateButton,SIGNAL(clicked()),model,SLOT(generateNew()));
	QObject::connect(ui.autoButton,SIGNAL(clicked()),model,SLOT(autoComplete()));
	QObject::connect(model,SIGNAL(invokeMessageBox(sudokuModel::MSGTYPE)),this,SLOT(displayMessageBox(sudokuModel::MSGTYPE)));
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
		msgbox.setText("Sudoku Completed!");
		msgbox.exec();
									  }

										 


	}

}
