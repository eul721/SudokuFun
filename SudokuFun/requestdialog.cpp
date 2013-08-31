#include "requestdialog.h"

RequestDialog::RequestDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	
}

RequestDialog::~RequestDialog()
{

}

const int RequestDialog::ask(REQUESTTYPE req)
{
	if (req==REQUESTINGGRIDSIZE)
	{
		while(ui.requestLine->text().toInt()<=1){
			if(this->exec() == QDialog::Rejected)
				exit(-1);
			else{
				ui.requestQuestion->setText("You need to enter an integer that is greater than 1!");
			}
		}
		return ui.requestLine->text().toInt();
	}
	else if(req==REQUESTINGSUDOKUSIZE)
	{
		ui.requestLine->setText("");
		ui.requestQuestion->setText("What size, n^2, would you like to play in?");

		while(ui.requestLine->text().toInt()<=1){
			if(this->exec() == QDialog::Rejected)
				exit(-1);
			else{
				ui.requestQuestion->setText("You need to enter an integer that is greater than 1!");
			}
		}
	
		return  ui.requestLine->text().toInt();
	}
}

