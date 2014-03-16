/*****************************************************************************
 *                                    matrix.h
 *
 * ÓÃvectorÄ£Äâ¾ØÕó.
 *
 * JiangChao, 2014-03-16
 *****************************************************************************/

#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>

using namespace std;

namespace kxiaoc
{
	template<typename T>
	class matrix
	{
	private:
		vector<vector<T>> array;
	public:
		matrix(int rows, int cols) : array(rows)
		{
			for (int i = 0; i < rows; i++)
				array[i].resize(cols);
		}

		const vector<T>& operator[](int row) const { return array[row]; }
		vector<T>& operator[](inst row) { return array[row]; }
		int numrows() const { return array.size(); }
		int numcols() const { return numrows() ? array[0].size() : 0; }
	};
}

#endif