// GETTERS
template <typename T, size_t row_count, size_t column_count>
constexpr size_t Matrix<T, row_count, column_count>::get_row_count()
{
	return row_count;
}
template <typename T, size_t row_count, size_t column_count>
constexpr size_t Matrix<T, row_count, column_count>::get_column_count()
{
	return column_count;
}

// OPERATORS
template <typename T, size_t row_count, size_t column_count>
T& Matrix<T, row_count, column_count>::operator[](size_t row_index, size_t column_index)
{
	return values[row_index][column_index];
}
template <typename T, size_t row_count, size_t column_count>
Matrix<T, row_count, column_count> Matrix<T, row_count, column_count>
::operator+(const Matrix<T, row_count, column_count>& rhs)
{
	Matrix<T, row_count, column_count> result;

	result  = *this;
	result += rhs;

	return result;
}
template <typename T, size_t row_count, size_t column_count>
Matrix<T, row_count, column_count>& Matrix<T, row_count, column_count>
::operator+=(const Matrix<T, row_count, column_count>& other)
{

	for (size_t row_index = 0; row_index < row_count; row_index++)
		for (size_t column_index = 0; column_index < column_count; column_index++)
			values[row_index][column_index] += other.values[row_index][column_index];

	return *this;
}
