#include "gui.h"
#include "requestdialog.h"
#include "Grid.h"

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

