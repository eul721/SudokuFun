#ifndef SUDOKUFUNDELEGATE_H
#define SUDOKUFUNDELEGATE_H

#include <qstyleditemdelegate>

class sudokuFunDelegate : public QStyledItemDelegate
{
	Q_OBJECT

public:
	sudokuFunDelegate(QObject *parent);
	sudokuFunDelegate::sudokuFunDelegate(QObject *parent, int,int);
	~sudokuFunDelegate();
	void paint(QPainter* painter,const QStyleOptionViewItem & option, const QModelIndex & index);


private:
	const int _sudokuDimSize;
	const int _gridDimSize;
};

#endif // SUDOKUFUNDELEGATE_H
