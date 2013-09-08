#include "Grid.h"
#include <math.h>
#include <algorithm>
#include <ctime>




/*----------------------------------------
	Default Constructor of Grid 3x3
	Consturctors first fill in the elements
	vector with respective index values
	from 1~n. Then, a function is called
	to shuffle them.
-----------------------------------------*/
Grid::Grid(void)
	:gridSize(3*3),dimSize(3),elements(std::vector<Field*>(gridSize,NULL))
{
	//fill in a number into each position of an array, according to index
	//initialize the grid such that at the buttom it is actually filled with number, but may not be visible depending on boolean [filled].
	for (int i=0;i<gridSize;i++){
		elements[i] = new Field;
		elements[i]->value = 0;
		elements[i]->filled = false;
		elements[i]->userAttemptedValue = 0;
		elements[i]->belongsTo = this;
	}

	std::random_shuffle(elements.begin(),elements.end());

}

/*----------------------------------------
	Default Destructor
-----------------------------------------*/
Grid::~Grid(void)
{
	for (int i=0;i<gridSize;i++)
		delete elements[i];
}

/*----------------------------------------
	Default Constructor of Grid nxn
	Consturctors first fill in the elements
	vector with respective index values
	from 1~n. Then, a function is called
	to shuffle them.
-----------------------------------------*/
Grid::Grid(const int gridDimSize)
	:gridSize(gridDimSize*gridDimSize),dimSize(gridDimSize),elements(std::vector<Field*>(gridSize,NULL))
{
	//fill in a number into each position of an array, according to index
	for (int i=0;i<this->gridSize;i++){
		elements[i] = new Field;
		elements[i]->value = 0;
		elements[i]->filled = false;
		elements[i]->userAttemptedValue = 0;
		elements[i]->belongsTo = this;
	}
	std::random_shuffle(elements.begin(),elements.end());
}

/*----------------------------------------
	Copy Constructor that will be used 
	when a backup grid (Sudoku) is needed.
-----------------------------------------*/
Grid::Grid(const Grid& oriGrid) :
	gridSize(oriGrid.gridSize),dimSize(oriGrid.dimSize),elements(std::vector<Field*>(gridSize,NULL))
{
	
	for (int i=0;i<this->gridSize;i++){
		elements[i] = new Field;
		elements[i]->filled = oriGrid.elements[i]->filled;
		elements[i]->userAttemptedValue = oriGrid.elements[i]->userAttemptedValue;
		elements[i]->value = oriGrid.elements[i]->value;
		elements[i]->belongsTo = this;
	}

}

/*----------------------------------------
	Copy Assignment to replace a grid for
	regeneration purposes
-----------------------------------------*/
Grid& Grid::operator=(const Grid& newGrid)
{
	elements = newGrid.elements;

	return *this;

}
/*----------------------------------------
	A function that checks if a grid violates
	Sudoku grid condition. 
-----------------------------------------*/
bool Grid::isViolated(const std::vector<int>& comparisonVector) const
{
	std::vector<int>renewedComparisonVector(comparisonVector);
	for (std::vector<Field*>::const_iterator it = elements.cbegin();
		it != elements.end();
		it++)
	{
		if ((*it)->value == 0)
		{
			//0 means the field has yet to be filled. ignore.
		}
		else if (!find((*it)->userAttemptedValue,renewedComparisonVector))
			return true;
	}

	return false;
}

/*----------------------------------------
	Retrieve row elements
-----------------------------------------*/
const std::vector<Field*> Grid::getRowElements(int rowNum) const
{
	std::vector<Field*> row;
	for (int i=0;i<dimSize;i++)
		row.push_back(elements.at((rowNum-1)*dimSize+i));

	return row;
}
/*----------------------------------------
	Retrieve col elements
-----------------------------------------*/
const std::vector<Field*> Grid::getColElements(int colNum) const
{
	std::vector<Field*> col;
	for (int i=0;i<dimSize;i++)
		col.push_back(elements.at(i*dimSize + (colNum - 1)));

	return col;
}

const std::vector<Field*> Grid::getGridElements() const
{
	return elements;
}

/*----------------------------------------
	This outputs a comparison vector that 
	will be used for constraint checking purposes
-----------------------------------------*/
std::vector<Field> Grid::generateComparisonVec(int gridSize) const {

	std::vector<Field> comp;
	for (int i=1;i<=gridSize;i++){
		Field f;
		f.filled = true;
		f.value = i;
		f.userAttemptedValue = i;
		comp.push_back(f);
	}
	return comp;
}


/*----------------------------------------
	This function checks whether the provided
	value at *cit can be found in comparison vector.
	If it's found, remove that corresponding field
	from the comparison vector and return true. Else, just
	return false.
-----------------------------------------*/
const bool Grid::find(const int valToFind, std::vector<int>& reference) const{
	for (std::vector<int>::iterator rit = reference.begin();
		rit!=reference.end();
		rit++){
			if (valToFind == *rit){
				reference.erase(rit);
				return true;}
	}
	return false;
}

/*----------------------------------------
	This function fills the grid at specific 
	index with specific value. 
-----------------------------------------*/
void Grid::fill(int fieldNum,const int newVal,const fillOption fillO = PLAYER)
{
	fieldNum--;
	if (fillO == GENERATOR)
	{
		elements[fieldNum]->value = newVal;
	}
	else
	{
		if (!elements[fieldNum]->filled)
			elements[fieldNum]->filled = true;
	}
		elements[fieldNum]->userAttemptedValue = newVal;

}

const Field* Grid::getField(int index) const{
	return elements[index];
}