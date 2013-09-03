#include "Sudoku.h"
#include <ctime>
#include <algorithm>

bool find(const int, const std::vector<Field*>*);
bool find(const Field* target, const std::vector<Field*>* refVec);

/*----------------------------------------
	Generate default 9x9 Sudoku Game.
	Still invalid.
-----------------------------------------*/
Sudoku::Sudoku(void):
	Grid(3),sudokuDimSize(3*3),grids(std::vector<Grid*>(3))
{
	std::srand((unsigned)std::time(0));
	for (int i=0;i<sudokuDimSize;i++)
		grids[i] = new Grid(dimSize);

	initializeComparisonVector();


}

/*----------------------------------------
	Generate sizexsize Sudoku Game.
	Still invalid.
-----------------------------------------*/
Sudoku::Sudoku(const int size):
	Grid(size),sudokuDimSize(size*size),grids(std::vector<Grid*>(sudokuDimSize))
{
	std::srand((unsigned)std::time(0));
	for (int i=0;i<sudokuDimSize;i++)
		grids[i] = new Grid(dimSize);

	initializeComparisonVector();
}



Sudoku::~Sudoku(void)
{
	for (int i=0;i<sudokuDimSize;i++)
		delete grids[i];
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
		if(grids[i]->isViolated(comparisonVector))
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
	std::vector<int> renewedComparisonVector(comparisonVector);
	std::vector<Field*> mainRow;
	mainRow = getRowElements(rowNum);
	for (std::vector<Field*>::const_iterator cit = mainRow.cbegin();
		 cit!=mainRow.cend();
		 cit++)
	{
		if (!find((*cit)->userAttemptedValue,renewedComparisonVector))
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
	std::vector<int> renewedComparisonVector(comparisonVector);
	std::vector<Field*> mainCol;
	mainCol = getColElements(colNum);
	for (std::vector<Field*>::const_iterator cit = mainCol.cbegin();
		 cit!=mainCol.end();
		 cit++)
	{
		if (!find((*cit)->userAttemptedValue,renewedComparisonVector))
			return true;
	}


	return false;

}

bool Sudoku::generate(int rowNum,int colNum)
{
	if (rowNum > sudokuDimSize)
		return true;
	
	//Get a vector of possible values for the field at [rowNum]x[colNum]
	std::vector<int> possibleValues = removeConflictValues(getField(rowNum,colNum));
	std::random_shuffle(possibleValues.begin(),possibleValues.end());
	
	//prepare an iterator for iterating through the values in [possibleValues]
	std::vector<int>::const_iterator cit = possibleValues.cbegin();

	

	//if not, there are some possible values worth trying.
	//enter a while loop. Plug the value in, and run generate 
	//recursively into the next val

		while(cit!=possibleValues.cend())
		{
			fill(rowNum,colNum,*cit,GENERATOR);
			int nextFieldRowNum = 0, nextFieldColNum = 0;
			if (colNum + 1 > sudokuDimSize) //if at the end of a row
			{
				nextFieldRowNum = rowNum + 1;
				nextFieldColNum = 1;
			}
			else //if not, just the field beside it
			{
				nextFieldRowNum = rowNum;
				nextFieldColNum = colNum + 1;
			}

			if (generate(nextFieldRowNum,nextFieldColNum))
				return true;
			else
				cit = possibleValues.erase(cit);
			fill(rowNum,colNum,0,GENERATOR);
		}
		//if cbegin()=cend(), it means that there are no possible values left.
		//need to backtrack. Return false here
		return false; //if no values work, backtrack
	
	

}
/*----------------------------------------
	Get Sudoku row number n.
-----------------------------------------*/
const std::vector<Field*> Sudoku::getRowElements(int rowNum) const
{
	std::vector<Field*> mainRow;

	//move step counter to the according SudokuRow 
	int step=1;
	while (rowNum > step*dimSize) step++;

	for (int i=0;i<dimSize;i++)
	{
		const std::vector<Field*> gridRow = grids.at((step-1)*dimSize + i)->getRowElements(((rowNum-1) % dimSize)+1);
		mainRow.insert(mainRow.end(),gridRow.begin(),gridRow.end());
	}

	return mainRow;

}
/*----------------------------------------
	Get Sudoku col number n.
-----------------------------------------*/
const std::vector<Field*> Sudoku::getColElements(int colNum) const
{
	std::vector<Field*> mainCol;

	//move step counter to the according SudokuRow 
	int step=1;
	while (colNum > step*dimSize) step++;

	for (int i=0;i<dimSize;i++)
	{
		const std::vector<Field*> gridCol = grids.at((step-1) + i*dimSize)->getColElements(((colNum-1) % dimSize)+1);
		mainCol.insert(mainCol.end(),gridCol.begin(),gridCol.end());
	}

	return mainCol;

}

bool Sudoku::checkMainRowViolation(int mainRowNum) const{

	return false;
}

void Sudoku::fill(int rowNum, int colNum,int newVal,fillOption fillO)
{
	Field* field = getField(rowNum,colNum);

	if (fillO == GENERATOR)
	{
		field->value = newVal;
	}
	else
	{
		if (!field->filled)
			field->filled = true;
	}
		field->userAttemptedValue = newVal;
}

void Sudoku::initializeComparisonVector(){
	for (int i=1;i<=sudokuDimSize;i++)
		comparisonVector.push_back(i);
}
const std::vector<Field*> Sudoku::getRowElements(const Field* refField) const
{
	int step = 1;
	std::vector<Field*> row = getRowElements(step);
	while (!::find(refField,&row))
		row = getRowElements(step++);
	return row;
}
const std::vector<Field*> Sudoku::getColElements(const Field* refField) const
{
	int step = 1;
	std::vector<Field*> col = getColElements(step);
	while (!::find(refField,&col)){
		step++;
		col = getColElements(step);
	}
	return col;
}
const std::vector<Field*> Sudoku::getGridElements(const Field* refField) const
{
	Grid* grid = (Grid*) refField->belongsTo;
	return grid->getGridElements();
}
std::vector<int> Sudoku::removeConflictValues(const Field* refField) const
{
	std::vector<int> refreshedVec(comparisonVector);
	const std::vector<Field*> colWhereFieldResides = getColElements(refField);
	const std::vector<Field*> rowWhereFieldResides = getRowElements(refField);
	const std::vector<Field*> gridWhereFieldResides = getGridElements(refField);
	std::vector<int>::const_iterator it = refreshedVec.cbegin();
	while(it != refreshedVec.cend())
	{
		if (::find(*it,&colWhereFieldResides) || ::find(*it,&rowWhereFieldResides) || ::find(*it,&gridWhereFieldResides))
			it = refreshedVec.erase(it);
		else it++;
	}
	return refreshedVec;
	
}

Field* Sudoku::getField(int rowNum,int colNum)
{
	std::vector<Field*> row = getRowElements(rowNum);
	return row[colNum-1];
}

bool find(const int target, const std::vector<Field*>* refVec)
{
	for (std::vector<Field*>::const_iterator cit = refVec->cbegin();
		cit != refVec->cend();
		cit++){
		if ((*cit)->userAttemptedValue == target)
			return true;
	}
	return false;
}
bool find(const Field* target, const std::vector<Field*>* refVec)
{
	for (std::vector<Field*>::const_iterator cit = refVec->begin();
		cit != refVec->cend();
		cit++)
	{
		if (*cit == target)
			return true;
	}
	return false;
}
