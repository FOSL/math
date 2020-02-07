#ifndef _FOSL_MATH_VECTOR_FIXED_SIZE_HPP_
#define _FOSL_MATH_VECTOR_FIXED_SIZE_HPP_

#include <FOSL/utility/math.hpp>

namespace FOSL
{
	namespace math
	{
		namespace vector
		{
			template <typename value_t, typename dimensions_t, dimensions_t dimensions>
			class fixed_size final
			{
				public:
					using type = fixed_size<value_t, dimensions_t, dimensions>;
				private:
					struct array final { value_t values[dimensions]; };

				public: // CONSTRUCTORS
					fixed_size(void) = default;
					template <typename ...value_ts>
					fixed_size(value_ts... values);
				public: // DESTRUCTOR
					~fixed_size(void) = default;

				private: // VARIABLES
					value_t values[dimensions];

				public: // METHODS
					// TODO

				public: // OPERATORS
					value_t &operator[](dimensions_t index);
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

			#include "FOSL/math/vector/fixed_size-impl.hpp"
		}
	}
}

#endif
