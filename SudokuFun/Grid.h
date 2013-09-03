#pragma once
#include <vector>

struct Field
	{
		int value;
		bool filled;
		int userAttemptedValue;
		void* belongsTo;
		
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
	const virtual std::vector<Field*> getRowElements(int rowNum) const;
	const virtual std::vector<Field*> getColElements(int colNum) const;
	const virtual std::vector<Field*> getGridElements() const;
	bool isViolated(const std::vector<int>& comparisonVector) const;

	//for debugging purposes
	void fill(int fieldNum,const int newVal,const fillOption fillO);
	

	
protected:
	const int dimSize;

	
	std::vector<Field> generateComparisonVec(int) const;
	const bool find(const int, std::vector<int>& reference) const;
	
	
private:
	const int gridSize;
	std::vector<Field*> elements;
	
};

