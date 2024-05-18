cmake_minimum_required(VERSION 3.26)
project(sensor)

set(CMAKE_CXX_STANDARD 23)

file (GLOB_RECURSE sensor_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE sensor_HEADERS CONFIGURE_DEPENDS "src/*.hpp")

set (sensor_INCLUDE_DIRS "")
foreach (_headerFile ${sensor_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND sensor_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES sensor_INCLUDE_DIRS)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(sensor ${sensor_SOURCES})

target_compile_features(sensor PRIVATE cxx_std_23)
target_link_libraries(sensor PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network Xrandr)
target_include_directories(sensor PRIVATE ${sensor_INCLUDE_DIRS})

install(TARGETS sensor)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)