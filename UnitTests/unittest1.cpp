#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SudokuFun/Grid.h"
#include <Sudoku.h>
#include <iostream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;




namespace UnitTests
{		
	
	TEST_CLASS(SudokuTests)
	{
	public:
		
		TEST_METHOD(sudokuViolated)
		{
			Sudoku s1(3);
			Assert::IsFalse(s1.isViolated());
			s1.fill(1,1,1,Grid::PLAYER);
			s1.fill(1,2,1,Grid::PLAYER);
			Assert::IsTrue(s1.isViolated());
		}
		TEST_METHOD(sudokuGenerate)
		{
			Sudoku s1(3);
			s1.generate(1,1);
			Assert::IsFalse(s1.isViolated());
		}
		TEST_METHOD(sudokuAutoGenerate){
			Sudoku s1(2);
			Assert::IsTrue(s1.generate(1,1));
		}

		TEST_METHOD(sudokuCopyCon)
		{
			Sudoku s1(2);
			Sudoku s2(s1);
			for (int i=0;i<3;i++){
				Assert::IsTrue(s1.getField(1,1)->value == s2.getField(1,1)->value);
				Assert::IsTrue(s1.getField(1,1)->userAttemptedValue == s2.getField(1,1)->userAttemptedValue);
				Assert::IsTrue(s1.getField(1,1)->filled == s2.getField(1,1)->filled);
				Assert::IsFalse(s1.getField(1,1)->belongsTo == s2.getField(1,1)->belongsTo);
			}

			
		}

		
		
	};
	TEST_CLASS(GridTests)
	{
	public:
		TEST_METHOD(GridsIsViolated)
		{
			std::vector<int> comparisonVector;
			for (int i=1;i<=9;i++)
			{comparisonVector.push_back(i);}
			Grid* g1 = new Grid;
			for (int i=1;i<=9;++i)
				g1->fill(i,i,Grid::GENERATOR);
			//grid is perfectly legit atm
			Assert::IsFalse(g1->isViolated(comparisonVector));
			//now, break rules
			g1->fill(5,1,Grid::PLAYER);
			Assert::IsTrue(g1->isViolated(comparisonVector));
		}
	};

	

}