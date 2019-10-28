project(armadillo-exercise)
cmake_minimum_required(VERSION 3.0.0)

find_package(Armadillo REQUIRED)

include_directories(include ${ARMADILLO_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}-demo-01 src/demo-01.cpp)
add_executable(${PROJECT_NAME}-demo-02 src/demo-02.cpp)
add_executable(${PROJECT_NAME}-demo-03 src/demo-03.cpp)

target_link_libraries(${PROJECT_NAME}-demo-01 ${ARMADILLO_LIBRARIES})
target_link_libraries(${PROJECT_NAME}-demo-02 ${ARMADILLO_LIBRARIES})
target_link_libraries(${PROJECT_NAME}-demo-03 ${ARMADILLO_LIBRARIES})
