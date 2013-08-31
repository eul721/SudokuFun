#include "Grid.h"
#include <math.h>

Grid::Grid(void)
	:gridSize(3*3),elements(std::vector<int>(3*3))
{
}


Grid::~Grid(void)
{
}

Grid::Grid(const int gridSize)
	:gridSize(gridSize*gridSize),elements(std::vector<int>(gridSize*gridSize))
{

}