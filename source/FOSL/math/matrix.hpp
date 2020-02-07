#ifndef _FOSL_MATH_MATRIX_H_
#define _FOSL_MATH_MATRIX_H_

namespace fosl
{
	namespace math
	{
		template <typename T, size_t row_count, size_t column_count = row_count>
		class Matrix
		{
			public: // CONSTRUCTORS
				Matrix(void) = default;
			public: // DESTRUCTOR
				~Matrix(void) = default;

			public: // VARIABLES
			private:
				T values[row_count][column_count];

			public: // GETTERS
				size_t get_row_count();
				size_t get_column_count();
			public: // SETTERS

			public: // METHODS

			public: // OPERATORS
				T& operator[](size_t row_index, size_t column_index);
				Matrix<T, row_count, column_count>  operator+ (const Matrix<T, row_count, column_count>& rhs);
				Matrix<T, row_count, column_count>& operator+=(const Matrix<T, row_count, column_count>& other);
		};

		#include "fosl/math/matrix-impl.h"
	}
}

#endif
