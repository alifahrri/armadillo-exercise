cmake_minimum_required (VERSION 3.0)
project (eigen-demo)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable (demo-autodiff src/demo-autodiff.cpp)
target_link_libraries (demo-autodiff Eigen3::Eigen)

add_executable (demo-autodiff-jacobian src/demo-autodiff-jacobian.cpp)
target_link_libraries (demo-autodiff-jacobian Eigen3::Eigen)

target_compile_options(demo-autodiff-jacobian PUBLIC -std=c++17)