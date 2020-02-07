// CONSTRUCTORS
template <typename value_t>
fixed_size<value_t, uint8_t, 3>::fixed_size(value_t x, value_t y, value_t z)
	: x(x), y(y), z(z)
{
}

// OPERATORS
template <typename value_t>
value_t &fixed_size<value_t, uint8_t, 3>::operator[](uint8_t index)
{
	return *(((value_t *) this) + index);
}
//
template <typename value_t>
fixed_size<value_t, uint8_t, 3> &fixed_size<value_t, uint8_t, 3>::operator +=(
	fixed_size::type const&other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}
template <typename value_t>
fixed_size<value_t, uint8_t, 3> &fixed_size<value_t, uint8_t, 3>::operator -=(
	fixed_size::type const&other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;

	return *this;
}
template <typename value_t>
fixed_size<value_t, uint8_t, 3> &fixed_size<value_t, uint8_t, 3>::operator *=(
	fixed_size::type const&other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;

	return *this;
}
template <typename value_t>
fixed_size<value_t, uint8_t, 3> &fixed_size<value_t, uint8_t, 3>::operator /=(
	fixed_size::type const&other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;

	return *this;
}
//
template <typename value_t>
template <typename magnitude_t>
fixed_size<value_t, uint8_t, 3> &fixed_size<value_t, uint8_t, 3>::operator *=(
	magnitude_t magnitude)
{
	this->x *= magnitude;
	this->y *= magnitude;
	this->z *= magnitude;

	return *this;
}
template <typename value_t>
template <typename magnitude_t>
fixed_size<value_t, uint8_t, 3> &fixed_size<value_t, uint8_t, 3>::operator /=(
	magnitude_t magnitude)
{
	this->x /= magnitude;
	this->y /= magnitude;
	this->z /= magnitude;

	return *this;
}
//
template <typename value_t>
fixed_size<value_t, uint8_t, 3> &fixed_size<value_t, uint8_t, 3>::operator-(void)
{
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->y;

	return *this;
}
//
template <typename value_t>
fixed_size<value_t, uint8_t, 3> operator +(
	fixed_size<value_t, uint8_t, 3> const&lhs,
	fixed_size<value_t, uint8_t, 3> const&rhs)
{
	fixed_size<value_t, uint8_t, 3> result;

	result  = lhs;
	result += rhs;

	return result;
}
template <typename value_t>
fixed_size<value_t, uint8_t, 3> operator -(
	fixed_size<value_t, uint8_t, 3> const&lhs,
	fixed_size<value_t, uint8_t, 3> const&rhs)
{
	fixed_size<value_t, uint8_t, 3> result;

	result  = lhs;
	result -= rhs;

	return result;
}
template <typename value_t>
fixed_size<value_t, uint8_t, 3> operator *(
	fixed_size<value_t, uint8_t, 3> const&lhs,
	fixed_size<value_t, uint8_t, 3> const&rhs)
{
	fixed_size<value_t, uint8_t, 3> result;

	result  = lhs;
	result *= rhs;

	return result;
}
template <typename value_t>
fixed_size<value_t, uint8_t, 3> operator /(
	fixed_size<value_t, uint8_t, 3> const&lhs,
	fixed_size<value_t, uint8_t, 3> const&rhs)
{
	fixed_size<value_t, uint8_t, 3> result;

	result  = lhs;
	result /= rhs;

	return result;
}
