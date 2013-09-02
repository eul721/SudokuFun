#include "Sudoku.h"
#include <ctime>

bool find(const std::vector<Field>::iterator& , std::vector<Field>&);

/*----------------------------------------
	Generate default 9x9 Sudoku Game.
	Still invalid.
-----------------------------------------*/
Sudoku::Sudoku(void):
	sudokuDimSize(3*3)
{
	std::srand(std::time(0));
	for (int i=0;i<sudokuDimSize;i++)
		grids.push_back(Grid(dimSize));


}

/*----------------------------------------
	Generate sizexsize Sudoku Game.
	Still invalid.
-----------------------------------------*/
Sudoku::Sudoku(const int size):
	Grid(size),sudokuDimSize(size*size)
{
	std::srand(std::time(0));
	for (int i=0;i<sudokuDimSize;i++)
		grids.push_back((Grid)*this);

}



Sudoku::~Sudoku(void)
{
}

Sudoku::Sudoku(const Sudoku& oriSudoku):
	Grid(oriSudoku.dimSize),sudokuDimSize(oriSudoku.sudokuDimSize),grids(oriSudoku.grids)
{
	
}

/*----------------------------------------
	Checks if sudoku is violated.
-----------------------------------------*/
bool Sudoku::isViolated() const
{
	for (int i=0;i<sudokuDimSize;i++){
		if(grids[i].isViolated())
			return true;
	}
	for (int i=1;i<=sudokuDimSize;i++){
		if(checkRowViolation(i))
			return true;
		if(checkColViolation(i))
			return true;
	}

	return false;
}

/*----------------------------------------
	Check if Sudoku row number N
	is violated. 
-----------------------------------------*/
bool Sudoku::checkRowViolation(const int rowNum) const
{
	static const std::vector<Field>comparisonVector(generateComparisonVec(sudokuDimSize));
	std::vector<Field> renewedComparisonVector(comparisonVector);
	std::vector<Field> mainRow;
	mainRow = getRowElements(rowNum);
	for (std::vector<Field>::iterator it = mainRow.begin();
		 it!=mainRow.end();
		 it++)
	{
		if (!find(it,renewedComparisonVector))
			return true;
	}


	return false;

}

/*----------------------------------------
	Check if Sudoku col number N
	is violated. 
-----------------------------------------*/
bool Sudoku::checkColViolation(const int colNum) const
{
	static const std::vector<Field>comparisonVector(generateComparisonVec(sudokuDimSize));
	std::vector<Field> renewedComparisonVector(comparisonVector);
	std::vector<Field> mainCol;
	mainCol = getColElements(colNum);
	for (std::vector<Field>::iterator it = mainCol.begin();
		 it!=mainCol.end();
		 it++)
	{
		if (!find(it,renewedComparisonVector))
			return true;
	}


	return false;

}

/*----------------------------------------
	Make the sudoku valid
-----------------------------------------*/
void Sudoku::validate()
{
	while(isViolated())
		grids = std::vector<Grid>(sudokuDimSize,Grid(dimSize));
}

/*----------------------------------------
	Get Sudoku row number n.
-----------------------------------------*/
std::vector<Field> Sudoku::getRowElements(int rowNum) const
{
	std::vector<Field> mainRow;

	//move step counter to the according SudokuRow 
	int step=1;
	while (rowNum > step*dimSize) step++;

	for (int i=0;i<dimSize;i++)
	{
		std::vector<Field> gridRow = grids.at((step-1)*dimSize + i).getRowElements((rowNum-1 % dimSize)+1);
		mainRow.insert(mainRow.end(),gridRow.begin(),gridRow.end());
	}

	return mainRow;

}
/*----------------------------------------
	Get Sudoku col number n.
-----------------------------------------*/
std::vector<Field> Sudoku::getColElements(int colNum) const
{
	std::vector<Field> mainCol;

	//move step counter to the according SudokuRow 
	int step=1;
	while (colNum > step*dimSize) step++;

	for (int i=0;i<dimSize;i++)
	{
		std::vector<Field> gridCol = grids.at((step-1) + i*dimSize).getRowElements((colNum-1 & dimSize)+1);
		mainCol.insert(mainCol.end(),gridCol.begin(),gridCol.end());
	}

	return mainCol;

}

bool Sudoku::checkMainRowViolation(int mainRowNum) const{

	return false;
}

void Sudoku::fill(int gridNum, int fieldNum,int newVal,fillOption fillO)
{
	grids[gridNum].fill(fieldNum,newVal,fillO);
}