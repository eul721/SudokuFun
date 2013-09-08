#include "sudokumodel.h"
#include <qfont.h>


sudokuModel::sudokuModel(QObject *parent)
	: QAbstractTableModel(parent)
{

}

sudokuModel::sudokuModel(int dim)
	:sudokuDimensions(dim*dim),gridDimensions(dim),sudoku(new Sudoku(dim)),resetTarget(new Sudoku(*sudoku))
{
}

sudokuModel::~sudokuModel()
{
	
}

int sudokuModel::getSudokuDimensions() const
{
	return sudokuDimensions;
}
QVariant sudokuModel::data(const QModelIndex &index , int role) const {
	switch(role){
		case Qt::DisplayRole:
			{
				const Field* indexedField = sudoku->getField(index.row()+1 ,index.column()+1);

				return indexedField->filled? QString::number(indexedField->userAttemptedValue) : " ";
			} break;
		case Qt::FontRole:
			{
				QFont stretchedFont;
				stretchedFont.setPixelSize(35);
				return stretchedFont;
			} break;
		case Qt::TextAlignmentRole:
			{
				return Qt::AlignHCenter +Qt::AlignVCenter;
			}
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

void sudokuModel::resetModel()
{
	delete sudoku; //delete original model first
	sudoku =  new Sudoku(*resetTarget);

	emit dataChanged(createIndex(0,0),createIndex(sudokuDimensions-1,sudokuDimensions-1));
}

void sudokuModel::generateNew()
{
	delete sudoku;
	sudoku = new Sudoku(gridDimensions);
	delete resetTarget;
	resetTarget = new Sudoku(*sudoku);

	emit dataChanged(createIndex(0,0),createIndex(sudokuDimensions-1,sudokuDimensions-1));
}

bool sudokuModel::setData(const QModelIndex& index, const QVariant& value,int role)
{
	if(role==Qt::EditRole){
		if (value.toInt()<1 ||value.toInt()>sudokuDimensions){
			emit invokeMessageBox(OUTOFRANGE);
		}
		else{
		sudoku->fill(index.row()+1,index.column()+1,value.toInt(),Grid::PLAYER);
		emit editCompleted(value.toInt());}
	}
	return true;


	
}

Qt::ItemFlags sudokuModel::flags(const QModelIndex &index) const
{
	return Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

void sudokuModel::autoComplete(){
	if (sudoku->generate(1,1))
		emit invokeMessageBox(SUDOKUCOMPLETED);
	else
		emit invokeMessageBox(AUTOCOMPLETEFAILED);
}
