set (TARGET_NAME asio_ex)

file(GLOB_RECURSE SOURCE_HEADER *.h)
file(GLOB_RECURSE SOURCE_SRC *.cpp)
file(GLOB_RECURSE SOURCE_HPP *.hpp )
file(GLOB_RECURSE SOURCE_SRC_C *.c )

set(SOURCE_ALL_FILES ${SOURCE_HEADER} ${SOURCE_SRC} ${SOURCE_HPP} ${SOURCE_SRC_C} )
source_group_by_dir(SOURCE_ALL_FILES)

if(MSVC)
    add_compile_options(/experimental:c11atomics)
endif()

include_directories (${CMAKE_SOURCE_DIR}/include)
include_directories (${CMAKE_SOURCE_DIR}/include/boost)

add_executable(${TARGET_NAME} ${SOURCE_ALL_FILES})