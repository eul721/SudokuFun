#pragma once
#include <vector>
class Grid
{
public:
	Grid(void);
	Grid(const int gridSize);
	~Grid(void);
private:
	const int gridSize;
	std::vector<int> elements;
protected:
	bool gridViolated() const;
	std::vector<int> getRowElements(int rowNum) const;
	std::vector<int> getColElements(int colNum) const;

};

