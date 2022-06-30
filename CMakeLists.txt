cmake_minimum_required (VERSION 3.15)

project ("shtrausCs")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDAED_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(MSVC)
	add_compile_options(/W4 /WX /permissive- /Zc:externConstexpr /Zc:inline)
endif()

add_executable ("shtrausCs")
add_subdirectory(include)
add_subdirectory(src)