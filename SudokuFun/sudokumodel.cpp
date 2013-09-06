#include "sudokumodel.h"


sudokuModel::sudokuModel(QObject *parent)
	: QAbstractTableModel(parent)
{

}

sudokuModel::sudokuModel(int dim)
	:sudokuDimensions(dim*dim),sudoku(new Sudoku(dim))
{
}

sudokuModel::~sudokuModel()
{
	
}

int sudokuModel::dimCount(const QModelIndex &parent) const
{
	return sudokuDimensions;
}
QVariant sudokuModel::data(const QModelIndex &index , int role) const {
	if (role==Qt::DisplayRole)
	{
		Field* indexedField = sudoku->getField(index.row()+1 ,index.column()+1);
		return indexedField->filled? QString::number(indexedField->userAttemptedValue) : " ";
	}
	return QVariant();
}

int sudokuModel::rowCount(const QModelIndex &parent ) const
{
	return sudokuDimensions;
}
int sudokuModel::columnCount(const QModelIndex &parent) const{
	return sudokuDimensions;
}