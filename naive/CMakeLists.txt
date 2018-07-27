cmake_minimun_required(VERSION 2.8)

PROJECT("Cascos convexos")
set(CMAKE_CXX_STANDARD 17)

find_package(CGAL REQUIRED)
include(${CGAL_USE_FILE})

add_executable(convexhull main.cxx)

target_link_libraries(convexhull ${CGAL_LIBRARIES})
