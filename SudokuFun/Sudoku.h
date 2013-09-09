#pragma once
#include "grid.h"
#include <vector>
class Sudoku :
	public Grid
{
public:
	Sudoku(void);
	Sudoku(const int dimsize);
	Sudoku(const Sudoku&);
	Sudoku& operator=(const Sudoku&);
	~Sudoku(void);
	virtual bool isViolated() const;
	virtual void fill(int,int,int,fillOption);

	int getSudokuDimSize(){ return sudokuDimSize;}
	int getGridDimSize(){ return dimSize;}
	

	const Field* getField(int rowNum,int colNum) const;
	Field* getField(int, int);
	std::vector<int> removeConflictValues(const Field*) const;
	bool generate(int rowNum, int colNum);
	void resetSudoku();
	bool sudokuComplete() const;
private:
	const int sudokuDimSize;
	std::vector<int> comparisonVector;
	std::vector<Grid*> grids;
	bool checkRowViolation(int) const;
	bool checkMainRowViolation(int) const;
	bool checkColViolation(int) const;
	void randomizeFilledRatio();
	
	void initializeComparisonVector();
	const virtual std::vector<Field*> getRowElements(int) const;
	const virtual std::vector<Field*> getColElements(int) const;
	const virtual std::vector<Field*> getRowElements(const Field*) const;
	const virtual std::vector<Field*> getColElements(const Field*) const;
	const virtual std::vector<Field*> getGridElements(const Field*) const;

	
	
};

