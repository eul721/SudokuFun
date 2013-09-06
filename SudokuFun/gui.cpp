#include "gui.h"
#include "requestdialog.h"
#include "Grid.h"
#include "sudokumodel.h"

gui::gui(QWidget *parent)
	: QMainWindow(parent)
{
	
	RequestDialog request;
	const int gridSize = request.ask(RequestDialog::REQUESTINGGRIDSIZE);
	const int sudokuSize = request.ask(RequestDialog::REQUESTINGSUDOKUSIZE);
	
	ui.setupUi(this);
	sudokuModel* model = new sudokuModel(sudokuSize);
	this->ui.sudokuArea->setModel(model);
	this->ui.sudokuArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	adjustAreaSize();
}

gui::~gui()
{

}

void gui::adjustAreaSize()
{
	ui.sudokuArea->resizeColumnsToContents();
	QRect rect = ui.sudokuArea->geometry();
	rect.setWidth(2+ ui.sudokuArea->verticalHeader()->width() + ui.sudokuArea->columnWidth(0) * ui.sudokuArea->model()->columnCount());
	ui.sudokuArea->setGeometry(rect);

}