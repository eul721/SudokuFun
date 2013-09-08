#include "sudokufundelegate.h"
#include <qpainter.h>

sudokuFunDelegate::sudokuFunDelegate(QObject *parent)
	: QStyledItemDelegate(parent),_sudokuDimSize(9),_gridDimSize(3)
{

}
sudokuFunDelegate::sudokuFunDelegate(QObject *parent, int sudokuDimSize, int gridDimSize)
	: QStyledItemDelegate(parent),_sudokuDimSize(sudokuDimSize),_gridDimSize(gridDimSize)
{
	
}

sudokuFunDelegate::~sudokuFunDelegate()
{

}


void sudokuFunDelegate::paint(QPainter* painter,const QStyleOptionViewItem & option, const QModelIndex & index)
{


		


}
