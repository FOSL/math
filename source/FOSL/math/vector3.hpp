#ifndef _FOSL_MATH_VECTOR3_HPP_
#define _FOSL_MATH_VECTOR3_HPP_

#include "FOSL/math/vector/fixed_size.hpp"

namespace FOSL
{
	namespace math
	{
		namespace vector
		{
			template <typename value_t>
			class fixed_size<value_t, uint8_t, 3> final
			{
				public:
					using type = fixed_size<value_t, uint8_t, 3>;

				public: // CONSTRUCTORS
					fixed_size(void) = default;
					fixed_size(value_t x, value_t y, value_t z);
				public: // DESTRUCTOR
					~fixed_size(void) = default;

				public: // VARIABLES
					value_t x, y, z;

				public: // METHODS
					// TODO

				public: // OPERATORS
					value_t &operator[](uint8_t index);
					operator value_t *(void);
					//
					fixed_size::type &operator +=(fixed_size::type const&other);
					fixed_size::type &operator -=(fixed_size::type const&other);
					fixed_size::type &operator *=(fixed_size::type const&other);
					fixed_size::type &operator /=(fixed_size::type const&other);
					//
					template <typename magnitude_t> fixed_size::type &operator *=(magnitude_t magnitude);
					template <typename magnitude_t> fixed_size::type &operator /=(magnitude_t magnitude);
					//
					fixed_size::type &operator -(void);
					//
					friend fixed_size::type operator +(fixed_size::type const&lhs, fixed_size::type const&rhs);
					friend fixed_size::type operator -(fixed_size::type const&lhs, fixed_size::type const&rhs);
					friend fixed_size::type operator *(fixed_size::type const&lhs, fixed_size::type const&rhs);
					friend fixed_size::type operator /(fixed_size::type const&lhs, fixed_size::type const&rhs);
			};

			#include "FOSL/math/vector3-impl.hpp"
		}

		template <typename value_t>
		using vector3 = vector::fixed_size<value_t, uint8_t, 3>;
	}
}

#endif
