#pragma once
#include <vector>

struct Field
	{
		int value;
		bool filled;
		int userAttemptedValue;
	};

class Grid
{
public:
	Grid(void);
	Grid(const int gridDimSize);
	Grid(const Grid&);
	~Grid(void);
	Grid& operator=(const Grid&);
	
	enum fillOption {GENERATOR = 0, PLAYER = 1};
	
	//these are provided for sudoku class to use
	virtual std::vector<Field> getRowElements(int rowNum) const;
	virtual std::vector<Field> getColElements(int colNum) const;
	bool isViolated() const;
	void fill(int fieldNum,const int newVal,const fillOption fillO);
	

	
protected:
	const int dimSize;

	std::vector<Field> generateComparisonVec(int) const;
	const bool find(const std::vector<Field>::const_iterator& it, std::vector<Field>& reference) const;
	
	
private:
	const int gridSize;
	std::vector<Field> elements;
	
};

