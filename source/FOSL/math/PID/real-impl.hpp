// CONSTRUCTORS
template <typename real_t>
real<real_t>::real(real_t kp, real_t ki, real_t kd, real_t limit)
{
	initialize(kp, ki, kd, limit);
}

// METHODS
template <typename real_t>
void real<real_t>::initialize(real_t kp, real_t ki, real_t kd, real_t limit)
{
	reset();

	this->kp = kp;
	this->ki = ki;
	this->kd = kd;
	this->limit = limit;
}
template <typename real_t>
void real<real_t>::reset(void)
{
	error_sum  = 0;
	last_error = 0;
}

// OPERATORS
template <typename real_t>
real_t real<real_t>::operator()(real_t error)
{
	using namespace FOSL::utility::math;

	error_sum += error;
	error_sum = clamp(-limit, limit, error_sum);

	real_t error_change = error - last_error;
	last_error = error;

	real_t control =
		kp * error +
		ki * error_sum +
		kd * error_change;

	return control;
}
