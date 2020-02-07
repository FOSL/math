project(FOSL-math)

set(PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/source")
set(PROJECT_BINARY_DIR "${PROJECT_BINARY_DIR}/source")

add_library(
	${PROJECT_NAME}

	${PROJECT_SOURCE_DIR}/FOSL/math/PID.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/PID/real.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/PID/real-impl.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/PID/templated.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/PID/templated-impl.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/vector2.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/vector2-impl.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/vector3.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/vector3-impl.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/vector/fixed_size.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/vector/fixed_size-impl.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math/vector.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math.hpp
	${PROJECT_SOURCE_DIR}/FOSL/math.cpp
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}
)

target_link_libraries(
	${PROJECT_NAME}

	FOSL-utility
)
