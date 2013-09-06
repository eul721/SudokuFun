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

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	int dimCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index , int role) const;

private:
	int sudokuDimensions;
	Sudoku* sudoku;
};

#endif // SUDOKUMODEL_H
