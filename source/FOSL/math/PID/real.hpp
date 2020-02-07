#ifndef _FOSL_MATH_PID_FLOAT_HPP_
#define _FOSL_MATH_PID_FLOAT_HPP_

#include <FOSL/utility/math.hpp>

namespace FOSL
{
	namespace math
	{
		namespace PID
		{
			template <typename real_t>
			class real
			{
				public: // CONSTRUCTORS
					real(void) = default;
					real(real_t kp, real_t ki, real_t kd, real_t limit);
				public: // DESTRUCTOR
					~real(void) = default;

				public: // METHODS
					void initialize (real_t kp, real_t ki, real_t kd, real_t limit);
					void reset(void);

				public: // OPERATORS
					real_t operator()(real_t error);

				private:
					real_t kp;
					real_t ki;
					real_t kd;
					real_t limit;

					real_t error_sum;
					real_t last_error;
			};

			#include "FOSL/math/PID/real-impl.hpp"
		}
	}
}

#endif
