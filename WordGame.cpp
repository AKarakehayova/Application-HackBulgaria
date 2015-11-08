// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void checkRows(char** matrix, char* word, int row, int column, int index, int& count, int lastCol,int length)
{

	bool stillOnWord = true;
	cout << "bool" << endl;
	int j = 1;
	while (j + column < lastCol && j < length && stillOnWord)
	{
		cout << "while" << endl;
		if (word[index + j] != matrix[row][column + j])
		{
			stillOnWord = false;
			cout << "bool=false" << endl;
		}
		if (index + j >= length-1)
		{
			count++;
			cout << "count change" << endl;
		}
		j++;
		cout << "J>"<<endl;
	}
}


void checkRowsReverse(char**matrix, char* word, int row, int column, int index, int& count)
{
	bool stillOnWord = true;
	int length = strlen(word);
	int j = 1;
	while (column - j > 0 && j < length && stillOnWord)
	{
		if (word[index + j] != matrix[row][column - j])
		{
			stillOnWord = false;
		}
		if (index + j >= length-1)
		{
			count++;
		}
		j++;
	}
}

void checkColumns(char** matrix, char* word, int row, int column, int index, int& count, int lastRow)
{
	bool stillOnWord = true;
	int length = strlen(word) - 1;
	int i = 1;
	while (row + i < lastRow && i < length  && stillOnWord)
	{
		if (word[index + i] != matrix[row + i][column])
		{
			stillOnWord = false;
		}
		if (index + i >= length-1)
		{
			count++;
		}
		i++;
	}
}

void checkColumnsReverse(char**matrix, char* word, int row, int column, int index, int& count)
{

	bool stillOnWord = true;
	int length = strlen(word);
	int i = 1;
	while (row - i > 0 && i < length && stillOnWord)
	{
		if (word[index + i] != matrix[row - i][column])
		{
			stillOnWord = false;
		}
		if (index + i >= length-1)
		{
			count++;
		}
		i++;
	}

}

void checkMainDiagonals(char**matrix, char* word, int row, int column, int index, int& count, int lastRow, int lastCol)
{

	bool stillOnWord = true;
	int length = strlen(word);
	int i = 1;
	while (row + i <lastRow && column + i< lastCol && i < length && stillOnWord)
	{
		if (word[index + i] != matrix[row + i][column + i])
		{
			stillOnWord = false;
		}
		if (index + i >= length-1)
		{
			count++;
		}
		i++;
	}

}

void checkSecondDiagonals(char**matrix, char*word, int row, int column, int index, int& count, int lastRow)
{

	bool stillOnWord = true;
	int length = strlen(word);
	int i = 1;
	while (row + i < lastRow && column - i>0 && i < length && stillOnWord)
	{
		if (word[index + i] != matrix[row + i][column - i])
		{
			stillOnWord = false;
		}
		if (index + i >= length-1)
		{
			count++;
		}
		i++;
	}
}

void checkMainDiagReverse(char**matrix, char* word, int row, int column, int index, int& count)
{

	bool stillOnWord = true;
	int length = strlen(word);
	int i = 1;
	while (column - i > 0 && row - i > 0 && i < length && stillOnWord)
	{
		if (word[index + i] != matrix[row - i][column - i])
		{
			stillOnWord = false;
		}
		if (index + i >= length-1)
		{
			count++;
		}
		i++;
	}
}

void checkSecondDiagReverse(char**matrix, char* word, int row, int column, int index, int& count, int lastCol)
{
	bool stillOnWord = true;
	int length = strlen(word);
	int i = 1;
	while (row - i>0 && column + i<lastCol && i < length && stillOnWord)
	{
		if (word[index + i] != matrix[row - i][column + i])
		{
			stillOnWord = false;
		}
		if (index + i >= length-1)
		{
			count++;
		}
		i++;
	}

}
int main()
{
	int n, m;
	int count = 0;
	int length;
	cout << "The word is long:" << endl;
	cin >> length;
	char* word = new char[length];
	cout << "Input the number of the rows: " << endl;
	cin >> n;
	cout << "Input the number of the columns: " << endl;
	cin >> m;
	char** table = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		table[i] = new char[m];
	}

	cout << "Input the elements of the table:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "table[" << i << "][" << j << "]: " << endl;
			cin >> table[i][j];
		}
	}
	cout << "Now input the word: " << endl;
	cin >> word;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (table[i][j] == word[0])
			{
			
				checkRows(table, word, i, j, 0, count, m,length);
				checkRowsReverse(table, word, i, j, 0, count);
				checkColumns(table, word, i, j, 0, count, n);
				checkColumnsReverse(table, word, i, j, 0, count);
				checkMainDiagonals(table, word, i, j, 0, count, n, m);
				checkMainDiagReverse(table, word, i, j, 0, count);
				checkSecondDiagonals(table, word, i, j, 0, count, n);
				checkSecondDiagReverse(table, word, i, j, 0, count, m);
			}
		}
	}
	cout << "The word count is: " << count;
	for (int i = 0; i < n; ++i) {
		delete[] table[i];
	}
	delete[] table;
	delete[] word;
	return 0;
}
