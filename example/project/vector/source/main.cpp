#include <FOSL/math/vector2.hpp>

int main(void)
{
	using namespace FOSL;
	using namespace FOSL::math;

	vector2<float> v2 = { 1.0, 2.0 };
	v2.x = 3.0;
	v2[0] += 0.5;
	v2 = -v2;
	v2 *= v2[1];
}
