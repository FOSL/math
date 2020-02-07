// CONSTRUCTORS
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
template <typename ...value_ts>
fixed_size<value_t, dimensions_t, dimensions>::fixed_size(value_ts... values)
{
	*((array *) &this->values) = { values... };
}

// OPERATORS
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
value_t &fixed_size<value_t, dimensions_t, dimensions>::operator[](dimensions_t index)
{
	return values[index];
}
//
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
fixed_size<value_t, dimensions_t, dimensions> &fixed_size<value_t, dimensions_t, dimensions>::operator +=(
	fixed_size::type const&other)
{
	for (dimensions_t i = 0; i < dimensions; i++)
		values[i] += other.values[i];

	return *this;
}
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
fixed_size<value_t, dimensions_t, dimensions> &fixed_size<value_t, dimensions_t, dimensions>::operator -=(
	fixed_size::type const&other)
{
	for (dimensions_t i = 0; i < dimensions; i++)
		values[i] -= other.values[i];

	return *this;
}
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
fixed_size<value_t, dimensions_t, dimensions> &fixed_size<value_t, dimensions_t, dimensions>::operator *=(
	fixed_size::type const&other)
{
	for (dimensions_t i = 0; i < dimensions; i++)
		values[i] *= other.values[i];

	return *this;
}
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
fixed_size<value_t, dimensions_t, dimensions> &fixed_size<value_t, dimensions_t, dimensions>::operator /=(
	fixed_size::type const&other)
{
	for (dimensions_t i = 0; i < dimensions; i++)
		values[i] /= other.values[i];

	return *this;
}
//
template <typename value_t, typename dimensions_t, dimensions_t dimensions> template <typename magnitude_t>
fixed_size<value_t, dimensions_t, dimensions> &fixed_size<value_t, dimensions_t, dimensions>::operator *=(
	magnitude_t magnitude)
{
	for (dimensions_t i = 0; i < dimensions; i++)
		values[i] *= magnitude;

	return *this;
}
template <typename value_t, typename dimensions_t, dimensions_t dimensions> template <typename magnitude_t>
fixed_size<value_t, dimensions_t, dimensions> &fixed_size<value_t, dimensions_t, dimensions>::operator /=(
	magnitude_t magnitude)
{
	static_assert(!sizeof(magnitude_t)&&"TODO! (bootstrap for Marek Ličko)");
}
//
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
fixed_size<value_t, dimensions_t, dimensions>& fixed_size<value_t, dimensions_t, dimensions>::operator-(void)
{
	for (dimensions_t i = 0; i < dimensions; i++)
		values[i] = -values[i];

	return *this;
}
//
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
fixed_size<value_t, dimensions_t, dimensions> operator +(
	fixed_size<value_t, dimensions_t, dimensions> const&lhs,
	fixed_size<value_t, dimensions_t, dimensions> const&rhs)
{
	fixed_size<value_t, dimensions_t, dimensions> result;

	result  = lhs;
	result += rhs;

	return result;
}
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
fixed_size<value_t, dimensions_t, dimensions> operator -(
	fixed_size<value_t, dimensions_t, dimensions> const&lhs,
	fixed_size<value_t, dimensions_t, dimensions> const&rhs)
{
	fixed_size<value_t, dimensions_t, dimensions> result;

	result  = lhs;
	result -= rhs;

	return result;
}
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
fixed_size<value_t, dimensions_t, dimensions> operator *(
	fixed_size<value_t, dimensions_t, dimensions> const&lhs,
	fixed_size<value_t, dimensions_t, dimensions> const&rhs)
{
	fixed_size<value_t, dimensions_t, dimensions> result;

	result  = lhs;
	result *= rhs;

	return result;
}
template <typename value_t, typename dimensions_t, dimensions_t dimensions>
fixed_size<value_t, dimensions_t, dimensions> operator /(
	fixed_size<value_t, dimensions_t, dimensions> const&lhs,
	fixed_size<value_t, dimensions_t, dimensions> const&rhs)
{
	fixed_size<value_t, dimensions_t, dimensions> result;

	result  = lhs;
	result /= rhs;

	return result;
}
