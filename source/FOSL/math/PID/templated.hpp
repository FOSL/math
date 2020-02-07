#ifndef _FOSL_MATH_PID_TEMPLATED_HPP_
#define _FOSL_MATH_PID_TEMPLATED_HPP_

#include <FOSL/utility/math.hpp>

namespace FOSL
{
	namespace math
	{
		namespace PID
		{
			template <
				typename input_t,
				typename intermediate_t,
				typename output_t,
				intermediate_t kp,
				intermediate_t ki,
				intermediate_t kd,
				intermediate_t integral_limit,
				intermediate_t factor>
			class templated
			{
				public: // CONSTRUCTORS
					templated(void) = default;
				public: // DESTRUCTOR
					~templated(void) = default;

				public: // METHODS
					void initialize (void);
					void reset(void);

				public: // OPERATORS
					output_t operator()(input_t error);

				private:
					intermediate_t error_sum  = 0;
					intermediate_t last_error = 0;
			};

			#include "FOSL/math/PID/templated-impl.hpp"
		}
	}
}

#endif
