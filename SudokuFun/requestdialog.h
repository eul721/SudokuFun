#ifndef REQUESTDIALOG_H
#define REQUESTDIALOG_H

#include <QDialog>
#include "ui_requestdialog.h"

class RequestDialog : public QDialog
{
	Q_OBJECT

	
public:
	enum REQUESTTYPE{REQUESTINGGRIDSIZE = 0, REQUESTINGSUDOKUSIZE=1};
	RequestDialog(QWidget *parent = 0);
	~RequestDialog();
	const int ask(REQUESTTYPE);


private:
	Ui::RequestDialog ui;
};

#endif // REQUESTDIALOG_H
