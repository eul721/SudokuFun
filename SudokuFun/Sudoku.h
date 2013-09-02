#pragma once
#include "grid.h"
#include <vector>
class Sudoku :
	public Grid
{
public:
	Sudoku(void);
	Sudoku(const int dimsize);
	~Sudoku(void);
	Sudoku(const Sudoku&);
	virtual bool isViolated() const;
	virtual void fill(int,int,int,fillOption);
private:
	const int sudokuDimSize;
	std::vector<Grid> grids;
	bool checkRowViolation(int) const;
	bool checkMainRowViolation(int) const;
	bool checkColViolation(int) const;
	void validate();
	virtual std::vector<Field> getRowElements(int) const;
	virtual std::vector<Field> getColElements(int) const;
};

