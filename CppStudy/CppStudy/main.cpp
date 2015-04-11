#include <iostream>
#include <vector>
using namespace std;

#define RT		//从右上开始扫描
//#define LB		//从左下开始扫描

bool finds(int *array, int rows,int columns, int key)
{
	int i=0, j=columns-1;
	bool found = false;
	if (array != nullptr&&rows > 0 && columns > 0)
	{
#ifdef RT
		int row = 0;
		int column = columns - 1;
		while (row < rows&&column >= 0)
		{
			if (array[row*columns + column] == key)
			{
				found = true;
				break;
			}
			else if (array[row*columns + column]>key)
				--column;
			else
				++row;
		}
#endif
#ifdef LB
		int row = rows - 1;
		int column = 0;
		while (row >= 0 && column < columns)
		{
			if (array[row*columns + column] == key)
			{
				found = true;
				break;
			}
			else if (array[row*columns + column]>key)
				--row;
			else
				++column;
		}
#endif
	}
	return found;
}

int main()
{
	int a[4][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	cout << finds((int*)a, 4,4, 7) << endl;
	cout << finds((int*)a, 4,4, 5) << endl;
	cin.get();
}

