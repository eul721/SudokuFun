#ifndef SUDOKUMODEL_H
#define SUDOKUMODEL_H

#include <QAbstractTableModel>
#include "Sudoku.h"

class sudokuModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	sudokuModel(QObject *parent);
	sudokuModel(int);
	~sudokuModel();
	int getGridDimensions() const {return gridDimensions;}
	
	enum MSGTYPE{
		OUTOFRANGE = 0,
		SUDOKUCOMPLETED = 1,
		AUTOCOMPLETEFAILED = 2
	};

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	int getSudokuDimensions() const;
	bool setData(const QModelIndex& index, const QVariant& value,int role);
	QVariant data(const QModelIndex &index , int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
signals:
	void editCompleted(int);
	void invokeMessageBox(sudokuModel::MSGTYPE);
public slots:
	void resetModel();
	void generateNew();
	

private:
	int sudokuDimensions;
	int gridDimensions;
	Sudoku* sudoku;
	Sudoku resetTarget;
private slots:
	void autoComplete();
};

#endif // SUDOKUMODEL_H
