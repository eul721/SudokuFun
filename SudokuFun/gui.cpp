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

}

gui::~gui()
{

}
