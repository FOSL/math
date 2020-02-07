// METHODS
template <
	typename input_t,
	typename intermediate_t,
	typename output_t,
	intermediate_t kp,
	intermediate_t ki,
	intermediate_t kd,
	intermediate_t integral_limit,
	intermediate_t factor>
void templated<
	input_t,
	intermediate_t,
	output_t,
	kp,
	ki,
	kd,
	integral_limit,
	factor>
::initialize(void)
{
}
template <
	typename input_t,
	typename intermediate_t,
	typename output_t,
	intermediate_t kp,
	intermediate_t ki,
	intermediate_t kd,
	intermediate_t integral_limit,
	intermediate_t factor>
void templated<
	input_t,
	intermediate_t,
	output_t,
		kp,
	ki,
	kd,
	integral_limit,
	factor>
::reset(void)
{
	error_sum  = 0;
	last_error = 0;
}

// OPERATORS
template <
	typename input_t,
	typename intermediate_t,
	typename output_t,
	intermediate_t kp,
	intermediate_t ki,
	intermediate_t kd,
	intermediate_t integral_limit,
	intermediate_t factor>
output_t templated<
	input_t,
	intermediate_t,
	output_t,
		kp,
	ki,
	kd,
	integral_limit,
	factor>
::operator()(input_t error)
{
	using namespace FOSL::utility::math;

	error_sum = safe_add(error_sum, error);
	error_sum = clamp<intermediate_t, -integral_limit, integral_limit>(error_sum);

	intermediate_t error_change = error - last_error;
	last_error = error;

	output_t control = safe_cast<output_t>(
		(kp * error +
		 ki * error_sum +
		 kd * error_change) / factor);

	return control;
}
